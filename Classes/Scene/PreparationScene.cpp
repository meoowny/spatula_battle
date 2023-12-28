#include "PreparationScene.h"

Scene* PreparationScene::createScene(PlayerInfo* playerInfo)
{
    return PreparationScene::create(playerInfo);
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool PreparationScene::init()
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
    displayStoreLegend();

    //显示我方小小英雄
    displayMyPlayer();

    //显示我方备战区英雄
    displayMyPrepareLegend();

    //显示我方战斗区英雄
    displayMyBattleLegend();

    //显示棋盘
    displayBoard();

    // 添加鼠标监听器
    auto listener = EventListenerMouse::create();
    listener->onMouseDown = CC_CALLBACK_1(PreparationScene::onMouseDown, this);
    listener->onMouseMove = CC_CALLBACK_1(PreparationScene::onMouseMove, this);
    listener->onMouseUp = CC_CALLBACK_1(PreparationScene::onMouseUp, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
   
    //开始倒计时
    countdown();
    return true;
}

//鼠标按下的回调函数
void PreparationScene::onMouseDown(EventMouse* event)
{
    selectedSprite = selectLegend(event);
    //如果有英雄被选中，才显示棋盘
    if (selectedSprite) {
        for (int i = 0; i < battleBoardWidth; i++) {
            for (int j = 0; j < battleBoardHeight; j++) {
                battleChessboard[i][j]->setVisible(true);
            }
        }
        for (int i = 0; i < preparationSize; i++) {
            preparationChessboard[i]->setVisible(true);
        }
    }
}

//鼠标移动的回调函数
void PreparationScene::onMouseMove(EventMouse* event)
{
    dragLegend(event, selectedSprite);
    boardCellSelected(event);  
}

//显示棋盘
void PreparationScene::displayBoard()
{
    //战斗区
    Size visibleSize = Director::getInstance()->getVisibleSize();
    for (int i = 0; i < battleBoardWidth; i++) {
        for (int j = 0; j < battleBoardHeight; j++) {
            auto chessboardCell = Sprite::create("chessboardCell.png");           
            battleChessboard[i][j] = chessboardCell;
            chessboardCell->setPosition(Vec2(visibleSize.width / 3.6 + i * chessboardCellWidth, visibleSize.height / 2.9 + j * chessboardCellHeight));
            chessboardCell->setScale(0.1);
            addChild(chessboardCell, 0);
            chessboardCell->setVisible(false);

            auto chessboardCellSelected = Sprite::create("chessboardCellSelected.png");
            battleSelectedChessboard[i][j] = chessboardCellSelected;
            chessboardCellSelected->setPosition(Vec2(visibleSize.width / 3.6 + i * chessboardCellWidth, visibleSize.height / 2.9 + j * chessboardCellHeight));
            chessboardCellSelected->setScale(0.1);
            addChild(chessboardCellSelected, 0);
            chessboardCellSelected->setVisible(false);
            
        }
    }
    //备战区
    for (int i = 0; i < preparationSize; i++) {
        auto chessboardCell = Sprite::create("chessboardCell.png");      
        preparationChessboard[i] = chessboardCell;
        chessboardCell->setPosition(Vec2(visibleSize.width / 4.8 + i * chessboardCellWidth, visibleSize.height / 4));
        chessboardCell->setScale(0.1);
        addChild(chessboardCell, 0);
        chessboardCell->setVisible(false);

        auto chessboardCellSelected = Sprite::create("chessboardCellSelected.png");
        preparationSelectedChessboard[i] = chessboardCellSelected;
        chessboardCellSelected->setPosition(Vec2(visibleSize.width / 4.8 + i * chessboardCellWidth, visibleSize.height / 4));
        chessboardCellSelected->setScale(0.1);
        addChild(chessboardCellSelected, 0);
        chessboardCellSelected->setVisible(false);
    }
}

//棋盘回显
void PreparationScene::boardCellSelected(EventMouse* event)
{
    if (selectedSprite)
    {
        Vec2 mouseLocation(event->getCursorX(), event->getCursorY());
        for (int i = 0; i < battleBoardWidth; i++) {
            for (int j = 0; j < battleBoardHeight; j++) {
                Rect targetRect = battleSelectedChessboard[i][j]->getBoundingBox();
                if (targetRect.containsPoint(mouseLocation))
                {
                    battleSelectedChessboard[i][j]->setVisible(true);
                }
                else {
                    battleSelectedChessboard[i][j]->setVisible(false);
                }
            }
        }

        for (int i = 0; i < preparationSize; i++) {
            Rect targetRect = preparationSelectedChessboard[i]->getBoundingBox();
            if (targetRect.containsPoint(mouseLocation))
            {
                preparationSelectedChessboard[i]->setVisible(true);
            }
            else {
                preparationSelectedChessboard[i]->setVisible(false);
            }
        }
    }
}

void PreparationScene::onMouseUp(EventMouse* event)
{
    if (selectedSprite)
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 mouseLocation(event->getCursorX(), event->getCursorY());

        //当鼠标松开后，棋盘不再显示
        for (int i = 0; i < battleBoardWidth; i++) {
            for (int j = 0; j < battleBoardHeight; j++) {
                battleChessboard[i][j]->setVisible(false);
                battleSelectedChessboard[i][j]->setVisible(false);
            }
        }

        for (int i = 0; i < preparationSize; i++) {
            preparationChessboard[i]->setVisible(false);
            preparationSelectedChessboard[i]->setVisible(false);
        }

        // 判断是否在指定区域内
        bool isInBoard = false;

        for (int i = 0; i < battleBoardWidth; i++) {
            for (int j = 0; j < battleBoardHeight; j++) {
                Rect targetRect= battleChessboard[i][j]->getBoundingBox();
                if (targetRect.containsPoint(mouseLocation))
                {
                    // 移动到指定区域的中心
                    selectedSprite->setPosition(targetRect.getMidX(), targetRect.getMidY());
                    isInBoard = true;
                    break;
                }
               
                 //否则回到初始位置
                auto it = std::find(sprites.begin(), sprites.end(), selectedSprite);
                if (it != sprites.end()) {
                    int position = std::distance(sprites.begin(), it);
                    selectedSprite->setPosition(Vec2(visibleSize.width / 4.8 + i * chessboardCellWidth, visibleSize.height / 4));
                }
            }
            if (isInBoard) break;
        }

     
        for (int i = 0; i < preparationSize; i++) {
            if (!isInBoard) {
                Rect targetRect = preparationChessboard[i]->getBoundingBox();
                if (targetRect.containsPoint(mouseLocation))
                {
                    // 移动到指定区域的中心
                    selectedSprite->setPosition(targetRect.getMidX(), targetRect.getMidY());
                    isInBoard = true;
                    break;
                }

                //否则回到初始位置
                auto it = std::find(sprites.begin(), sprites.end(), selectedSprite);
                if (it != sprites.end()) {
                    int position = std::distance(sprites.begin(), it);
                    selectedSprite->setPosition(Vec2(visibleSize.width / 4.8 + position * 100, visibleSize.height / 4));
                }
            }
        }
        
        // 重置选中的精灵
        selectedSprite = nullptr;
    }
}