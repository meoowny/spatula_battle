#ifndef __SERVERMODE_SCENE_H__
#define __SERVERMODE_SCENE_H__

#include "socket/SocketServer.h"


class ServerModeScene :public Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ServerModeScene);

	void onEnter();
	void onExit();

protected:
	void initNetwork();//ÍøÂç³õÊ¼»¯

private:
	SocketServer* server;
};

#endif
