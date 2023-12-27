#ifndef __SERVERMODE_SCENE_H__
#define __SERVERMODE_SCENE_H__

#include "Socket/SocketServer.h"
#include "Player/Player.h"

class ServerModeScene :public Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ServerModeScene);

	void onEnter();
	void onExit();

	void startGameCallBack(Ref* pSender);//跳转到游戏开始
	void givePlayerInfoCallBack(Ref* pSender);//分配玩家信息

private:
	SocketServer* server;

protected:
	void initNetwork();//网络初始化

};

#endif
