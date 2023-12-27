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

    void displayOppoPlayer();       //显示对方小小英雄
    void displayOppoPrepareLegend(); //显示对方备战区英雄
    void displayOppoBattleLegend(); //显示对方战斗区英雄
    void performBattlingLogic(float delta);           //执行战斗逻辑


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