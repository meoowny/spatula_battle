#pragma once
#ifndef __SOCKET_SERVER_H__
#define __SOCKET_SERVER_H__

#include "SocketBase.h"
#include "Scene/ServerModeScene.h"
//#include "Player/Player.h"
#include <map>

struct RecvData
{
	HSocket socketClient;
	int dataLen;
	char data[1024];
};





class SocketServer : public SocketBase
{
	friend class ServerModeScene;//将ServerModeScene设置为友元，便于获取客户端信息
public:
	static SocketServer* getInstance();
	void destroyInstance();

	bool startServer(unsigned short port);
	void sendMessage(HSocket socket, const char* data, int count);
	void sendMessage(const char* data, int count);
	void update(float dt);


	std::function<void(const char* ip)> onStart;
	std::function<void(HSocket socket)> onNewConnection;
	std::function<void(HSocket socket, const char* data, int count)> onRecv;
	std::function<void(HSocket socket)> onDisconnect;

CC_CONSTRUCTOR_ACCESS:
	SocketServer();
	~SocketServer();

private:
	void clear();
	bool initServer(unsigned short port);
	void acceptClient();
	void acceptFunc();
	void newClientConnected(HSocket socket);
	void recvMessage(HSocket socket);

private:
	static SocketServer* s_server;
	HSocket _socketServer;
	unsigned short _serverPort;

private:
	std::list<HSocket> _clientSockets;
	std::list<SocketMessage*> _UIMessageQueue;
	std::mutex   _UIMessageQueueMutex;
	std::map<char, HSocket> idToSocket;//用来将用户端与其ID一一对应，根据ID找到用户端
	std::map<HSocket, char> socketToId;//用来将用户端与其ID一一对应，根据用户端找ID
	int num;
	//std::map<HSocket, AfterParationInfo> socketToInfo;//将用户端与其备战后的信息相对应
};

#endif
