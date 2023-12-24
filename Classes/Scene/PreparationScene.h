#ifndef __PREPARATION_SCENE_H__
#define __PREPARATION_SCENE_H__

#include "BaseRoundScene.h"

class PreparationScene : public BaseRoundScene
{
public:
	static Scene* createScene();
	virtual bool init();

	void displayPlayer();//��ʾССӢ��

    //��������������
    void onMouseDown(EventMouse* event);
    void mouseLeftClick(EventMouse* event);
    void mouseRightClick(EventMouse* event);
    void onMouseMove(EventMouse* event);
    void onMouseUp(EventMouse* event);

    CREATE_FUNC(PreparationScene);

private:
    Sprite* selectedSprite = nullptr; //��¼��ѡ���϶���Ӣ��
    Sprite* myPlayer;                 //ССӢ��
};

#endif // __PREPARATION_SCENE_H__