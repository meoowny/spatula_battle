#include "ServerModeScene.h"

cocos2d::Scene* ServerModeScene::createScene()
{
	auto scene = Scene::create();//创建一个场景
	auto firstLayer = ServerModeScene::create();//创建一个图层
	scene->addChild(firstLayer);//把firstLayer图层加入到scene场景中
	return scene;
}

bool ServerModeScene::init()
{
	if (!Layer::init())//先初始化父类的init，若初始化失败，返回false
	{
		return false;
	}
	initNetwork();

	Size visibleSize = Director::getInstance()->getVisibleSize();//获得屏幕大小

	//设置开始游戏标签
	auto labelStartGame = Label::createWithSystemFont("开始了", "STHUPO.TTF", 120);
	auto itemStartGame = MenuItemLabel::create(labelStartGame, CC_CALLBACK_1(ServerModeScene::startGameCallBack, this));
	
	//设置分配玩家信息
	auto labelGivePlayerInfo = Label::createWithSystemFont("分配玩家信息", "STHUPO.TTF", 120);
	auto itemGivePlayerInfo = MenuItemLabel::create(labelGivePlayerInfo, CC_CALLBACK_1(ServerModeScene::givePlayerInfoCallBack, this));

	//将标签添加到菜单里
	auto menu = Menu::create(itemStartGame, itemGivePlayerInfo, NULL);
	menu->alignItemsVerticallyWithPadding(30);//设置菜单条目间的宽度
	menu->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(menu);
	return true;
}

void ServerModeScene::onEnter()
{
	Layer::onEnter();
}

void ServerModeScene::onExit()
{
	server->destroyInstance();
	Director::getInstance()->getEventDispatcher()->removeEventListener(_touchListener);
	Layer::onExit();
}

//通知玩家游戏开始
void ServerModeScene::startGameCallBack(Ref* pSender)
{
	
}

//分配玩家信息
void ServerModeScene::givePlayerInfoCallBack(Ref* pSender)
{
	std::list<HSocket>::iterator iterClient;//迭代器，辅助遍历当前所有客户端
	std::string tempPlayerFileName = "Peashooter_0.png";

	server->_mutex.lock();
	//遍历当前所有客户端，为其分发玩家信息
	for (iterClient = server->_clientSockets.begin(); iterClient != server->_clientSockets.end(); iterClient++)
	{
		PlayerInfo tempPlayerInfo(tempPlayerFileName, false);
		server->sendMessage(*iterClient, (char*)(&tempPlayerInfo), sizeof(PlayerInfo));
	}
	server->_mutex.unlock();
}

//网络初始化
void ServerModeScene::initNetwork()
{
	server = SocketServer::getInstance();
	server->startServer(8000);
}
