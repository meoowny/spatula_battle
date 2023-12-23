#include "StartupScene.h"

//����StartupScene�ĳ���
Scene* StartupScene::createScene()
{
	auto scene = Scene::create();//����һ������
	auto firstLayer = StartupScene::create();//����һ��ͼ��
	scene->addChild(firstLayer);//��firstLayerͼ����뵽scene������
	return scene;
}

//��ʼ��StartupScene
bool StartupScene::init()
{
	if (!Layer::init())//�ȳ�ʼ�������init������ʼ��ʧ�ܣ�����false
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();//�����Ļ��С
	//��ӱ���ͼƬ
	auto background = Sprite::create("StartUpSceneBackground.jpg");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(1.5);
	this->addChild(background);
	//������Ϸ����ǩ
	auto labelGameName = Label::createWithSystemFont("�����֮ս", "STHUPO.ttf", 150);
	labelGameName->setPosition(visibleSize.width / 2, visibleSize.height * 2 / 3);//����Ϸ����ǩ������Ļ�м�ƫ��
	labelGameName->setColor(Color3B::RED);
	this->addChild(labelGameName);
	this->addChild(addMenuItem());//��Ӳ˵�
	return true;
}

Menu* StartupScene::addMenuItem()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();//�����Ļ��С
	//��������ģʽ��ǩ
	auto labelOnlineMode = Label::createWithSystemFont("����ģʽ", "STHUPO.ttf", 100);
	labelOnlineMode->setColor(Color3B::RED);
	auto itemOnlineMode = MenuItemLabel::create(labelOnlineMode, CC_CALLBACK_1(StartupScene::onlineModeCallBack, this));
	itemOnlineMode->setPosition(0, 0);

	//���õ���ģʽ��ǩ
	auto labelStandaloneMode = Label::createWithSystemFont("����ģʽ", "STHUPO.ttf", 100);
	labelStandaloneMode->setColor(Color3B::RED);
	auto itemStandaloneMode = MenuItemLabel::create(labelStandaloneMode, CC_CALLBACK_1(StartupScene::standaloneModeCallBack, this));
	itemStandaloneMode->setPosition(0, -visibleSize.height / 8);

	//����˳���Ϸ��ǩ
	auto labelMenuClose = Label::createWithSystemFont("�˳���Ϸ", "STHUPO.ttf", 100);
	labelMenuClose->setColor(Color3B::RED);
	auto itemMenuClose = MenuItemLabel::create(labelMenuClose, CC_CALLBACK_1(StartupScene::menuCloseCallBack, this));
	itemMenuClose->setPosition(0, -visibleSize.height / 6);

	//����ǩ��ӵ��˵���
	auto menu = Menu::create(itemOnlineMode, itemStandaloneMode, itemMenuClose, NULL);
	//menu->alignItemsVerticallyWithPadding(30);//���ò˵���Ŀ��Ŀ��
	return menu;
}

//�ص���������ת������ģʽ
void StartupScene::onlineModeCallBack(Ref* pSender)
{
	//Director::getInstance()->replaceScene(second_scene::createScene());
}

//�ص���������ת������ģʽ
void StartupScene::standaloneModeCallBack(Ref* pSender)
{
	//Director::getInstance()->replaceScene(second_scene::createScene());
}

//�ص���������ת���˳���Ϸ
void StartupScene::menuCloseCallBack(Ref* pSender)
{
	Director::getInstance()->end();
}
