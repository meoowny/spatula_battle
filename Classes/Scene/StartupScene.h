#ifndef __SATRTUP_SCENE_H__
#define __SATRTUP_SCENE_H__

#include "cocos2d.h"
#include"ui/CocosGUI.h"
#include "Scene/PreparationScene.h"
#include "Scene/ServerModeScene.h"
#include "Scene/OnlineModeScene.h"
#include "Scene/BattleScene.h"

using namespace cocos2d;

//�½�һ���̳в����
class StartupScene :public Layer
{
public:
	static Scene* createScene();//����first_scene�ĳ���
	virtual bool init();//first_scene�ĳ�ʼ��
	CREATE_FUNC(StartupScene);//����first_scene��create����
	Menu* addMenuItem(PlayerInfo* playerInfo);//��Ӳ˵���Ŀ�������ز˵�
	static void onlineModeCallBack(Ref* pSender);//��ת������ģʽ
	static void standaloneModeCallBack(PlayerInfo* playerInfo, Ref* pSender);//��ת������ģʽ
	//void menuCloseCallBack(Ref* pSender);//��ת���˳���Ϸ
	static void onSetupButtonClick(Ref* psender);
};

#endif //__SATRTUP_SCENE_H__
