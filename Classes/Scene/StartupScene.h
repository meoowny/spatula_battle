#ifndef __SATRTUP_SCENE_H__
#define __SATRTUP_SCENE_H__

#include "cocos2d.h"
#include"ui/CocosGUI.h"
#include "Scene/PreparationScene.h"
#include "Scene/ServerModeScene.h"
#include "Scene/OnlineModeScene.h"

using namespace cocos2d;

//�½�һ���̳в����
class StartupScene :public Layer
{
public:
	static Scene* createScene();//����StartupScene�ĳ���
	virtual bool init();//StartupScene�ĳ�ʼ��
	CREATE_FUNC(StartupScene);//����StartupScene��create����
	Menu* addMenuItem();//��Ӳ˵���Ŀ�������ز˵�
	void onlineModeCallBack(Ref* pSender);//��ת������ģʽ
	void standaloneModeCallBack(Ref* pSender);//��ת������ģʽ

	//void menuCloseCallBack(Ref* pSender);//��ת���˳���Ϸ
	void onSetupButtonClick(Ref* psender);
	void serverModeCallBack(Ref* pSender);//��ת��������ģʽ
};

#endif //__SATRTUP_SCENE_H__
