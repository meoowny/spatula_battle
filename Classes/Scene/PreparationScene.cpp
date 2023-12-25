#include "PreparationScene.h"

Scene* PreparationScene::createScene()
{
    return PreparationScene::create();
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
    /*displayStoreLegend();*/

    //显示备战区英雄
    displayPrepareLegend();

    //显示战斗区英雄
    displayBattleLegend();

    //显示我方小小英雄
    displayMyPlayer();

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
    selectLegend(event);
    //如果有英雄被选中，才显示棋盘
    if (selectedSprite) {
        displayBoard();
    }
}

//鼠标移动的回调函数
void PreparationScene::onMouseMove(EventMouse* event)
{
    dragLegend(event);
}

//显示棋盘
void PreparationScene::displayBoard()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    for (int i = 0; i < boardWidth; i++) {
        for (int j = 0; j < boardHeight; j++) {
            auto chessboardCell = Sprite::create("chessboardCell.png");
            if (chessboardCell == nullptr)
            {
                problemLoading("'chessboardCell.png'");
            }
            else
            {
                chessboard[i][j] = chessboardCell;
                chessboardCell->setPosition(Vec2(visibleSize.width / 3.6 + i * chessboardCellWidth, visibleSize.height / 2.9 + j * chessboardCellHeight));
                chessboardCell->setScale(0.1);
                addChild(chessboardCell, 0);
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

        // 判断是否在指定区域内
        bool isInBoard = false;
        // 判断是否在指定区域内
        for (int i = 0; i < boardWidth; i++) {
            for (int j = 0; j < boardHeight; j++) {           

                //当鼠标松开后，棋盘不再显示
                //if (chessboard[i][j]) {    //这个会报错
                //   chessboard[i][j]->removeFromParentAndCleanup(true);
                //}

                Rect targetRect= chessboard[i][j]->getBoundingBox();               
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
            if (isInBoard) break;
        }
        // 重置选中的精灵
        selectedSprite = nullptr;
    }
}