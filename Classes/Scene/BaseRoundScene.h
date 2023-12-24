#ifndef __BASEROUND_SCENE_H__
#define __BASEROUND_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Player/Player.h"
using namespace cocos2d;
using namespace ui;

class BaseRoundScene : public Scene
{
public:
    void displayBackground();    //��ʾ����
    void displayStore();         //��ʾ�̵�
    void displayBuyButton();     //��ʾ������ֵ��ť
    void displayRefreshButton(); //��ʾˢ�°�ť
    void displayStoreLegend();   //��ʾ�̵�Ӣ�ۿ���
    void displayPrepareLegend(); //��ʾ��ս��Ӣ��
    void displayBattleLegend();  //��ʾս����Ӣ��

    void buyButtonClickCallback(Ref* pSender);     //������ֵ��ť�ص�����
    void refreshButtonClickCallback(Ref* pSender); //ˢ�°�ť�ص�����
    void buyLegendCallback(Ref* pSender);          //����Ӣ�ۻص�����

    void countdown();                   //��ʼ����ʱ
    void updateTimerCallback(float dt); //��ʱ���ص����������ڸ���ʣ��ʱ��

    CREATE_FUNC(BaseRoundScene);

private:
    Label* labelRemainTime;     //��ʾʣ��ʱ��ı�ǩ
    int remainingTimeInSeconds; //ʣ��ʱ��
};


#endif // __BASEROUND_SCENE_H__
