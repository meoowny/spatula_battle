#ifndef __BASEROUND_SCENE_H__
#define __BASEROUND_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Player/Player.h"

#include <vector>//待修改  只是测试用

using namespace cocos2d;
using namespace ui;

class BaseRoundScene : public Scene
{
public:
    void displayBackground();    //显示背景
    void displayStore();         //显示商店
    void displayBuyButton();     //显示购买经验值按钮
    void displayRefreshButton(); //显示刷新按钮
    void displayStoreLegend();   //显示商店英雄卡牌
    void displayPrepareLegend(); //显示备战区英雄
    void displayBattleLegend();  //显示战斗区英雄
    void displayMyPlayer();      //显示我方小小英雄
    //void displayDeleteButton();  //显示删除按钮


    void selectLegend(EventMouse* event); //选择要拖动的英雄
    void dragLegend(EventMouse* event);   //拖动英雄

    void moveMyPlayer(EventMouse* event);          //移动小小英雄

    void buyButtonClickCallback(Ref* pSender);     //购买经验值按钮回调函数
    void refreshButtonClickCallback(Ref* pSender); //刷新按钮回调函数
    void buyLegendCallback(Ref* pSender);          //购买英雄回调函数


    void countdown();                   //开始倒计时
    void updateTimerCallback(float dt); //定时器回调函数，用于更新剩余时间

    CREATE_FUNC(BaseRoundScene);

protected:
    Sprite* selectedSprite = nullptr; //记录被选中拖动的英雄

    //待修改 只是测试用
    vector<Sprite*> sprites;

private:
    Label* labelRemainTime;     //显示剩余时间的标签
    int remainingTimeInSeconds; //剩余时间
    Sprite* myPlayer;           //己方小小英雄



};


#endif // __BASEROUND_SCENE_H__
