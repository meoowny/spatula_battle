#ifndef __SATRTUP_SCENE_H__
#define __SATRTUP_SCENE_H__

#include <cocos2d.h>
#include"ui/CocosGUI.h"
using namespace cocos2d;

//�½�һ���̳в����
class StartupScene :public Layer
{
public:
	static Scene* createScene();//����first_scene�ĳ���
	virtual bool init();//first_scene�ĳ�ʼ��
	CREATE_FUNC(StartupScene);//����first_scene��create����
	Menu* addMenuItem();//��Ӳ˵���Ŀ�������ز˵�
	void onlineModeCallBack(Ref* pSender);//��ת������ģʽ
	void standaloneModeCallBack(Ref* pSender);//��ת������ģʽ
	void menuCloseCallBack(Ref* pSender);//��ת���˳���Ϸ
	void onSetupButtonClick(Ref* psender);
};

#endif#pragma once