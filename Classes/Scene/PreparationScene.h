#ifndef __PREPARATION_SCENE_H__
#define __PREPARATION_SCENE_H__

#include "BaseRoundScene.h"



class PreparationScene : public BaseRoundScene
{
public:
    PreparationScene(PlayerInfo* playerInfo)
        : BaseRoundScene(playerInfo) { }

	static Scene* createScene(PlayerInfo* playerInfo);
	virtual bool init();

    void displayBoard();         //��ʾ����

    void boardCellSelected(EventMouse* event);   //���̻���

    //��������������
    void onMouseDown(EventMouse* event);
    void onMouseMove(EventMouse* event);
    void onMouseUp(EventMouse* event);

    //CREATE_FUNC(PreparationScene);

    static PreparationScene* create(PlayerInfo* playerInfo) {
        PreparationScene* pRet = new(std::nothrow) PreparationScene(playerInfo); if (pRet && pRet->init()) {
            pRet->autorelease(); return pRet;
        }
        else {
            delete pRet; pRet = nullptr; return nullptr;
        }
    }


private:
    Sprite* battleChessboard[battleBoardWidth][battleBoardWidth];      //ս��������
    Sprite* battleSelectedChessboard[battleBoardWidth][battleBoardWidth];      //ս������������
    Sprite* preparationChessboard[preparationSize];              //��ս������
    Sprite* preparationSelectedChessboard[preparationSize];              //��ս����������

    //LegendWithLocation selectedSpriteWithLocation = { nullptr,{-1,-1} }; //��¼��ѡ���϶���Ӣ��
};

#endif // __PREPARATION_SCENE_H__