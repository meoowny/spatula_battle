#ifndef __PREPARATION_SCENE_H__
#define __PREPARATION_SCENE_H__

#include "BaseRoundScene.h"

const int boardWidth = 7;
const int boardHeight = 3;
const int chessboardCellWidth = 100;
const int chessboardCellHeight = 100;

class PreparationScene : public BaseRoundScene
{
public:
	static Scene* createScene();
	virtual bool init();

    void displayBoard();         //��ʾ����

    //��������������
    void onMouseDown(EventMouse* event);
    void onMouseMove(EventMouse* event);
    void onMouseUp(EventMouse* event);

    CREATE_FUNC(PreparationScene);
private:
    Sprite* chessboard[boardWidth][boardHeight]; //���̸���

    // int chessboard[boardWidth][boardHeight];//����Ӣ��

   

};

#endif // __PREPARATION_SCENE_H__