#include "BattleScene.h"

Scene* BattleScene::createScene(PlayerInfo* playerInfo1, PlayerInfo* playerInfo2)
{
    return BattleScene::create(playerInfo1, playerInfo2);
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

BattleScene::BattleScene(PlayerInfo* playerInfo1, PlayerInfo* playerInfo2)
    : BaseRoundScene(playerInfo1, playerInfo2)
{
   /* auto dirs = Director::getInstance()->getRunningScene();
    auto myPlayer = dynamic_cast<Player*>(this->getChildByName("player1"));
    if (myPlayer == nullptr) {
        exit(0);
    }*/



    //auto oppoPlayer = dynamic_cast<Player*>(this->getChildByName("player2"));
           //auto oppoBattlingLegends = oppoPlayer->getBattlingLegends();

    /*for (auto i : myPlayer->getBattlingLegends()) {

        for (auto j : i) {
            if (j == nullptr)
                continue;
        }
    }*/

    //for (int i = 0; i < battleBoardWidth; i++) {
    //    for (int j = 0; j < battleBoardHeight * 2; j++) {
    //        //�ҷ�Ӣ��
    //        if (j < battleBoardHeight) {

    //        }
    //        //�Է�Ӣ��
    //        else {

    //        }
    //    }
    //}

}

bool BattleScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    //��ʾ����
    displayBackground();

    //��ʾ�̵�
    displayStore();

    //��ʾ������ֵ��ť
    displayBuyButton();

    //��ʾˢ�°�ť
    displayRefreshButton();

    //��ʾ�̵�Ӣ�ۿ���
    /*displayStoreLegend();*/

    //��ʾ�ҷ�ССӢ��
    displayMyPlayer();

    //��ʾ�Է�ССӢ��
    displayOppoPlayer();

    //��ʾ�ҷ���ս��Ӣ��
    displayMyPrepareLegend();

    //��ʾ�ҷ�ս����Ӣ��
    displayMyBattleLegend();

    //��ʾ�Է���ս��Ӣ��
    //displayOppoPrepareLegend();

    //��ʾ�Է�ս����Ӣ��
    //displayOppoBattleLegend();

    //��ʼս��
    // schedule(CC_SCHEDULE_SELECTOR(BattleScene::performBattlingLogic), 1.0f);


    countdown();
    return true;
}

void BattleScene::displayOppoPlayer()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();

    //myPlayer = Sprite::create("Peashooter_0.png");
    auto oppoPlayer = Player::create(_playerInfo2);
    if (oppoPlayer == nullptr) {
        problemLoading(oppoPlayer->getResourceName().c_str());
    }
    else
    {
        visibleSize.width / 2 + visibleSize.width / 4, visibleSize.height / 1.2;


        oppoPlayer->setName("player2");
        oppoPlayer->setAnchorPoint(Vec2(0.5f, 0.5f));
        oppoPlayer->setPosition(Vec2(visibleSize.width / 2 + visibleSize.width / 3 + offset_x, visibleSize.height - visibleSize.height / 2.8 + offset_y));
        this->addChild(oppoPlayer, 3);
    }
}

void BattleScene::performBattlingLogic(float delta)
{
    // �����Ϸ��������
    //    if (isGameOver())
    //    {
    //        // ��Ϸ�����߼�
    //    }


    auto dirs = Director::getInstance()->getRunningScene();
    auto myPlayer = dynamic_cast<Player*>(this->getChildByName("player1"));
    if (myPlayer == nullptr) {
        exit(0);
    }

    int count = 0;
    for (auto i : myPlayer->getPreparedLegends()) {
        // TODO: Ӣ�� setName ���淶��LegendInfo ��������ʱʹ�������Ϊ����
        if (i == nullptr)
            continue;
        auto legend = Legend::create(i);
        if (legend == nullptr) {
            problemLoading(legend->getImagePath());
        }
        else {

            // �ƶ��߼�
          

        //Vec2 destination = findMovePath(chessBoard);
//        piece->moveTo(destination);





            // ��������
            // piece->blueBar += delta * 5;  // ����ÿ������5
            // ����δ��ʱ����һ��Ƶ���ͷ���ͨ����
//        if (piece->blueBar < piece->maxBlueBar)
//        {
//            // ����ÿ���ͷ�һ����ͨ����
//            piece->normalAttackCooldown -= delta;
//            if (piece->normalAttackCooldown <= 0)
//            {
//                piece->normalAttack();
//                piece->normalAttackCooldown = piece->maxNormalAttackCooldown;
//            }
//        }
//        else
//        {
//            // ������ʱ�ͷŴ���
//            piece->ultimateAttack();
//            piece->blueBar = 0;  // �������
//        }

          
            legend->setName("0");
            sprites.push_back(legend);
            addChild(legend);
            count++;
        }
    }
}


//Vec2 BattleScene::findNearestEnemy(int chessBoard[battleBoardWidth][battleBoardHeight * 2])
//{
//   
//}




//
//void GameScene::checkCollisions()
//{
//    // �򻯴�������������ɫ��ײʱ������ս�������ٶԷ�Ѫ��
//    for (auto& piece : chessPieces)
//    {
//        for (auto& otherPiece : chessPieces)
//        {
//            if (piece != otherPiece && piece->getBoundingBox().intersectsRect(otherPiece->getBoundingBox()))
//            {
//                piece->attack(otherPiece);
//            }
//        }
//    }
//
//    // �����Ϸ��������
//    if (isGameOver())
//    {
//        // ��Ϸ�����߼�
//        endGame();
//    }
//}
//
//bool GameScene::isGameOver()
//{
//    // �򻯴���������Ϸ����������ĳһ��ȫ����ɫ��Ѫ������
//    int player1Alive = 0;
//    int player2Alive = 0;
//
//    for (auto& piece : chessPieces)
//    {
//        if (piece->isAlive())
//        {
//            if (piece->getPositionX() < Director::getInstance()->getVisibleSize().width / 2)
//                player1Alive++;
//            else
//                player2Alive++;
//        }
//    }
//
//    return player1Alive == 0 || player2Alive == 0;
//}
//
//void GameScene::endGame()
//{
//    // ��Ϸ�����߼�
//    // ...

//}

