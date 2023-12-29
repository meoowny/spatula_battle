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

    //auto dirs = Director::getInstance()->getRunningScene();
    //Size visibleSize = Director::getInstance()->getVisibleSize();


    auto myPlayer = dynamic_cast<Player*>(this->getChildByName("player1"));
    auto oppoPlayer = dynamic_cast<Player*>(this->getChildByName("player2"));
    int i = 0, j = 0;
    for (auto& legend_i : myPlayer->getBattlingLegends()) {
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
    }
    i = 0, j = 0;
    for (auto& legend_i : oppoPlayer->getBattlingLegends()) {
        for (auto& legend_j : legend_i) {
            if (legend_j == nullptr) {
                chessBoard[i][j] = emptyFlag;
                continue;
            }
            chessBoard[i+battleBoardHeight][j] = enemyFlag;
            j++;
        }
        i++;
    }
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

    //��ʾ�ҷ�ССӢ��
    displayMyPlayer();

    //��ʾ�Է�ССӢ��
    displayOppoPlayer();

    //��ʾ�ҷ���ս��Ӣ��
    displayMyPrepareLegend();

    //��ʾ�ҷ�ս����Ӣ��
    displayMyBattleLegend();

    //��ʾ�̵�Ӣ�ۿ���
    /*displayStoreLegend();*/

    //��ʾ�Է���ս��Ӣ��
    displayOppoPrepareLegend();

    //��ʾ�Է�ս����Ӣ��
    //displayOppoBattleLegend();

    //��ʼս��
    // schedule(CC_SCHEDULE_SELECTOR(BattleScene::performBattlingLogic), 1.0f);



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
        oppoPlayer->setPosition(Vec2(visibleSize.width / 2 + visibleSize.width / 3 + offset_x, visibleSize.height - visibleSize.height / 2.8 + offset_y));//���겻��  ���������ġ�����
        this->addChild(oppoPlayer, 3);
    }
}

void BattleScene::displayOppoPrepareLegend()
{
    //���޸�
    auto dirs = Director::getInstance()->getRunningScene();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto player = dynamic_cast<Player*>(this->getChildByName("player2"));
    if (player == nullptr) {
        exit(0);
    }

    std::string id = "0";
    int count = 0;
    for (auto i : player->getPreparedLegends()) {
        // TODO: Ӣ�� setName ���淶��LegendInfo ��������ʱʹ�������Ϊ����
        if (i == nullptr)
            continue;
        auto legend = Legend::create(i);
        if (legend == nullptr) {
            problemLoading(legend->getImagePath());
        }
        else {
            legend->setName(id);
            legend->setPosition(Vec2(visibleSize.width / 1.5 - count * 70, visibleSize.height / 1.15));//���겻��  ���������ġ�����
            addChild(legend);
            id += '0' + count;
            count++;


            //Ѫ��
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
    for (auto& i : myPlayer->getBattlingLegends()) {
        for (auto& j : i) {
            // TODO: Ӣ�� setName ���淶��LegendInfo ��������ʱʹ�������Ϊ����
            if (j == nullptr)
                continue;
            auto legend = Legend::create(j);
            if (legend == nullptr) {
                problemLoading(legend->getImagePath());
            }
            else {
                // ���ڹ�����Χ�ڣ�����й���
                //if(opponentLegendInRange(i-(myPlayer->getPreparedLegends().begin(),legend->y))
                //{

                    //  int attackDamage=getAttack();
                    // beingAttack(attackDamage);
                //}

                //��������ƶ�
            //else{
            //Vec2 destination = findMovePath(legend->x,legend->y);
            //piece->moveTo(destination);
            //}

                legend->setName("0");
                addChild(legend);
                count++;
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
    //���Լ�����ĶԷ�Ӣ�۵�λ��
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

    //�ƶ��ķ���
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

