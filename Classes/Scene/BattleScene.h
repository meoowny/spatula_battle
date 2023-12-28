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

    Vec2 findMovePath(int x,int y,int Flag); //Ѱ���ƶ�·��

    //�ݶ�Ϊbool��  ������Ӧ�÷���һ�����꣬��ʾ����λ��
    bool opponentLegendInRange(int x, int y, int range);  // ��鹥����Χ���Ƿ���ڶԷ�����

    bool isValidPosition(int x, int y);
    double calculateDistance(int x1, int y1, int x2, int y2);
};

#endif // __BATTLE_SCENE_H__