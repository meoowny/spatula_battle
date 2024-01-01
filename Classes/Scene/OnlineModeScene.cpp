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
	//client->sendMessage("111", 4);
}



void OnlineModeScene::onEnter()
{
	if (roundNum != 0)
	{
		roundNum++;

		//备战回合结束，将己方信息传给服务器
		//服务器接收到信息后会把敌方信息传给己方
		//己方对EnemyInfo进行改动
		AfterParationInfo nowParationInfo = { 0 };
		nowParationInfo.theId = ID;
		strcpy(nowParationInfo.fileName, myPlayerInfo->_image_path.c_str());
		nowParationInfo.isAI = myPlayerInfo->_isAI;
		nowParationInfo.coins = myPlayerInfo->_coins;
		nowParationInfo.experience = myPlayerInfo->_experience;
		nowParationInfo.health = myPlayerInfo->_health;

		enum legendType
		{
			aphelios = 1, caitlyn = 2, ezreal = 3, lucian = 4, miss_fortune = 5,
			graves = 6, varus = 7, katarina = 8, akali = 9, annie = 10,
			viktor = 11, sona = 12, jhin = 13, viego = 14, qiyana = 15,
			kayn = 16, bel_veth = 17, ekko = 18, riven = 19, fiora = 20,
			camille = 21, irelia = 22, sett = 23, ganplank = 24, thresh = 25,
			renata_glasc = 26, rakan = 27, bard = 28, nautilus = 29, pyke = 30
		};
		
		//对preparadLegends的信息进行转换
		for (int i = 0; i < 9; i++)
		{
			if (myPlayerInfo->_preparedLegends[i] != NULL)
			{
				if (myPlayerInfo->_preparedLegends[i]->_name == "Aphelios")
				{
					nowParationInfo.preparadLegends[i] = aphelios;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Caitlyn")
				{
					nowParationInfo.preparadLegends[i] = caitlyn;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Ezreal")
				{
					nowParationInfo.preparadLegends[i] = ezreal;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Lucian")
				{
					nowParationInfo.preparadLegends[i] = lucian;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Miss_Fortune")
				{
					nowParationInfo.preparadLegends[i] = miss_fortune;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Graves")
				{
					nowParationInfo.preparadLegends[i] = graves;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Varus")
				{
					nowParationInfo.preparadLegends[i] = varus;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Katarina")
				{
					nowParationInfo.preparadLegends[i] = katarina;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Akali")
				{
					nowParationInfo.preparadLegends[i] = akali;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Annie")
				{
					nowParationInfo.preparadLegends[i] = annie;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Viktor")
				{
					nowParationInfo.preparadLegends[i] = viktor;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Sona")
				{
					nowParationInfo.preparadLegends[i] = sona;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Jhin")
				{
					nowParationInfo.preparadLegends[i] = jhin;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Viego")
				{
					nowParationInfo.preparadLegends[i] = viego;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Qiyana")
				{
					nowParationInfo.preparadLegends[i] = qiyana;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Kayn")
				{
					nowParationInfo.preparadLegends[i] = kayn;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Bel_Veth")
				{
					nowParationInfo.preparadLegends[i] = bel_veth;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Ekko")
				{
					nowParationInfo.preparadLegends[i] = ekko;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Riven")
				{
					nowParationInfo.preparadLegends[i] = riven;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Fiora")
				{
					nowParationInfo.preparadLegends[i] = fiora;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Camille")
				{
					nowParationInfo.preparadLegends[i] = camille;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Irelia")
				{
					nowParationInfo.preparadLegends[i] = irelia;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Sett")
				{
					nowParationInfo.preparadLegends[i] = sett;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Ganplank")
				{
					nowParationInfo.preparadLegends[i] = ganplank;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Thresh")
				{
					nowParationInfo.preparadLegends[i] = thresh;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Renata_Glasc")
				{
					nowParationInfo.preparadLegends[i] = renata_glasc;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Rakan")
				{
					nowParationInfo.preparadLegends[i] = rakan;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Bard")
				{
					nowParationInfo.preparadLegends[i] = bard;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Nautilus")
				{
					nowParationInfo.preparadLegends[i] = nautilus;
				}
				else if (myPlayerInfo->_preparedLegends[i]->_name == "Pyke")
				{
					nowParationInfo.preparadLegends[i] = pyke;
				}
			}
		}
		
		client->sendMessage((char*)(&nowParationInfo), sizeof(AfterParationInfo));
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
		if (tempAfterParationInfo.theId != ID)
		{
			changePlayerInfo(tempAfterParationInfo);
			Director::getInstance()->pushScene(BattleScene::createScene(myPlayerInfo, enemyPlayerInfo));
		}
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

	enum legendType
	{
		aphelios = 1, caitlyn = 2, ezreal = 3, lucian = 4, miss_fortune = 5,
		graves = 6, varus = 7, katarina = 8, akali = 9, annie = 10,
		viktor = 11, sona = 12, jhin = 13, viego = 14, qiyana = 15,
		kayn = 16, bel_veth = 17, ekko = 18, riven = 19, fiora = 20,
		camille = 21, irelia = 22, sett = 23, ganplank = 24, thresh = 25,
		renata_glasc = 26, rakan = 27, bard = 28, nautilus = 29, pyke = 30
	};

	for (int i = 0; i < 9; i++)
	{
		if (tempAfterParationInfo.preparadLegends[i] == aphelios)
		{
			//生成aphelios放到preparedlegend数组里
			LegendInfo* info = Aphelios::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == caitlyn)
		{
			LegendInfo* info = Caitlyn::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == ezreal)
		{
			LegendInfo* info = Ezreal::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == lucian)
		{
			LegendInfo* info = Lucian::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == miss_fortune)
		{
			LegendInfo* info = Miss_Fortune::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == graves)
		{
			LegendInfo* info = Graves::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == varus)
		{
			LegendInfo* info = Varus::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == katarina)
		{
			LegendInfo* info = Katarina::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == akali)
		{
			LegendInfo* info = Akali::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == annie)
		{
			LegendInfo* info = Annie::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == viktor)
		{
			LegendInfo* info = Viktor::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == sona)
		{
			LegendInfo* info = Sona::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == jhin)
		{
			LegendInfo* info = Jhin::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == viego)
		{
			LegendInfo* info = Viego::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == qiyana)
		{
			LegendInfo* info = Qiyana::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == kayn)
		{
			LegendInfo* info = Kayn::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == bel_veth)
		{
			LegendInfo* info = Bel_Veth::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == ekko)
		{
			LegendInfo* info = Ekko::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == riven)
		{
			LegendInfo* info = Riven::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == fiora)
		{
			LegendInfo* info = Fiora::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == camille)
		{
			LegendInfo* info = Camille::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == irelia)
		{
			LegendInfo* info = Irelia::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == sett)
		{
			LegendInfo* info = Sett::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == ganplank)
		{
			LegendInfo* info = Ganplank::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == thresh)
		{
			LegendInfo* info = Thresh::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == renata_glasc)
		{
			LegendInfo* info = Renata_Glasc::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == rakan)
		{
			LegendInfo* info = Rakan::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == bard)
		{
			LegendInfo* info = Bard::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == nautilus)
		{
			LegendInfo* info = Nautilus::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
		else if (tempAfterParationInfo.preparadLegends[i] == pyke)
		{
			LegendInfo* info = Pyke::createInfo();
			enemyPlayerInfo->_preparedLegends[i] = info;
		}
	}
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


