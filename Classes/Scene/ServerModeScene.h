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

	void startGameCallBack(Ref* pSender);//��ת����Ϸ��ʼ
	void givePlayerInfoCallBack(Ref* pSender);//���������Ϣ

private:
	class SocketServer* server;

protected:
	void initNetwork();//�����ʼ��

};

#endif
