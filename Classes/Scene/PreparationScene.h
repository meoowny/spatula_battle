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

    void displayBoard();         //��ʾ����

    void boardCellSelected(EventMouse* event);   //���̻���

    //��������������
    void onMouseDown(EventMouse* event);
    void onMouseMove(EventMouse* event);
    void onMouseUp(EventMouse* event);

    CREATE_FUNC(PreparationScene);
private:
    Sprite* battleChessboard[battleBoardWidth][battleBoardWidth];      //ս��������
    Sprite* battleSelectedChessboard[battleBoardWidth][battleBoardWidth];      //ս������������
    Sprite* preparationChessboard[preparationBoardWidth];              //��ս������
    Sprite* preparationSelectedChessboard[preparationBoardWidth];              //��ս����������

    // int chessboard[boardWidth][boardHeight];//����Ӣ��

   

};

#endif // __PREPARATION_SCENE_H__