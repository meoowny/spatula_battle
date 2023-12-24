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

    //显示小小英雄
    displayPlayer();

    // 添加鼠标监听器
    auto listener = EventListenerMouse::create();
    listener->onMouseDown = CC_CALLBACK_1(PreparationScene::onMouseDown, this);
    listener->onMouseMove = CC_CALLBACK_1(PreparationScene::onMouseMove, this);
    listener->onMouseUp = CC_CALLBACK_1(PreparationScene::onMouseUp, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    //开始倒计时，设置为1分钟
    countdown();
    return true;
}

//显示小小英雄
void PreparationScene::displayPlayer()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();

    myPlayer = Sprite::create("Peashooter_0.png");
    if (myPlayer == nullptr)
    {
        problemLoading("'Peashooter_0.png'");
    }
    else
    {
        myPlayer->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 2.55, visibleSize.height / 3.2));
        addChild(myPlayer, 3);
    }
}

void PreparationScene::onMouseDown(EventMouse* event)
{
    EventMouse::MouseButton button = event->getMouseButton();
    if (button == EventMouse::MouseButton::BUTTON_LEFT)
    {
        mouseLeftClick(event);
    }
    if (button == EventMouse::MouseButton::BUTTON_RIGHT)
    {
        mouseRightClick(event);
    }
}

void PreparationScene::mouseLeftClick(EventMouse* event)
{
    //for (auto sprite : sprites)
  //{
  //    if (sprite->getBoundingBox().containsPoint(Vec2(event->getCursorX(), event->getCursorY())))
  //    {
  //        // 记录当前被点击的精灵
  //        selectedSprite = sprite;

  //        /*offset = event->getLocation() - selectedSprite->getPosition();*/
  //        break;
  //    }
  //}
}

void PreparationScene::mouseRightClick(EventMouse* event)
{
    auto dirs = Director::getInstance()->getRunningScene();
    // 获取鼠标点击的目标位置
    Vec2 targetPosition = Vec2(event->getCursorX(), event->getCursorY());

    Size visibleSize = Director::getInstance()->getVisibleSize();
    targetPosition.x = clampf(targetPosition.x, visibleSize.width / 2 - visibleSize.width / 2.5, visibleSize.width / 2 + visibleSize.width / 2.5);
    targetPosition.y = clampf(targetPosition.y, visibleSize.height / 2 - visibleSize.height / 5, visibleSize.height / 2 + visibleSize.height / 5 + 50);

    // 计算精灵移动的时间
    float duration = 1.0f;

    // 创建精灵的运动动作
    auto moveAction = MoveTo::create(duration, targetPosition);
    myPlayer->runAction(moveAction);

    myPlayer->stopAllActions();    // 停止之前的动作
    myPlayer->runAction(moveAction);
}

void PreparationScene::onMouseMove(EventMouse* event)
{
    //if (selectedSprite)
    //{
    //    // 移动被选中的精灵
    //    selectedSprite->setPosition(Vec2(event->getCursorX(), event->getCursorY())/*- offset*/);
    //}
}

void PreparationScene::onMouseUp(EventMouse* event)
{
    //if (selectedSprite)
    //{
    //    // 判断是否在指定区域内
    //    Rect targetRect = Rect(500, 500, 300, 300);

    //    if (targetRect.containsPoint(event->getLocation()))
    //    {
    //        // 移动到指定区域的中心
    //        selectedSprite->setPosition(targetRect.getMidX(), targetRect.getMidY());
    //    }
    //    else
    //    {
    //        // 回到初始位置
    //        selectedSprite->setPosition(Vec2(350 * (sprites.getIndex(selectedSprite) + 1) - 200, 200));
    //    }
    //    // 重置选中的精灵
    //    selectedSprite = nullptr;
    //}
}