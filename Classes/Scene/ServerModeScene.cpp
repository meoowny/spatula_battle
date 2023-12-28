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

	//添加背景图片
	auto background = Sprite::create("ServerModeBackground.jpg");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(3.0);
	this->addChild(background);

	
	//添加“由你来掌控游戏”标签
	auto labelGameName = Label::createWithSystemFont("你来掌控游戏", "STHUPO.TTF", 200);
	labelGameName->setPosition(visibleSize.width / 2, visibleSize.height * 3 / 4);//将游戏名标签放置屏幕中间偏上
	labelGameName->setColor(Color3B::YELLOW);
	labelGameName->enableShadow(Color4B::BLACK, Size(8, -8));
	this->addChild(labelGameName);

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
	server->_mutex.lock();
	//为当前所有客户端分发游戏开始信息
	server->sendMessage("start", 6);
	server->_mutex.unlock();
}

//分配玩家信息
void ServerModeScene::givePlayerInfoCallBack(Ref* pSender)
{
	std::list<HSocket>::iterator iterClient;//迭代器，辅助遍历当前所有客户端
	int serverNum = 0;
	server->_mutex.lock();
	//遍历当前所有客户端，为其分发玩家信息
	for (iterClient = server->_clientSockets.begin(); iterClient != server->_clientSockets.end(); iterClient++)
	{
		serverNum++;
		//每个玩家分配不一样的小小英雄
		if (serverNum % 2 == 1)
		{
			StartPlayerInfo tempStartPlayerInfo = { "Peashooter_0.png" ,false };
			server->sendMessage(*iterClient, (char*)(&tempStartPlayerInfo), sizeof(StartPlayerInfo));
		}
		else
		{
			StartPlayerInfo tempStartPlayerInfo = { "HelloWorld.png" ,false };
			server->sendMessage(*iterClient, (char*)(&tempStartPlayerInfo), sizeof(StartPlayerInfo));
		}
	}
	server->_mutex.unlock();
}

//网络初始化
void ServerModeScene::initNetwork()
{
	server = SocketServer::getInstance();
	server->startServer(8000);
}
