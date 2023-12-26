#ifndef __SATRTUP_SCENE_H__
#define __SATRTUP_SCENE_H__

#include <cocos2d.h>
#include "ServerModeScene.h"
#include "OnlineModeScene.h"
using namespace cocos2d;

//新建一个继承层的类
class StartupScene :public Layer
{
public:
	static Scene* createScene();//创建StartupScene的场景
	virtual bool init();//StartupScene的初始化
	CREATE_FUNC(StartupScene);//创建StartupScene的create方法
	Menu* addMenuItem();//添加菜单条目，并返回菜单
	void onlineModeCallBack(Ref* pSender);//跳转到联机模式
	void standaloneModeCallBack(Ref* pSender);//跳转到单机模式
	void serverModeCallBack(Ref* pSender);//跳转到服务器模式
	void menuCloseCallBack(Ref* pSender);//跳转到退出游戏
};

#endif