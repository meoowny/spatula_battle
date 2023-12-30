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

	Size visibleSize = Director::getInstance()->getVisibleSize();//获得屏幕大小

	//设置开始游戏标签
	auto labelStartGame = Label::createWithSystemFont("开始了", "STHUPO.TTF", 120);
	auto itemStartGame = MenuItemLabel::create(labelStartGame, CC_CALLBACK_1(ExerciseScene::startGameCallBack, this));


	//将标签添加到菜单里
	auto menu = Menu::create(itemStartGame,  NULL);
	menu->alignItemsVerticallyWithPadding(30);//设置菜单条目间的宽度
	menu->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	this->addChild(menu);
	return true;
}


//通知玩家游戏开始
void ExerciseScene::startGameCallBack(Ref* pSender)
{
	Director::getInstance()->popScene();
}
