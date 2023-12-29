#include "ExerciseScene.h"


Scene* ExerciseScene::createScene(SocketClient* tempClient)
{
	return ExerciseScene::create(tempClient);
}

bool ExerciseScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();//�����Ļ��С

	//���ÿ�ʼ��Ϸ��ǩ
	auto labelStartGame = Label::createWithSystemFont("��ʼ��", "STHUPO.TTF", 120);
	auto itemStartGame = MenuItemLabel::create(labelStartGame, CC_CALLBACK_1(ExerciseScene::startGameCallBack, this));


	//����ǩ��ӵ��˵���
	auto menu = Menu::create(itemStartGame,  NULL);
	menu->alignItemsVerticallyWithPadding(30);//���ò˵���Ŀ��Ŀ��
	menu->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	this->addChild(menu);
	return true;
}


//֪ͨ�����Ϸ��ʼ
void ExerciseScene::startGameCallBack(Ref* pSender)
{
	Director::getInstance()->popScene();
}
