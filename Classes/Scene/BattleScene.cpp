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
    //        //我方英雄
    //        if (j < battleBoardHeight) {

    //        }
    //        //对方英雄
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

    //显示背景
    displayBackground();

    //显示商店
    displayStore();

    //显示购买经验值按钮
    displayBuyButton();

    //显示刷新按钮
    displayRefreshButton();

    //显示商店英雄卡牌
    /*displayStoreLegend();*/

    //显示我方小小英雄
    displayMyPlayer();

    //显示对方小小英雄
    displayOppoPlayer();

    //显示我方备战区英雄
    displayMyPrepareLegend();

    //显示我方战斗区英雄
    displayMyBattleLegend();

    //显示对方备战区英雄
    //displayOppoPrepareLegend();

    //显示对方战斗区英雄
    //displayOppoBattleLegend();

    //开始战斗
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
    // 检查游戏结束条件
    //    if (isGameOver())
    //    {
    //        // 游戏结束逻辑
    //    }


    auto dirs = Director::getInstance()->getRunningScene();
    auto myPlayer = dynamic_cast<Player*>(this->getChildByName("player1"));
    if (myPlayer == nullptr) {
        exit(0);
    }

    int count = 0;
    for (auto i : myPlayer->getPreparedLegends()) {
        // TODO: 英雄 setName 待规范，LegendInfo 的任务，暂时使用序号作为测试
        if (i == nullptr)
            continue;
        auto legend = Legend::create(i);
        if (legend == nullptr) {
            problemLoading(legend->getImagePath());
        }
        else {

            // 移动逻辑
          

        //Vec2 destination = findMovePath(chessBoard);
//        piece->moveTo(destination);





            // 蓝条增加
            // piece->blueBar += delta * 5;  // 假设每秒增加5
            // 蓝条未满时按照一定频率释放普通攻击
//        if (piece->blueBar < piece->maxBlueBar)
//        {
//            // 假设每秒释放一次普通攻击
//            piece->normalAttackCooldown -= delta;
//            if (piece->normalAttackCooldown <= 0)
//            {
//                piece->normalAttack();
//                piece->normalAttackCooldown = piece->maxNormalAttackCooldown;
//            }
//        }
//        else
//        {
//            // 蓝条满时释放大招
//            piece->ultimateAttack();
//            piece->blueBar = 0;  // 清空蓝条
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
//    // 简化处理，假设两个角色碰撞时，进行战斗，减少对方血量
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
//    // 检查游戏结束条件
//    if (isGameOver())
//    {
//        // 游戏结束逻辑
//        endGame();
//    }
//}
//
//bool GameScene::isGameOver()
//{
//    // 简化处理，假设游戏结束条件是某一方全部角色的血量清零
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
//    // 游戏结束逻辑
//    // ...

//}

