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

    void displayBoard();         //œ‘ æ∆Â≈Ã

    //º‡Ã˝ Û±Í≤Ÿ◊˜∫Ø ˝
    void onMouseDown(EventMouse* event);
    void onMouseMove(EventMouse* event);
    void onMouseUp(EventMouse* event);

    CREATE_FUNC(PreparationScene);
private:
    Sprite* chessboard[boardWidth][boardHeight]; //∆Â≈Ã∏Ò◊”

    // int chessboard[boardWidth][boardHeight];//∆Â≈Ã”¢–€

   

};

#endif // __PREPARATION_SCENE_H__