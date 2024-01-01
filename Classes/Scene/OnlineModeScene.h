#ifndef __ONLINEMODE_SCENE_H__
#define __ONLINEMODE_SCENE_H__

#include "socket/SocketClient.h"
#include <string>
#include <sstream>
#include "Player/Player.h"
#include"Scene/PreparationScene.h"
#include"Scene/BattleScene.h"



class OnlineModeScene : public Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(OnlineModeScene);

	void onEnter();
	void onExit();

	void onRecv(const char* data, int count);
	void onDisconnect();
	char ID;
	int roundNum;//记录场景跳转的数量


	void givePlayerInfoCallBack(Ref* pSender);//分配玩家信息

	
protected:
	void initNetwork();//网络初始化
	SocketClient* client;


private:
	PlayerInfo *myPlayerInfo;
	PlayerInfo* enemyPlayerInfo;
	int changePlayerInfo(AfterParationInfo& tempAfterParationInfo);//对enemyplayerinfo内信息进行改动
};


#endif
