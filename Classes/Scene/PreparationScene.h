#ifndef __PREPARATION_SCENE_H__
#define __PREPARATION_SCENE_H__

#include "BaseRoundScene.h"

const int chessboardCellWidth = 100;
const int chessboardCellHeight = 100;
const int preparationBoardWidth = 9;;

class PreparationScene : public BaseRoundScene
{
public:
	static Scene* createScene();
	virtual bool init();

    void displayBoard();         //显示棋盘

    void boardCellSelected(EventMouse* event);   //棋盘回显

    //监听鼠标操作函数
    void onMouseDown(EventMouse* event);
    void onMouseMove(EventMouse* event);
    void onMouseUp(EventMouse* event);

    CREATE_FUNC(PreparationScene);
private:
    Sprite* battleChessboard[battleBoardWidth][battleBoardWidth];      //战斗区棋盘
    Sprite* battleSelectedChessboard[battleBoardWidth][battleBoardWidth];      //战斗区回显棋盘
    Sprite* preparationChessboard[preparationBoardWidth];              //备战区棋盘
    Sprite* preparationSelectedChessboard[preparationBoardWidth];              //备战区回显棋盘

    // int chessboard[boardWidth][boardHeight];//棋盘英雄

   

};

#endif // __PREPARATION_SCENE_H__