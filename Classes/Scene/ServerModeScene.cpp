#include "ServerModeScene.h"

cocos2d::Scene* ServerModeScene::createScene()
{
	auto scene = Scene::create();//����һ������
	auto firstLayer = ServerModeScene::create();//����һ��ͼ��
	scene->addChild(firstLayer);//��firstLayerͼ����뵽scene������
	return scene;
}

bool ServerModeScene::init()
{
	if (!Layer::init())//�ȳ�ʼ�������init������ʼ��ʧ�ܣ�����false
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

//�����ʼ��
void ServerModeScene::initNetwork()
{
	server = SocketServer::getInstance();
	server->startServer(8000);
}
