#ifndef __SATRTUP_SCENE_H__
#define __SATRTUP_SCENE_H__

<<<<<<< HEAD
#include "cocos2d.h"
#include"ui/CocosGUI.h"
#include "Scene/PreparationScene.h"
=======
#include <cocos2d.h>
#include "ServerModeScene.h"
#include "OnlineModeScene.h"
>>>>>>> bgy
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
<<<<<<< HEAD
	//void menuCloseCallBack(Ref* pSender);//��ת���˳���Ϸ
	void onSetupButtonClick(Ref* psender);
};

#endif //__SATRTUP_SCENE_H__
=======
	void serverModeCallBack(Ref* pSender);//��ת��������ģʽ
	void menuCloseCallBack(Ref* pSender);//��ת���˳���Ϸ
};

#endif
>>>>>>> bgy
