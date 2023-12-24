#include "StartupScene.h"
#include"SetupScene.h"
#include"ui/CocosGUI.h"
#include "Player/Player.h"
#include "SimpleAudioEngine.h"

//创建StartupScene的场景
Scene* StartupScene::createScene()
{
	auto scene = Scene::create();//创建一个场景
	auto firstLayer = StartupScene::create();//创建一个图层
	scene->addChild(firstLayer);//把firstLayer图层加入到scene场景中
	return scene;
}

//初始化StartupScene
bool StartupScene::init()
{
	if (!Layer::init())//先初始化父类的init，若初始化失败，返回false
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();//获得屏幕大小

	// 一个循环播放的 BGM
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("ZombiesOnYourLawn.ogg", true);

	//添加背景图片
	auto background = Sprite::create("StartUpSceneBackground.jpg");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(1.5);
	this->addChild(background);

	
	
	 //添加设置按钮
	auto setupButton = ui::Button::create("SetupButton_Normal.png", "SetupButton_Selected.png");
	setupButton->setPosition(Vec2(visibleSize.width * 0.1, visibleSize.height * 0.9));//把按钮放置在场景的右上角
	setupButton->addClickEventListener([=](Ref* sender) {
		Director::getInstance()->pushScene(Setup::createScene());
		});
		this->addChild(setupButton);
		
	

	//设置游戏名标签
	auto labelGameName = Label::createWithSystemFont("一起来铲铲", "STHUPO.TTF", 200);
	labelGameName->setPosition(visibleSize.width / 3, visibleSize.height * 3 / 4);//将游戏名标签放置屏幕中间偏上
	labelGameName->setColor(Color3B::YELLOW);
	this->addChild(labelGameName);
	this->addChild(addMenuItem());//添加菜单

	// 放一个帧动画的演示，连续快速点击 Create 按钮有奇效
	auto menuImage = MenuItemImage::create(
		"Peashooter_9.png",   // 正常状态的按钮图片
		"Peashooter_0.png",   // 按下状态的按钮图片
		testCallBack          // 帧动画的实现放在 testCallBack 中了
	);
	menuImage->setPosition(visibleSize.width * 0.9, visibleSize.height * 0.1);

	auto menuItem1 = MenuItemFont::create("Create");
	menuItem1->setFontNameObj("arial.ttf");
	menuItem1->setFontSizeObj(32);
	menuItem1->setName("menuItem1");
	menuItem1->setColor(Color3B(0, 0, 0));
	menuImage->addChild(menuItem1);

	auto menuI = Menu::create(menuImage, NULL);
	menuI->setName("menu");
	menuI->setPosition(Vec2::ZERO);

	this->addChild(menuI, 2);

	return true;
}

Menu* StartupScene::addMenuItem()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();//获得屏幕大小
	//设置联机模式标签
	auto labelOnlineMode = Label::createWithSystemFont("联机模式", "STHUPO.TTF", 120);
	auto itemOnlineMode = MenuItemLabel::create(labelOnlineMode, CC_CALLBACK_1(StartupScene::onlineModeCallBack, this));

	//设置单机模式标签
	auto labelStandaloneMode = Label::createWithSystemFont("单机模式", "STHUPO.TTF", 120);
	auto itemStandaloneMode = MenuItemLabel::create(labelStandaloneMode, CC_CALLBACK_1(StartupScene::standaloneModeCallBack, this));

	//添加退出游戏标签
	auto labelMenuClose = Label::createWithSystemFont("我去图书馆了", "STHUPO.TTF", 120);
	auto itemMenuClose = MenuItemLabel::create(labelMenuClose, CC_CALLBACK_1(StartupScene::menuCloseCallBack, this));

	//添加设置按钮
	auto setupButton = MenuItemImage::create(
		"SetupButton_Noarmal.png",   // 正常状态的按钮图片
		"SetupButton_Selected.png", // 按下状态的按钮图片
		CC_CALLBACK_1(StartupScene::onSetupButtonClick, this) // 按钮回调函数
	);
	setupButton->setPosition(visibleSize.width * 0.9, visibleSize.height * 0.1);

	

	//将标签添加到菜单里
	auto menu = Menu::create(itemOnlineMode, itemStandaloneMode, itemMenuClose ,NULL);
	menu->alignItemsVerticallyWithPadding(30);//设置菜单条目间的宽度
	menu->setPosition(visibleSize.width*3 / 4, visibleSize.height*2 / 5);
	menu->setColor(Color3B::BLACK);
	return menu;
}

//回调函数，跳转到联机模式
void StartupScene::onlineModeCallBack(Ref* pSender)
{
	//Director::getInstance()->replaceScene(second_scene::createScene());
}

//回调函数，跳转到单机模式
void StartupScene::standaloneModeCallBack(Ref* pSender)
{
	//Director::getInstance()->replaceScene(second_scene::createScene());
}

//回调函数，跳转到退出游戏
void StartupScene::menuCloseCallBack(Ref* pSender)
{
	// 退出时结束音乐的播放
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	Director::getInstance()->end();
}

//回调函数，跳转到设置界面
void StartupScene::onSetupButtonClick(Ref* pSender) {
	auto scene = Setup::createScene();
	Director::getInstance()->pushScene(scene);
}