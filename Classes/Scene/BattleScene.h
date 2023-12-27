#ifndef __BATTLE_SCENE_H__
#define __BATTLE_SCENE_H__

#include "BaseRoundScene.h"

class BattleScene : public BaseRoundScene
{
public:
<<<<<<< Updated upstream
    static Scene* createScene();
=======
    BattleScene(PlayerInfo* playerInfo1, PlayerInfo* playerInfo2);
        //: BaseRoundScene(playerInfo1, playerInfo2) {}
    static Scene* createScene(PlayerInfo* playerInfo1, PlayerInfo* playerInfo2);
>>>>>>> Stashed changes
    virtual bool init();

 

<<<<<<< Updated upstream
    CREATE_FUNC(BattleScene);
=======

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

    Vec2 findMovePath(int chessBoard[battleBoardWidth][battleBoardHeight * 2]);
>>>>>>> Stashed changes
};

#endif // __BATTLE_SCENE_H__