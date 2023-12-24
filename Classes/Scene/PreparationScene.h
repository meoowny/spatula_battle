#ifndef __PREPARATION_SCENE_H__
#define __PREPARATION_SCENE_H__

#include "BaseRoundScene.h"

class PreparationScene : public BaseRoundScene
{
public:
	static Scene* createScene();
	virtual bool init();

	void displayPlayer();//显示小小英雄

    //监听鼠标操作函数
    void onMouseDown(EventMouse* event);
    void mouseLeftClick(EventMouse* event);
    void mouseRightClick(EventMouse* event);
    void onMouseMove(EventMouse* event);
    void onMouseUp(EventMouse* event);

    CREATE_FUNC(PreparationScene);

private:
    Sprite* selectedSprite = nullptr; //记录被选中拖动的英雄
    Sprite* myPlayer;                 //小小英雄
};

#endif // __PREPARATION_SCENE_H__