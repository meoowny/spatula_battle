#ifndef __BASEROUND_SCENE_H__
#define __BASEROUND_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Player/Player.h"

#include <vector>//���޸�  ֻ�ǲ�����

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
    void displayMyPlayer();      //��ʾ�ҷ�ССӢ��
    //void displayDeleteButton();  //��ʾɾ����ť


    void selectLegend(EventMouse* event); //ѡ��Ҫ�϶���Ӣ��
    void dragLegend(EventMouse* event);   //�϶�Ӣ��

    void moveMyPlayer(EventMouse* event);          //�ƶ�ССӢ��

    void buyButtonClickCallback(Ref* pSender);     //������ֵ��ť�ص�����
    void refreshButtonClickCallback(Ref* pSender); //ˢ�°�ť�ص�����
    void buyLegendCallback(Ref* pSender);          //����Ӣ�ۻص�����


    void countdown();                   //��ʼ����ʱ
    void updateTimerCallback(float dt); //��ʱ���ص����������ڸ���ʣ��ʱ��

    CREATE_FUNC(BaseRoundScene);

protected:
    Sprite* selectedSprite = nullptr; //��¼��ѡ���϶���Ӣ��

    //���޸� ֻ�ǲ�����
    vector<Sprite*> sprites;

private:
    Label* labelRemainTime;     //��ʾʣ��ʱ��ı�ǩ
    int remainingTimeInSeconds; //ʣ��ʱ��
    Sprite* myPlayer;           //����ССӢ��



};


#endif // __BASEROUND_SCENE_H__
