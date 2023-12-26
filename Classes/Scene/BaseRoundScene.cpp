#include "BaseRoundScene.h"

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

//显示背景
void BaseRoundScene::displayBackground()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto preparationBackground = Sprite::create("PreparationBackground.jpg");
    if (preparationBackground == nullptr)
    {
        problemLoading("'PreparationBackground.jpg'");
    }
    else
    {
        preparationBackground->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
        preparationBackground->setScaleX(1.8);
        preparationBackground->setScaleY(2.5);
        addChild(preparationBackground, 0);
    }
}

//显示商店
void BaseRoundScene::displayStore()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto store = Sprite::create("Store.jpg");
    if (store == nullptr)
    {
        problemLoading("'Store.jpg'");
    }
    else
    {
        store->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 12));
        store->setScale(2.2);
        addChild(store, 1);
    }
}

//显示购买经验值按钮
void BaseRoundScene::displayBuyButton()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //如果未达到满级，则创建按钮


    /*

     if判断   待修改



    */



    if (true) {
        auto buyExperienceButton = Button::create("BuyExperienceButton.jpg");
        buyExperienceButton->setScale(2.2);
        buyExperienceButton->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 2.62, visibleSize.height / 12 + 45));
        buyExperienceButton->addClickEventListener(CC_CALLBACK_1(BaseRoundScene::buyButtonClickCallback, this));
        addChild(buyExperienceButton, 2);
    }
    //否则不能点击升级
    else {
        auto canNotBuyExperienceButton = Sprite::create("CanNotBuyExperienceButton.jpg");
        if (canNotBuyExperienceButton == nullptr)
        {
            problemLoading("'CanNotBuyExperienceButton.jpg'");
        }
        else
        {
            canNotBuyExperienceButton->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 2.62, visibleSize.height / 12 + 45));
            canNotBuyExperienceButton->setScale(2.2);
            addChild(canNotBuyExperienceButton, 2);
        }
    }
}

// 显示刷新按钮
void BaseRoundScene::displayRefreshButton()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //如果金币还有剩余，则创建按钮



     /*

     if判断   待修改



    */



    if (true) {
        auto refreshButton = Button::create("RefreshButton.jpg");
        refreshButton->setScale(2.2);
        refreshButton->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 2.62, visibleSize.height / 12 - 45));
        refreshButton->addClickEventListener(CC_CALLBACK_1(BaseRoundScene::refreshButtonClickCallback, this));
        addChild(refreshButton, 2);
    }
    //否则不能点击刷新
    else {
        auto canNotRefreshButton = Sprite::create("CanNotRefreshButton.jpg");
        if (canNotRefreshButton == nullptr)
        {
            problemLoading("'CanNotRefreshButton.jpg'");
        }
        else
        {
            canNotRefreshButton->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 2.62, visibleSize.height / 12 - 45));
            canNotRefreshButton->setScale(2.2);
            addChild(canNotRefreshButton, 2);
        }
    }
}

//显示商店英雄卡牌
void BaseRoundScene::displayStoreLegend()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();




    // for()






    auto StoreLegend = Button::create("Peashooter_0.png", "Peashooter_0.png", "Peashooter_1.png");
    StoreLegend->setScale(2.2);
    StoreLegend->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 4, visibleSize.height / 12));
    StoreLegend->addClickEventListener(CC_CALLBACK_1(BaseRoundScene::buyLegendCallback, this));
    addChild(StoreLegend, 2);




}

//显示备战区英雄
void BaseRoundScene::displayPrepareLegend()
{

    //测试用

    //待修改
    Size visibleSize = Director::getInstance()->getVisibleSize();
    for (int i = 0; i < 9; i++) {
        Sprite* preparationBackground = Sprite::create("Peashooter_0.png");
        if (preparationBackground == nullptr)
        {
            problemLoading("'Peashooter_0.png'");
        }
        else
        {
            sprites.push_back(preparationBackground);
            preparationBackground->setPosition(Vec2(visibleSize.width / 4.8 + i * 100, visibleSize.height / 4));
            //preparationBackground->setScale(5);
            addChild(preparationBackground, 0);
        }
    }

}

//显示战斗区英雄
void BaseRoundScene::displayBattleLegend()
{

}

//显示我方小小英雄
void BaseRoundScene::displayMyPlayer()
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
    //添加鼠标监听器
    auto listener = EventListenerMouse::create();
    listener->onMouseDown = CC_CALLBACK_1(BaseRoundScene::moveMyPlayer, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void BaseRoundScene::selectLegend(EventMouse* event)
{
    for (auto sprite : sprites)
  {
      if (sprite->getBoundingBox().containsPoint(Vec2(event->getCursorX(), event->getCursorY())))
      {
          // 记录当前被点击的精灵
          selectedSprite = sprite;
          break;
      }
  }
}

void BaseRoundScene::dragLegend(EventMouse* event)
{
    if (selectedSprite)
   {
       // 移动被选中的精灵
       selectedSprite->setPosition(Vec2(event->getCursorX(), event->getCursorY()));
   }
}

//移动小小英雄回调函数
void BaseRoundScene::moveMyPlayer(EventMouse* event)
{
    if (event->getMouseButton() != EventMouse::MouseButton::BUTTON_RIGHT) {
        return;
    }
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

//购买经验值按钮回调函数
void BaseRoundScene::buyButtonClickCallback(Ref* pSender)
{
    //玩家升级经验

    // ...

    //displayBuyButton();
}

//刷新按钮回调函数
void BaseRoundScene::refreshButtonClickCallback(Ref* pSender)
{
    //  传给玩家类  需要重新获取英雄卡牌信息

    //  ...

    //displayRefreshButton();
}

//购买英雄回调函数
void BaseRoundScene::buyLegendCallback(Ref* pSender)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //一、首先判断钱够不够

    //return;

    //二、其次判断备战区是否已满

    //return;

    //三。然后判断买入后是否存在三个一样的英雄  如果有 要进行升级



    //四、然后，才在备战区添加一位英雄
    auto prepareLegend = Sprite::create("HelloWorld.png");
    prepareLegend->setScale(2.2);
    prepareLegend->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 4, visibleSize.height / 10));
    /*refreshButton->addClickEventListener(CC_CALLBACK_1(PreparationScene::buyLegendCallback, this));*/
    addChild(prepareLegend, 2);

    // 点击后设置按钮为不可点击状态
    auto button = dynamic_cast<Button*>(pSender);
    if (button) {
        button->setTouchEnabled(false);
        button->setEnabled(false);
    }
}

//开始倒计时
void BaseRoundScene::countdown()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //开始倒计时，设置为1分钟
    int totalTimeInSeconds = 60;
    remainingTimeInSeconds = totalTimeInSeconds;

    // 在屏幕上创建一个标签用于显示剩余时间
    labelRemainTime = Label::createWithTTF("Time: 01:00", "fonts/arial.ttf", 24);
    labelRemainTime->setScale(4);
    labelRemainTime->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 50));
    this->addChild(labelRemainTime);

    // 启动倒计时定时器
    schedule(CC_SCHEDULE_SELECTOR(BaseRoundScene::updateTimerCallback), 1.0f, kRepeatForever, 0);

}

// 定时器回调函数，用于更新剩余时间
void BaseRoundScene::updateTimerCallback(float dt)
{
    /* 创建蓝条
        auto blueBar = DrawNode::create();
    blueBar->drawSolidRect(Vec2(origin.x, visibleSize.height - 50), Vec2(origin.x + visibleSize.width, visibleSize.height), Color4F::BLUE);
    this->addChild(blueBar);*/

    //float totalTime = 60.0f; // 总时间（以秒为单位）
    //float decreaseRate = 1.0f; // 每秒减少的长度

    //float initialWidth = visibleSize.width; // 初始蓝条长度
    //float currentWidth = initialWidth; // 当前蓝条长度

    //this->schedule([=](float dt) mutable {
    //    float decreaseAmount = decreaseRate * dt; // 计算当前帧应该减少的长度
    //    currentWidth -= decreaseAmount; // 更新当前长度

    //    if (currentWidth < 0.0f) {
    //        currentWidth = 0.0f; // 确保长度不为负数
    //    }

    //    blueBar->clear(); // 清除之前的绘制
    //    blueBar->drawSolidRect(Vec2(origin.x, visibleSize.height - 50), Vec2(origin.x + currentWidth, visibleSize.height), Color4F::BLUE);
    //    }, 1.0f, "decrease_bar"); // 每秒执行一次









    if (remainingTimeInSeconds > 0) {
        remainingTimeInSeconds--;

        // 计算分钟和秒钟
        int minutes = remainingTimeInSeconds / 60;
        int seconds = remainingTimeInSeconds % 60;

        // 更新显示剩余时间的标签
        labelRemainTime->setString(StringUtils::format("Time: %02d:%02d", minutes, seconds));
    }
    else {
        // 时间结束，切换到另一个场景
        unschedule(CC_SCHEDULE_SELECTOR(BaseRoundScene::updateTimerCallback));
        //switchToNextScene();
        //Director::getInstance()->popScene();
    }
}
