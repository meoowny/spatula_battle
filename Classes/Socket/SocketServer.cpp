#include "SocketServer.h"

SocketServer* SocketServer::s_server = nullptr;

SocketServer* SocketServer::getInstance()
{
	if (s_server == nullptr)
	{
		s_server = new SocketServer;
	}

	return s_server;
}

void SocketServer::destroyInstance()
{
	CC_SAFE_DELETE(s_server);
}

SocketServer::SocketServer() :
	_socketServer(0),
	onRecv(nullptr),
	onStart(nullptr),
	onNewConnection(nullptr)
{
	Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
}


SocketServer::~SocketServer()
{
	this->clear();
};

void SocketServer::clear()
{
	if (_socketServer)
	{
		_mutex.lock();
		this->closeConnect(_socketServer);
		_mutex.unlock();
	}

	for (auto msg : _UIMessageQueue)
	{
		CC_SAFE_DELETE(msg);
	}
	_UIMessageQueue.clear();

	Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
}

bool SocketServer::startServer(unsigned short port)
{
	if (!initServer(port))
	{
		return false;
	}

	return true;
}

bool SocketServer::initServer(unsigned short port)
{
	if (_socketServer != 0)
	{
		this->closeConnect(_socketServer);
	}
	_socketServer = socket(AF_INET, SOCK_STREAM, 0);
	if (error(_socketServer))
	{
		log("socket error!");
		_socketServer = 0;
		return false;
	}

	do
	{
		struct sockaddr_in sockAddr;
		memset(&sockAddr, 0, sizeof(sockAddr));
		_serverPort = port;		// save the port

		sockAddr.sin_family = AF_INET;
		sockAddr.sin_port = htons(_serverPort);
		sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
		int ret = 0;
		ret = bind(_socketServer, (const sockaddr*)&sockAddr, sizeof(sockAddr));
		if (ret < 0)
		{
			log("bind error!");
			break;
		}

		ret = listen(_socketServer, 5);
		if (ret < 0)
		{
			log("listen error!");
			break;
		}
		// start 
		char hostName[256];
		gethostname(hostName, sizeof(hostName));
		struct hostent* hostInfo = gethostbyname(hostName);
		char* ip = inet_ntoa(*(struct in_addr*)*hostInfo->h_addr_list);
		this->acceptClient();

		if (onStart != nullptr)
		{
			log("start server!");
			this->onStart(ip);
		}

		return true;

	} while (false);

	this->closeConnect(_socketServer);
	_socketServer = 0;
	return false;
}

void SocketServer::acceptClient()
{
	std::thread th(&SocketServer::acceptFunc, this);
	th.detach();
}

void SocketServer::acceptFunc()
{
	int len = sizeof(sockaddr);
	struct sockaddr_in sockAddr;
	while (true)
	{
		HSocket clientSock = accept(_socketServer, (sockaddr*)&sockAddr, &len);
		if (error(clientSock))
		{
			log("accept error!");
		}
		else
		{
			this->newClientConnected(clientSock);
		}
	}
}


void SocketServer::newClientConnected(HSocket socket)
{
	log("new connect!");

	_clientSockets.push_back(socket);
	std::thread th(&SocketServer::recvMessage, this, socket);
	th.detach();
	if (onNewConnection)
	{
		std::lock_guard<std::mutex> lk(_UIMessageQueueMutex);
		SocketMessage* msg = new SocketMessage(NEW_CONNECTION, (unsigned char*)&socket, sizeof(HSocket));
		_UIMessageQueue.push_back(msg);
	}

	////��ͻ��˷��������ӵ���Ϣ���û����յ���Ϣ�󣬽�ID���ط�����
	////���ͻ��˷��ص�IDΪĬ��ֵ'0'���������Ϊ�����ID
	////���ͻ��˷��ص�ID��Ϊ'0'�������������ID��Ӧ��socket��Ϊ��ǰ��socket
	//_mutex.lock();
	//char ID[2] = { 0 };
	//ID[0] = 'b';//��Ϊ��ʶ�����������ִ��ݵ���Ϣ��id�����������ǳ�������ʱ�����ӵ���Ϣ
	//ID[1] = 48;
	//this->sendMessage(socket, ID, 2);
	//_mutex.unlock();

	_mutex.lock();
	//����ǰ�û�����Ŵ�����ǰ�û��ˣ������������û��˵�id
	char ID[2] = { 0 };
	ID[0] = 'i';//��Ϊ��ʶ�����������ִ��ݵ���Ϣ��id����������
	ID[1] = 48 + _clientSockets.size();
	this->sendMessage(socket, ID, 2);
	//ʹ��map��ÿ����ҵ�id����socket���Ӧ
	idToSocket.insert(std::map<char, HSocket>::value_type(ID[1], socket));
	socketToId.insert(std::map<HSocket, char>::value_type(socket, ID[1]));
	//����ǰ�������������ÿ�����
	char playerNum[2] = { 0 };
	playerNum[0] = 'a';
	playerNum[1] = 48 + _clientSockets.size();
	this->sendMessage(playerNum, 2);
	_mutex.unlock();
	

	/*_mutex.lock();
	this->sendMessage("start", 6);
	_mutex.unlock();*/

}

void SocketServer::recvMessage(HSocket socket)
{
	char buff[1024];
	int ret = 0;

	while (true)
	{
		ret = recv(socket, buff, sizeof(buff), 0);
		if (ret < 0)
		{
			log("recv(%d) error!", socket);
			break;
		}
		else
		{
			if (ret > 0 && onRecv != nullptr)
			{
				std::lock_guard<std::mutex> lk(_UIMessageQueueMutex);
				RecvData recvData;
				recvData.socketClient = socket;
				memcpy(recvData.data, buff, ret);
				recvData.dataLen = ret;
				SocketMessage* msg = new SocketMessage(RECEIVE, (unsigned char*)&recvData, sizeof(RecvData));
				_UIMessageQueue.push_back(msg);
			}
		}
	}

	/*_mutex.lock();
	this->sendMessage("start", 6);
	_mutex.unlock();*/

	_mutex.lock();
	this->closeConnect(socket);
	if (onDisconnect != nullptr)
	{
		std::lock_guard<std::mutex> lk(_UIMessageQueueMutex);
		SocketMessage* msg = new SocketMessage(DISCONNECT, (unsigned char*)&socket, sizeof(HSocket));
		_UIMessageQueue.push_back(msg);
	}
	_mutex.unlock();
}


void SocketServer::sendMessage(HSocket socket, const char* data, int count)
{
	for (auto& sock : _clientSockets)
	{
		if (sock == socket)
		{
			int ret = send(socket, data, count, 0);
			if (ret < 0)
			{
				log("send error!");
			}
			break;
		}
	}
}

void SocketServer::sendMessage(const char* data, int count)
{
	for (auto& socket : _clientSockets)
	{
		int ret = send(socket, data, count, 0);
		if (ret < 0)
		{
			log("send error!");
		}
	}
}

void SocketServer::update(float dt)
{
	if (_UIMessageQueue.size() == 0)
	{
		return;
	}

	_UIMessageQueueMutex.lock();

	if (_UIMessageQueue.size() == 0)
	{
		_UIMessageQueueMutex.unlock();
		return;
	}

	SocketMessage* msg = *(_UIMessageQueue.begin());
	_UIMessageQueue.pop_front();

	switch (msg->getMsgType())
	{
		case NEW_CONNECTION:
			if (onNewConnection)
			{
				this->onNewConnection(*(HSocket*)msg->getMsgData()->getBytes());
			}
			break;
		case DISCONNECT:
			if (onDisconnect)
			{
				this->onDisconnect(*(HSocket*)msg->getMsgData()->getBytes());
			}
			break;
		case RECEIVE:
			if (onRecv)
			{
				RecvData* recvData = (RecvData*)msg->getMsgData()->getBytes();
				this->onRecv(recvData->socketClient, (const char*)recvData->data, recvData->dataLen);
			}
			break;
		default:
			break;
	}

	CC_SAFE_DELETE(msg);
	_UIMessageQueueMutex.unlock();
}



//if (ret == sizeof(AfterParationInfo))//���յ���Ӣ����Ϣ
//{
//	AfterParationInfo tempInfo;
//	memcpy(&tempInfo, buff, sizeof(AfterParationInfo));
//	socketToInfo.insert(std::map<HSocket, AfterParationInfo>::value_type(socket, tempInfo));
//}
//_mutex.lock();
//if (ret == 7)
//{
//	sendMessage("start", 6);
//}
//sendMessage(socket, "start", 6);
//_mutex.unlock();

