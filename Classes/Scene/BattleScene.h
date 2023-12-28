#ifndef __BATTLE_SCENE_H__
#define __BATTLE_SCENE_H__

#include "BaseRoundScene.h"

const int emptyFlag = 0;
const int myFlag = 1;
const int enemyFlag = 2;

class BattleScene : public BaseRoundScene
{
public:
    BattleScene(PlayerInfo* playerInfo1, PlayerInfo* playerInfo2);
        //: BaseRoundScene(playerInfo1, playerInfo2) {}
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

    Vec2 findMovePath(int x,int y,int Flag); //寻找移动路径

    //暂定为bool型  理论上应该返回一个坐标，表示敌人位置
    bool opponentLegendInRange(int x, int y, int range);  // 检查攻击范围内是否存在对方棋子

    bool isValidPosition(int x, int y);
    double calculateDistance(int x1, int y1, int x2, int y2);
};

#endif // __BATTLE_SCENE_H__