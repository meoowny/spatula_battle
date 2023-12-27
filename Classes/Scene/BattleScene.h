#ifndef __BATTLE_SCENE_H__
#define __BATTLE_SCENE_H__

#include "BaseRoundScene.h"

const int emptyFlag = 0;
const int myFlag = 1;
const int enemyFlag = 2;

class BattleScene : public BaseRoundScene
{
public:
    BattleScene(PlayerInfo* playerInfo1, PlayerInfo* playerInfo2)
        : BaseRoundScene(playerInfo1, playerInfo2) {}
    static Scene* createScene(PlayerInfo* playerInfo1, PlayerInfo* playerInfo2);
    virtual bool init();

    void displayOppoPlayer();       //��ʾ�Է�ССӢ��
    void displayOppoPrepareLegend(); //��ʾ�Է���ս��Ӣ��
    void displayOppoBattleLegend(); //��ʾ�Է�ս����Ӣ��
    void performBattlingLogic(float delta);           //ִ��ս���߼�


    //CREATE_FUNC(BattleScene);
    static BattleScene* create(PlayerInfo* playerInfo1, PlayerInfo* playerInfo2) {
        BattleScene* pRet = new(std::nothrow) BattleScene(playerInfo1, playerInfo2); if (pRet && pRet->init()) {
            pRet->autorelease(); return pRet;
        }
        else {
            delete pRet; pRet = nullptr; return nullptr;
        }
    }

private:
    int chessBoard[battleBoardWidth][battleBoardHeight * 2];

    Vec2 findNearestEnemy(int chessBoard[battleBoardWidth][battleBoardHeight * 2]);
};

#endif // __BATTLE_SCENE_H__