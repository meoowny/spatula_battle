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

//网络初始化
void ServerModeScene::initNetwork()
{
	server = SocketServer::getInstance();
	server->startServer(8000);
}
