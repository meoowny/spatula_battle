#include "OnlineModeScene.h"

cocos2d::Scene* OnlineModeScene::createScene()
{
	auto scene = Scene::create();//����һ������
	auto firstLayer = OnlineModeScene::create();//����һ��ͼ��
	scene->addChild(firstLayer);//��firstLayerͼ����뵽scene������
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
	initNetwork();//�����ʼ��
	return true;
}

void OnlineModeScene::onEnter()
{
	if (roundNum==1)
	{
		roundNum++;

		////��ս�غϽ�������������Ϣ����������
		////���������յ���Ϣ���ѵз���Ϣ��������
		////������EnemyInfo���иĶ�
		//char fileName[30] = { 0 };
		//strcpy(fileName, myPlayerInfo->_image_path.c_str());

		Director::getInstance()->pushScene(BattleScene::createScene(myPlayerInfo, enemyPlayerInfo));
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

//�ص����������ܷ������������Ϣ
void OnlineModeScene::onRecv(const char* data, int count)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();//�����Ļ��С
	switch (count)//�Է�������Ϣ���ͽ��з���
	{
		case 2://�����ݵ���ϢΪ��ǰ���ID�����������
			if (data[0] == 'i')//������ϢΪ��ǰ���ID
			{
				//��ӡ��ǰ���ID��Ϣ
				ID = data[1];
				std::string outputID = "Your ID: ";
				outputID += data[1];
				auto labelOutputID = Label::createWithSystemFont(outputID, "Arial.TTF", 120);
				labelOutputID->setPosition(visibleSize.width / 2, visibleSize.height / 2);
				this->addChild(labelOutputID);
				//��ӡ��ҽ��뷿��ʱ���������������ҵڼ������뷿�䣬��ҵ�ID��Ϊ��
				std::string outputPlayerNum = "Now Player Num: ";
				outputPlayerNum += data[1];
				auto labelOutputPlayerNum = Label::createWithSystemFont(outputPlayerNum, "Arial.TTF", 120);
				labelOutputPlayerNum->setPosition(visibleSize.width / 2, visibleSize.height * 2 / 3);
				labelOutputPlayerNum->setTag(100);//100��Ϊ�ñ�ǩ�ı��
				this->addChild(labelOutputPlayerNum);
			}
			else if (data[0] == 'a')//������ϢΪ���������
			{
				this->removeChildByTag(100);//���Ƴ�֮ǰ��ӡ�����������
				//��ӡ��ǰ���������
				std::string outputPlayerNum = "Now Player Num: ";
				outputPlayerNum += data[1];
				auto labelOutputPlayerNum = Label::createWithSystemFont(outputPlayerNum, "Arial.TTF", 120);
				labelOutputPlayerNum->setPosition(visibleSize.width / 2, visibleSize.height * 2 / 3);
				labelOutputPlayerNum->setTag(100);//100��Ϊ�ñ�ǩ�ı��
				this->addChild(labelOutputPlayerNum);
			}
			break;
		case sizeof(StartPlayerInfo) ://����Ϊ��ʼ�����Ϣ

			//��ʼ�����������Ϣ
			StartPlayerInfo tempPlayerInfo;
			memcpy(&tempPlayerInfo, data, sizeof(StartPlayerInfo));
			myPlayerInfo = new PlayerInfo(tempPlayerInfo.fileName, tempPlayerInfo.isAI);

			//��ʼ���з�Ӣ����Ϣ
			//��Ҫ�Ķ�������ս�׶ν������յ��Է�����Ϣ����enemyPlayerInfo�е���Ϣ���иĶ�
			enemyPlayerInfo = new PlayerInfo(tempPlayerInfo.fileName, tempPlayerInfo.isAI);

			break;
		case 6://��ʼ��Ϸ
			roundNum++;
			Director::getInstance()->pushScene(PreparationScene::createScene(myPlayerInfo));

			break;
	}
}

void OnlineModeScene::onDisconnect()
{
}


//�����ʼ��
void OnlineModeScene::initNetwork()
{
	client =  SocketClient::construct();
    client->onRecv = CC_CALLBACK_2(OnlineModeScene::onRecv, this);
	client->onDisconnect = CC_CALLBACK_0(OnlineModeScene::onDisconnect, this);
	if (!client->connectServer("127.0.0.1", 8000))
	{
		Size visible_size = Director::getInstance()->getVisibleSize();//�����Ļ��С
		auto game_name_label = Label::createWithSystemFont("fail connect", "fonts.ttf", 100);
		game_name_label->setPosition(visible_size.width / 2, visible_size.height * 2);//��δ�ܳɹ����ӱ�ǩ������Ļ�м�ƫ��
		this->addChild(game_name_label);
	}
}


