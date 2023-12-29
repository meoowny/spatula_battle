#ifndef __BASEROUND_SCENE_H__
#define __BASEROUND_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Player/Player.h"

#include <vector>//���޸�  ֻ�ǲ�����

using namespace cocos2d;
using namespace ui;

const int offset_x = -150;
const int offset_y = 220;
const int chessboardCellWidth = 100;
const int chessboardCellHeight = 100;

struct LegendWithLocation 
{
    LegendInfo* legend;
    Position position;
};

class BaseRoundScene : public Scene
{
public:
    BaseRoundScene(PlayerInfo* playerInfo1 = NULL, PlayerInfo* playerInfo2 = NULL)
        :_playerInfo1(playerInfo1), _playerInfo2(playerInfo2){}

    void displayBackground();    //��ʾ����
    void displayStore();         //��ʾ�̵�
    void displayBuyButton();     //��ʾ������ֵ��ť
    void displayRefreshButton(); //��ʾˢ�°�ť
    void displayStoreLegend();   //��ʾ�̵�Ӣ�ۿ���
    void displayMyPrepareLegend(); //��ʾ��ս��Ӣ��
    void displayMyBattleLegend();  //��ʾս����Ӣ��
    void displayMyPlayer();      //��ʾ�ҷ�ССӢ��
    void displayCoinNumber();   //��ʾ�ҷ��������
    //void displayDeleteButton();  //��ʾɾ����ť


    LegendWithLocation selectLegend(EventMouse* event); //ѡ��Ҫ�϶���Ӣ��
    void dragLegend(EventMouse* event, LegendWithLocation selectedSpriteWithLocation);   //�϶�Ӣ��

    void moveMyPlayer(EventMouse* event);          //�ƶ�ССӢ��

    void buyButtonClickCallback(Ref* pSender);     //������ֵ��ť�ص�����
    void refreshButtonClickCallback(Ref* pSender); //ˢ�°�ť�ص�����
    void buyLegendCallback(Ref* pSender);          //����Ӣ�ۻص�����


    void countdown();                   //��ʼ����ʱ
    void updateTimerCallback(float dt); //��ʱ���ص����������ڸ���ʣ��ʱ��

    CREATE_FUNC(BaseRoundScene);

protected:

    //���޸� ֻ�ǲ�����
    //std::vector<Sprite*> sprites;

    PlayerInfo* _playerInfo1;
    PlayerInfo* _playerInfo2;


private:
    Label* labelRemainTime;     //��ʾʣ��ʱ��ı�ǩ
    int remainingTimeInSeconds; //ʣ��ʱ��



};


#endif // __BASEROUND_SCENE_H__
