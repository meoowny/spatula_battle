#ifndef __ONLINEMODE_SCENE_H__
#define __ONLINEMODE_SCENE_H__

#include "socket/SocketClient.h"
#include <string>
#include <sstream>
#include "Player/Player.h"
#include"Scene/PreparationScene.h"
#include"Scene/BattleScene.h"


#include "ExerciseScene.h"

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
	int roundNum;//��¼������ת������


	void givePlayerInfoCallBack(Ref* pSender);//���������Ϣ

	
protected:
	void initNetwork();//�����ʼ��
	SocketClient* client;


private:
	PlayerInfo *myPlayerInfo;
	PlayerInfo* enemyPlayerInfo;
};


#endif
