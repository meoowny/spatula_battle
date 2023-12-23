#ifndef __SATRTUP_SCENE_H__
#define __SATRTUP_SCENE_H__

#include <cocos2d.h>
using namespace cocos2d;

//新建一个继承层的类
class StartupScene :public Layer
{
public:
	static Scene* createScene();//创建first_scene的场景
	virtual bool init();//first_scene的初始化
	CREATE_FUNC(StartupScene);//创建first_scene的create方法
	Menu* addMenuItem();//添加菜单条目，并返回菜单
	void onlineModeCallBack(Ref* pSender);//跳转到联机模式
	void standaloneModeCallBack(Ref* pSender);//跳转到单机模式
	void menuCloseCallBack(Ref* pSender);//跳转到退出游戏
};

#endif#pragma once