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
	ID = 48;
	myPlayerInfo = NULL;
	enemyPlayerInfo = NULL;
	roundNum = 0;
	initNetwork();//网络初始化

	Size visibleSize = Director::getInstance()->getVisibleSize();//获得屏幕大小

	auto background = Sprite::create("OnlineModeSceneBackground.jpg");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(2.0);
	this->addChild(background);

	auto labelGivePlayerInfo = Label::createWithSystemFont("等待房间", "STHUPO.TTF", 120);
	labelGivePlayerInfo->setColor(Color3B::YELLOW);
	auto itemGivePlayerInfo = MenuItemLabel::create(labelGivePlayerInfo, CC_CALLBACK_1(OnlineModeScene::givePlayerInfoCallBack, this));
	auto menu = Menu::create( itemGivePlayerInfo, NULL);
	menu->setPosition(visibleSize.width / 2, visibleSize.height * 4 / 5);
	this->addChild(menu);

	return true;
}

void OnlineModeScene::givePlayerInfoCallBack(Ref* pSender)
{
	client->sendMessage("abcd", 5);
}



void OnlineModeScene::onEnter()
{
	if (roundNum == 1)
	{
		//roundNum++;
		////备战回合结束，将己方信息传给服务器
		////服务器接收到信息后会把敌方信息传给己方
		////己方对EnemyInfo进行改动
		/*AfterParationInfo nowParationInfo = { 0 };
		strcpy(nowParationInfo.fileName, myPlayerInfo->_image_path.c_str());
		nowParationInfo.isAI = myPlayerInfo->_isAI;
		nowParationInfo.coins = myPlayerInfo->_coins;
		nowParationInfo.experience = myPlayerInfo->_experience;
		nowParationInfo.health = myPlayerInfo->_health;
		client->sendMessage((char*)(&nowParationInfo), sizeof(AfterParationInfo));*/
		//Director::getInstance()->pushScene(BattleScene::createScene(myPlayerInfo, enemyPlayerInfo));
	}
	Layer::onEnter();
}

void OnlineModeScene::onExit()
{
	/*client->destroy();
	client = nullptr;
	Director::getInstance()->getEventDispatcher()->removeEventListener(_touchListener);*/
	Layer::onExit();
}

//回调函数，接受服务器传输的信息
void OnlineModeScene::onRecv(const char* data, int count)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();//获得屏幕大小

	if (count == 2)//若传递的信息为当前玩家ID或总玩家数量
	{
		if (data[0] == 'i')//传递信息为当前玩家ID
		{
			//打印当前玩家ID信息
			ID = data[1];
			std::string outputID = "你的ID: ";
			outputID += data[1];
			auto labelOutputID = Label::createWithSystemFont(outputID, "STHUPO.TTF", 120);
			labelOutputID->setPosition(visibleSize.width / 2, visibleSize.height / 2);
			this->addChild(labelOutputID);
			//打印玩家进入房间时的玩家总人数，玩家第几个进入房间，玩家的ID就为几
			std::string outputPlayerNum = "当前房间人数 : ";
			outputPlayerNum += data[1];
			auto labelOutputPlayerNum = Label::createWithSystemFont(outputPlayerNum, "STHUPO.TTF", 120);
			labelOutputPlayerNum->setPosition(visibleSize.width / 2, visibleSize.height * 2 / 3);
			labelOutputPlayerNum->setTag(100);//100作为该标签的标记
			this->addChild(labelOutputPlayerNum);
		}
		else if (data[0] == 'a')//传递信息为总玩家数量
		{
			this->removeChildByTag(100);//先移除之前打印的玩家总人数
			//打印当前玩家总人数
			std::string outputPlayerNum = "当前房间人数 : ";
			outputPlayerNum += data[1];
			auto labelOutputPlayerNum = Label::createWithSystemFont(outputPlayerNum, "STHUPO.TTF", 120);
			labelOutputPlayerNum->setPosition(visibleSize.width / 2, visibleSize.height * 2 / 3);
			labelOutputPlayerNum->setTag(100);//100作为该标签的标记
			this->addChild(labelOutputPlayerNum);
		}
	}
	else if (count == sizeof(StartPlayerInfo))
	{
		//初始化己方玩家信息
		StartPlayerInfo tempPlayerInfo;
		memcpy(&tempPlayerInfo, data, sizeof(StartPlayerInfo));
		myPlayerInfo = new PlayerInfo(tempPlayerInfo.fileName, tempPlayerInfo.isAI);

		//初始化敌方英雄信息
		//需要改动，当备战阶段结束后收到对方的信息，将enemyPlayerInfo中的信息进行改动
		enemyPlayerInfo = new PlayerInfo(tempPlayerInfo.fileName, tempPlayerInfo.isAI);
	}
	else if (count == 6)
	{
		roundNum++;
		Director::getInstance()->pushScene(PreparationScene::createScene(myPlayerInfo));
	}
	else if (count == sizeof(AfterParationInfo))
	{
		AfterParationInfo tempAfterParationInfo;
		memcpy(&tempAfterParationInfo, data, sizeof(AfterParationInfo));
		changePlayerInfo(tempAfterParationInfo);
		Director::getInstance()->pushScene(BattleScene::createScene(myPlayerInfo, enemyPlayerInfo));
	}
}

//对enemyplayerinfo内信息进行改动
int OnlineModeScene::changePlayerInfo(AfterParationInfo& tempAfterParationInfo)
{
	enemyPlayerInfo->_image_path = tempAfterParationInfo.fileName;
	enemyPlayerInfo->_isAI = tempAfterParationInfo.isAI;
	enemyPlayerInfo->_coins = tempAfterParationInfo.coins;
	enemyPlayerInfo->_experience = tempAfterParationInfo.experience;
	enemyPlayerInfo->_health = tempAfterParationInfo.health;
	return 0;
}

void OnlineModeScene::onDisconnect()
{
}


//网络初始化
void OnlineModeScene::initNetwork()
{
	client =  SocketClient::construct();
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


