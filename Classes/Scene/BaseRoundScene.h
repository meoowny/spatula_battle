#ifndef __BASEROUND_SCENE_H__
#define __BASEROUND_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Player/Player.h"

#include <vector>//待修改  只是测试用

using namespace cocos2d;
using namespace ui;

const int offset_x = -150;
const int offset_y = 220;
const int chessboardCellWidth = 100;
const int chessboardCellHeight = 100;

class BaseRoundScene : public Scene
{
public:
    BaseRoundScene(PlayerInfo* playerInfo1 = NULL, PlayerInfo* playerInfo2 = NULL)
        :_playerInfo1(playerInfo1), _playerInfo2(playerInfo2){}

    void displayBackground();    //显示背景
    void displayStore();         //显示商店
    void displayBuyButton();     //显示购买经验值按钮
    void displayRefreshButton(); //显示刷新按钮
    void displayStoreLegend();   //显示商店英雄卡牌
    void displayMyPrepareLegend(); //显示备战区英雄
    void displayMyBattleLegend();  //显示战斗区英雄
    void displayMyPlayer();      //显示我方小小英雄
    //void displayDeleteButton();  //显示删除按钮


    Sprite* selectLegend(EventMouse* event); //选择要拖动的英雄
    void dragLegend(EventMouse* event, Sprite* selectedSprite);   //拖动英雄

    void moveMyPlayer(EventMouse* event);          //移动小小英雄

    void buyButtonClickCallback(Ref* pSender);     //购买经验值按钮回调函数
    void refreshButtonClickCallback(Ref* pSender); //刷新按钮回调函数
    void buyLegendCallback(Ref* pSender);          //购买英雄回调函数


    void countdown();                   //开始倒计时
    void updateTimerCallback(float dt); //定时器回调函数，用于更新剩余时间

    CREATE_FUNC(BaseRoundScene);

protected:

    //待修改 只是测试用
    std::vector<Sprite*> sprites;

    PlayerInfo* _playerInfo1;
    PlayerInfo* _playerInfo2;

private:
    Label* labelRemainTime;     //显示剩余时间的标签
    int remainingTimeInSeconds; //剩余时间
    //Sprite* myPlayer;           //己方小小英雄



};


#endif // __BASEROUND_SCENE_H__
