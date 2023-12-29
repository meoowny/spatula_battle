#ifndef __SCENE_H__
#define __SCENE_H__

#include "socket/SocketClient.h"
#include <string>
#include "Scene/OnlineModeScene.h"

class ExerciseScene : public Scene
{
public:
	ExerciseScene(SocketClient* tempClient) :client(tempClient) {};
	static Scene* createScene(SocketClient* tempClient);
	virtual bool init();
	//CREATE_FUNC(ExerciseScene);
	static ExerciseScene* create(SocketClient* tempClient) {
		ExerciseScene* pRet = new(std::nothrow) ExerciseScene(tempClient); if (pRet && pRet->init()) {
			pRet->autorelease(); return pRet;
		}
		else {
			delete pRet; pRet = nullptr; return nullptr;
		}
	}
	void startGameCallBack(Ref* pSender);
protected:
	SocketClient* client;

};














#endif
