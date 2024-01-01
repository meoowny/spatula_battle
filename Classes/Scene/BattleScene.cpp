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

    auto dirs = Director::getInstance()->getRunningScene();
    Size visibleSize = Director::getInstance()->getVisibleSize();


    /*auto myPlayer = dynamic_cast<Player*>(this->getChildByName("player1"));
    auto oppoPlayer = dynamic_cast<Player*>(this->getChildByName("player2"));*/
    int i = 0, j = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (playerInfo1->_battlingLegends[i][j] == NULL)
            {
                chessBoard[j][i] = emptyFlag;
            }
            else
            {
                chessBoard[j][i] = myFlag;
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (playerInfo2->_battlingLegends[i][j] == NULL)
            {
                chessBoard[6 - j][5 - i] = emptyFlag;
            }
            else
            {
                chessBoard[6 - j][5 - i] = enemyFlag;
            }
        }
    }

    /*
    /*for (auto& legend_i : myPlayer->getBattlingLegends()) {
        j = 0;
        for (auto& legend_j : legend_i) {
            if (legend_j == nullptr) {
                chessBoard[i][j] = emptyFlag;
                j++;
                continue;
            }
            chessBoard[i][j] = myFlag;
            j++;
        }
        i++;
    }*/
    /*i = 0, j = 0;
    for (auto& legend_i : oppoPlayer->getBattlingLegends()) {
        j = 0;*/
       /* for (auto& legend_j : legend_i) {

            if (legend_j == nullptr) {
                chessBoard[i][j + battleBoardHeight] = emptyFlag;
                j++;
                continue;
            }
            chessBoard[i][j + battleBoardHeight] = enemyFlag;
            j++;
        }*/
   /*     i++;
    }*/
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

    //显示我方小小英雄
    displayMyPlayer();

    //显示对方小小英雄
    displayOppoPlayer();

    //显示我方备战区英雄
    displayMyPrepareLegend();

    //显示我方战斗区英雄
    displayMyBattleLegend();

    //显示对方备战区英雄
    displayOppoPrepareLegend();

    //显示对方战斗区英雄
    displayOppoBattleLegend();

    //开始战斗
     schedule(CC_SCHEDULE_SELECTOR(BattleScene::performBattlingLogic), 1.0f);


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
        oppoPlayer->setPosition(Vec2(visibleSize.width / 2 + visibleSize.width / 3 + offset_x, visibleSize.height - visibleSize.height / 2.8 + offset_y));//坐标不改  苦苦算出来的。。。
        this->addChild(oppoPlayer, 3);
    }
}

void BattleScene::displayOppoPrepareLegend()
{
    //待修改
    auto dirs = Director::getInstance()->getRunningScene();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto player = dynamic_cast<Player*>(this->getChildByName("player2"));
    if (player == nullptr) {
        exit(0);
    }

    std::string id = "a";
    int count = 0;
    for (auto i : player->getPreparedLegends()) {
        // TODO: 英雄 setName 待规范，LegendInfo 的任务，暂时使用序号作为测试
        if (i == nullptr)
            continue;
        auto legend = Legend::create(i);
        if (legend == nullptr) {
            problemLoading(legend->getImagePath());
        }
        else {
            legend->setName(id);
            legend->setPosition(Vec2(visibleSize.width / 1.5 - count * 70, visibleSize.height / 1.15));//坐标不改  苦苦算出来的。。。
            addChild(legend);
            //displayHP(legend);
            id[0] = 'a' + count;
            count++;


            //血条
            //healthBar = ProgressTimer::create(Sprite::create("health_bar.png"));
            //healthBar->setType(ProgressTimer::Type::BAR);
            //healthBar->setMidpoint(Vec2(0, 0.5));
            //healthBar->setBarChangeRate(Vec2(1, 0));
            //healthBar->setPosition(Vec2(0, sprite->getContentSize().height / 2 + 10));           
            //int currentHP=getHealth();) {         
             //   healthBar->setPercentage(currentHP / totalHP * 100);
            //}
        }
    }
}

void BattleScene::displayOppoBattleLegend()
{
    //待修改
    auto dirs = Director::getInstance()->getRunningScene();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto player = dynamic_cast<Player*>(this->getChildByName("player2"));
    if (player == nullptr) {
        exit(0);
    }

    std::string id = "A";
    int count = 0;
    for (auto i : player->getBattlingLegends()) {
        // TODO: 英雄 setName 待规范，LegendInfo 的任务，暂时使用序号作为测试
        for (auto& j : i) {
            if (j == nullptr)
                continue;
            auto legend = Legend::create(j);
            if (legend == nullptr) {
                problemLoading(legend->getImagePath());
            }
            else {
                legend->setName(id);
                legend->setPosition(Vec2(visibleSize.width-(visibleSize.width / 3.6 + count / battleBoardHeight * chessboardCellWidth)-50, visibleSize.height / 2.9 + count % battleBoardHeight * chessboardCellHeight + chessboardCellHeight * 3));
                addChild(legend);
                //displayHP(legend);
                id[0] = 'A' + count;
                count++;


                //血条
                //healthBar = ProgressTimer::create(Sprite::create("health_bar.png"));
                //healthBar->setType(ProgressTimer::Type::BAR);
                //healthBar->setMidpoint(Vec2(0, 0.5));
                //healthBar->setBarChangeRate(Vec2(1, 0));
                //healthBar->setPosition(Vec2(0, sprite->getContentSize().height / 2 + 10));           
                //int currentHP=getHealth();) {         
                 //   healthBar->setPercentage(currentHP / totalHP * 100);
                //}
            }
        }
    }
}

void BattleScene::performBattlingLogic(float delta)
{
    // 检查游戏结束条件
    //    if (isGameOver())
    //    {
    //        // 游戏结束逻辑
    //    }



    /*Size visibleSize = Director::getInstance()->getVisibleSize();
    auto dirs = Director::getInstance()->getRunningScene();
    auto myPlayer = dynamic_cast<Player*>(this->getChildByName("player1"));
    if (myPlayer == nullptr) {
        exit(0);
    }*/

    //将己方英雄移动到指定位置
    /*auto legend1= dynamic_cast<Legend*>(this->getChildByName("n"));
    if (legend1 != NULL)
    {
        cocos2d::MoveTo* moveTo = cocos2d::MoveTo::create(2.0, { 700.0,700.0 });
        legend1->runAction(moveTo);
    }
    auto legend2 = dynamic_cast<Legend*>(this->getChildByName("p"));
    if (legend2 != NULL)
    {
        cocos2d::MoveTo* moveTo = cocos2d::MoveTo::create(2.0, { 800.0,700.0 });
        legend2->runAction(moveTo);
    }
    auto legend3 = dynamic_cast<Legend*>(this->getChildByName("q"));
    if (legend3 != NULL)
    {
        cocos2d::MoveTo* moveTo = cocos2d::MoveTo::create(2.0, { 900.0,700.0 });
        legend3->runAction(moveTo);
    }*/


    //将对方英雄移动到指定位置
    /*auto legend4 = dynamic_cast<Legend*>(this->getChildByName("A"));
    if (legend4 != NULL)
    {
        cocos2d::MoveTo* moveTo = cocos2d::MoveTo::create(2.0, { 700.0,750.0 });
        legend4->runAction(moveTo);
    }
    auto legend5 = dynamic_cast<Legend*>(this->getChildByName("B"));
    if (legend5 != NULL)
    {
        cocos2d::MoveTo* moveTo = cocos2d::MoveTo::create(2.0, { 800.0,750.0 });
        legend5->runAction(moveTo);
    }
    auto legend6 = dynamic_cast<Legend*>(this->getChildByName("C"));
    if (legend6 != NULL)
    {
        cocos2d::MoveTo* moveTo = cocos2d::MoveTo::create(2.0, { 900.0,750.0 });
        legend6->runAction(moveTo);
    }*/
   



    //int count = 0;
    //for (auto& i : myPlayer->getBattlingLegends()) {
    //    for (auto& j : i) {
    //        // TODO: 英雄 setName 待规范，LegendInfo 的任务，暂时使用序号作为测试
    //        if (j == nullptr)
    //            continue;
    //        auto legend = Legend::create(j);
    //        if (legend == nullptr) {
    //            problemLoading(legend->getImagePath());
    //        }
    //        else {
    //            // 若在攻击范围内，则进行攻击
    //            //if(opponentLegendInRange(i-(myPlayer->getPreparedLegends().begin(),legend->y))
    //            //{

    //                //  int attackDamage=getAttack();
    //                // beingAttack(attackDamage);
    //       
    //            //}

    //            //否则进行移动
    //       
    //        /*Vec2 destination = findMovePath(legend->x, legend->y);
    //        piece->moveTo(destination);*/
    //        

    //            legend->setName("0");
    //            addChild(legend);
    //            count++;
    //        }
    //    }
    //}
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //判断一个位置是否有棋子，如果有，就发动攻击
    auto attacker = Sprite::create("Plants/Sun/Sun_0.png");
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (chessBoard[i][j] != emptyFlag)
            {
                attacker->setPosition(Vec2(visibleSize.width / 3.6 + i * chessboardCellWidth, visibleSize.height / 2.9 + j * chessboardCellHeight));
                addChild(attacker,2);
                MoveTo* moveToMiddle = MoveTo::create(2, { visibleSize.width / 2,visibleSize.height / 2 });
                attacker->runAction(moveToMiddle);


            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 3; j < 6; j++)
        {
            if (chessBoard[i][j] != emptyFlag)
            {
                auto attacker = Sprite::create("sliderNode_Press.png");
                attacker->setPosition(Vec2(visibleSize.width / 3.6 + i * chessboardCellWidth, visibleSize.height / 2.9 + j * chessboardCellHeight));
                addChild(attacker, 2);
                MoveTo* moveToMiddle = MoveTo::create(2, { visibleSize.width / 2,visibleSize.height / 2 });
                attacker->runAction(moveToMiddle);


            }
        }
    }
}

bool BattleScene::opponentLegendInRange(int x, int y, int range) {
    for (int i = -range; i <= range; i++) {
        for (int j = -range; j <= range; j++) {
            int newX = x + i;
            int newY = y + j;
            if (isValidPosition(newX, newY) && chessBoard[newX][newY] == enemyFlag) {
                return true;
            }
        }
    }
    return false;
}

bool BattleScene::isValidPosition(int x, int y) 
{
    return x >= 0 && x < battleBoardWidth && y >= 0 && y < battleBoardHeight * 2;
}

double BattleScene::calculateDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

Vec2 BattleScene::findMovePath(int x, int y,int Flag) {
    //离自己最近的对方英雄的位置
    int dst_x = x;
    int dst_y = y;
    double minDistance = INT_MAX;

    for (int i = 0; i < battleBoardWidth; i++) {
        for (int j = 0; j < battleBoardHeight * 2; j++) {
            if (chessBoard[i][j] == enemyFlag) {
                double distance = calculateDistance(x, y, i, j);
                if (distance < minDistance) {
                    minDistance = distance;
                    dst_x = i;
                    dst_y = j;
                }
            }
        }
    }

    //移动的方向
    int dir_x = 0;
    int dir_y = 0;
    dir_x = (dst_x > x) ? 1 : ((dst_x < x) ? -1 : 0);
    dir_y = (dst_y > y) ? 1 : ((dst_y < y) ? -1 : 0);
 
    Vec2 movePath(x + dir_x, y + dir_y);

    chessBoard[x][y] = emptyFlag;
    chessBoard[x + dir_x][y + dir_y] = Flag;

    return movePath;
}


//
//void GameScene::checkCollisions()
//{
//
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

