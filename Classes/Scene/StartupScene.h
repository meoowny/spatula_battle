#ifndef __SATRTUP_SCENE_H__
#define __SATRTUP_SCENE_H__

#include "cocos2d.h"
#include"ui/CocosGUI.h"
#include "Scene/PreparationScene.h"
using namespace cocos2d;

//新建一个继承层的类
class StartupScene :public Layer
{
public:
	static Scene* createScene();//创建first_scene的场景
	virtual bool init();//first_scene的初始化
	CREATE_FUNC(StartupScene);//创建first_scene的create方法
	Menu* addMenuItem(PlayerInfo* playerInfo);//添加菜单条目，并返回菜单
	static void onlineModeCallBack(Ref* pSender);//跳转到联机模式
	static void standaloneModeCallBack(PlayerInfo* playerInfo, Ref* pSender);//跳转到单机模式
	//void menuCloseCallBack(Ref* pSender);//跳转到退出游戏
	static void onSetupButtonClick(Ref* psender);
};

#endif //__SATRTUP_SCENE_H__