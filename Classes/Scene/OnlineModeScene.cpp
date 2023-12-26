#include "OnlineModeScene.h"

cocos2d::Scene* OnlineModeScene::createScene()
{
	auto scene = Scene::create();//创建一个场景
	auto firstLayer = OnlineModeScene::create();//创建一个图层
	scene->addChild(firstLayer);//把firstLayer图层加入到scene场景中
	return scene;
}

bool OnlineModeScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	ID = 0;
	initNetwork();//网络初始化
	return true;
}

void OnlineModeScene::onEnter()
{
	Layer::onEnter();
}

void OnlineModeScene::onExit()
{
	client->destroy();
	client = nullptr;
	Director::getInstance()->getEventDispatcher()->removeEventListener(_touchListener);
	Layer::onExit();
}

//回调函数，接受服务器传输的信息
void OnlineModeScene::onRecv(const char* data, int count)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();//获得屏幕大小
	switch (count)//对服务器信息类型进行分类
	{
		case 2://若传递的信息为当前玩家ID或总玩家数量
			if (data[0] == 'i')//传递信息为当前玩家ID
			{
				//打印当前玩家ID信息
				ID = data[1];
				std::string outputID = "Your ID: ";
				outputID += data[1];
				auto labelOutputID = Label::createWithSystemFont(outputID, "Arial.TTF", 120);
				labelOutputID->setPosition(visibleSize.width / 2, visibleSize.height / 2);
				this->addChild(labelOutputID);
				//打印玩家进入房间时的玩家总人数，玩家第几个进入房间，玩家的ID就为几
				std::string outputPlayerNum = "Now Player Num: ";
				outputPlayerNum += data[1];
				auto labelOutputPlayerNum = Label::createWithSystemFont(outputPlayerNum, "Arial.TTF", 120);
				labelOutputPlayerNum->setPosition(visibleSize.width / 2, visibleSize.height * 2 / 3);
				labelOutputPlayerNum->setTag(100);//100作为该标签的标记
				this->addChild(labelOutputPlayerNum);
			}
			else if (data[0] == 'a')//传递信息为总玩家数量
			{
				this->removeChildByTag(100);//先移除之前打印的玩家总人数
				//打印当前玩家总人数
				std::string outputPlayerNum = "Now Player Num: ";
				outputPlayerNum += data[1];
				auto labelOutputPlayerNum = Label::createWithSystemFont(outputPlayerNum, "Arial.TTF", 120);
				labelOutputPlayerNum->setPosition(visibleSize.width / 2, visibleSize.height * 2 / 3);
				labelOutputPlayerNum->setTag(100);//100作为该标签的标记
				this->addChild(labelOutputPlayerNum);
			}
			break;
	}
}

void OnlineModeScene::onDisconnect()
{
}


//网络初始化
void OnlineModeScene::initNetwork()
{
	client = SocketClient::construct();
    client->onRecv = CC_CALLBACK_2(OnlineModeScene::onRecv, this);
	client->onDisconnect = CC_CALLBACK_0(OnlineModeScene::onDisconnect, this);
	if (!client->connectServer("127.0.0.1", 8000))
	{
		Size visible_size = Director::getInstance()->getVisibleSize();//获得屏幕大小
		auto game_name_label = Label::createWithSystemFont("fail connect", "fonts.ttf", 100);
		game_name_label->setPosition(visible_size.width / 2, visible_size.height * 2);//将未能成功连接标签放置屏幕中间偏上
		this->addChild(game_name_label);
	}
}


