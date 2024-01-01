#include "BaseRoundScene.h"
#include "Store/Store.h"

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
    auto store = Sprite::create("Store.png");
    if (store == nullptr)
    {
        problemLoading("'Store.png'");
    }
    else
    {
        store->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 12));
        store->setScale(1.65);
        addChild(store, 1);
    }
}

//显示购买经验值按钮
void BaseRoundScene::displayBuyButton()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //如果未达到满级，则创建按钮
    auto dirs = Director::getInstance()->getRunningScene();
    

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
    
    auto st = new Store;
    Vector<LegendInfo*> legendPointer = st->refresh();
    Vector<Button*> storeLegends;
    for (auto info : legendPointer) {
        auto legend = Button::create(info->getCardPath(), "emptyStore.jpg", "emptyStore.jpg");
        legend->addClickEventListener([=](Ref* pSender) {
            //这里添加购买英雄的逻辑
            //点击按钮后，对应商店位置英雄被买走，按钮变成不可选择状态，对应玩家类调用购买英雄函数，购买英雄
            auto button = dynamic_cast<ui::Button*>(pSender);
            button->setBright(!button->isBright());
            auto player = dynamic_cast<Player*>(this->getChildByName("player1"));
            player->buyLegend(Legend::create(info));
            displayMyPrepareLegend();
            });
        storeLegends.pushBack(legend);
    }

    int gap = 0;
    for (auto storeLegend : storeLegends) {
        //storeLegend->create(StringUtils::format("image%d.png", gap), StringUtils::format("image%d.png", gap), "emptyStore.jpg");
        storeLegend->setPosition(Vec2(visibleSize.width / 3.6 + gap * 230, visibleSize.height / 12));
        storeLegend->setScale(2.0);
        //storeLegend->addClickEventListener(CC_CALLBACK_1(BaseRoundScene::buyLegendCallback, this));
        gap++;
        addChild(storeLegend, 2);
    }

}

//显示我方备战区英雄
void BaseRoundScene::displayMyPrepareLegend()
{
    auto dirs = Director::getInstance()->getRunningScene();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto player = dynamic_cast<Player*>(this->getChildByName("player1"));
    if (player == nullptr) {
        exit(0);
    }

    std::string id = "0";
    int count = 0;
    for (auto i : player->getPreparedLegends()) {
        // TODO: 英雄 setName 待规范，LegendInfo 的任务，暂时使用序号作为测试
        if (i == nullptr) {
            continue;
        }
        auto myPrepareLegend = dynamic_cast<Legend*>(this->getChildByName(id));
        if (myPrepareLegend == nullptr) {
            auto legend = Legend::create(i);
            legend->setName(id);
            legend->setPosition(Vec2(visibleSize.width / 4.8 + count * 100, visibleSize.height / 4));
            addChild(legend);
        }
        else {
            myPrepareLegend->setPosition(Vec2(visibleSize.width / 4.8 + count * 100, visibleSize.height / 4));        
        }
        count++;
        id = '0' + count;
    }
}

////显示我方备战区英雄
//void BaseRoundScene::displayMyPrepareLegend()
//{
//    auto dirs = Director::getInstance()->getRunningScene();
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    auto player = dynamic_cast<Player*>(this->getChildByName("player1"));
//    if (player == nullptr) {
//        exit(0);
//    }
//
//    std::string id = "0";
//    int count = 0;
//    while (true)
//    {
//        auto myPrepareLegend = dynamic_cast<Legend*>(this->getChildByName(id));
//        if (myPrepareLegend != nullptr)
//        {
//            myPrepareLegend->setPosition(Vec2(visibleSize.width / 4.8 + count * 100, visibleSize.height / 4));
//            id = '0' + count;
//            count++;
//        }
//        else break;
//    }
//}

//显示我方战斗区英雄
void BaseRoundScene::displayMyBattleLegend()
{
    //待修改
    auto dirs = Director::getInstance()->getRunningScene();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto player = dynamic_cast<Player*>(this->getChildByName("player1"));
    if (player == nullptr) {
        exit(0);
    }

    std::string id = "0";
    int count = 0;
    for (auto& i : player->getBattlingLegends()) {
        for (auto& j : i) {
            // TODO: 英雄 setName 待规范，LegendInfo 的任务，暂时使用序号作为测试
            if (j == nullptr)
                continue;
            auto legend = Legend::create(j);
            if (legend == nullptr) {
                problemLoading(legend->getImagePath());
            }
            else {
                legend->setName(id);
                legend->setPosition(Vec2(visibleSize.width / 3.6 + count / battleBoardHeight * chessboardCellWidth, visibleSize.height / 2.9 + count % battleBoardHeight * chessboardCellHeight));
                addChild(legend);
                id += '0' + count;
                count++;
            }
        }
    }
}

//显示我方小小英雄
void BaseRoundScene::displayMyPlayer()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto dirs = Director::getInstance()->getRunningScene();
    auto myPlayer = Player::create(_playerInfo1);
    if (myPlayer == nullptr)    {
        problemLoading(myPlayer->getResourceName().c_str());
    }
    else
    {
        myPlayer->setName("player1");
        myPlayer->setAnchorPoint(Vec2(0.5f, 0.5f));
        myPlayer->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 3, visibleSize.height / 2.8));
        this->addChild(myPlayer, 3);
    }

    auto HP = LoadingBar::create("HP_bar.png");
    HP->setDirection(LoadingBar::Direction::RIGHT);
    HP->setScale(0.4);
    HP->setAnchorPoint(Vec2(0.5, -10));
    HP->setPercent(100);
    //HP->setPosition(Vec2(myPlayer->getContentSize().width / 2, myPlayer->getContentSize().height / 2));
    myPlayer->addChild(HP);
    //添加鼠标监听器
    auto listener = EventListenerMouse::create();
    listener->onMouseDown = CC_CALLBACK_1(BaseRoundScene::moveMyPlayer, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

//显示我方小小英雄金币数量
void BaseRoundScene::displayCoinNumber()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto dirs = Director::getInstance()->getRunningScene();
    auto myPlayer= dynamic_cast<Player*>(this->getChildByName("player1"));
    Label* labelCoins;
    int myCoins = myPlayer->getCoin();
    labelCoins = Label::createWithTTF("My Coins", "fonts/UbuntuNFMono.ttf", 20);
    labelCoins->setName("labelCoins");
    labelCoins->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 12 + 120));
    this->addChild(labelCoins);
    labelCoins->setString(StringUtils::format("My Coins : %d", myCoins));
    this->removeChild(dirs->getChildByName("labelCoins"));
}

LegendWithLocation BaseRoundScene::selectLegend(EventMouse* event)
{
    auto myPlayer=dynamic_cast<Player*>(this->getChildByName("player1"));
    std::string id = "0";
    int count = 0;
    while (true) {
        auto selectedSprite = dynamic_cast<Legend*>(this->getChildByName(id));
        if (selectedSprite != nullptr) {
            if (selectedSprite->getBoundingBox().containsPoint(Vec2(event->getCursorX(), event->getCursorY())))
            {
                selectedSpriteWithLocation.legend = selectedSprite;
                selectedSpriteWithLocation.position = { count,-1 };
                // 记录当前被点击的精灵
                return selectedSpriteWithLocation;
            }
            count++;
            id = "0" + count;
        }
        else break;
    }
    id = "0";
    count = 0;
    while (true) {
        auto selectedSprite = dynamic_cast<Legend*>(this->getChildByName(id));
        if (selectedSprite != nullptr) {
            if (selectedSprite->getBoundingBox().containsPoint(Vec2(event->getCursorX(), event->getCursorY())))
            {
                selectedSpriteWithLocation.legend = selectedSprite;
                selectedSpriteWithLocation.position = { count,-1 };
                // 记录当前被点击的精灵
                return selectedSpriteWithLocation;
            }
            count++;
            id += "0" + count;
        }
        else break;
    }
    //for (auto selectedSprite : dynamic_cast<Legend*>(this->getChildByName(id))) {
    //    if (selectedSprite != nullptr) {
    //        if (selectedSprite->getBoundingBox().containsPoint(Vec2(event->getCursorX(), event->getCursorY())))
    //        {
    //            selectedSpriteWithLocation.legend = selectedSprite;
    //            selectedSpriteWithLocation.position = { i,-1 };
    //            // 记录当前被点击的精灵
    //            return selectedSpriteWithLocation;
    //        }
    //    }
    //    i++;
    //}
    //i = 0; j = 0;
    //for (auto& array : myPlayer->getBattlingLegends()) {
    //    for (auto& selectedSprite : array) {
    //        if (selectedSprite != nullptr) {
    //            if (selectedSprite->getBoundingBox().containsPoint(Vec2(event->getCursorX(), event->getCursorY())))
    //            {
    //                selectedSpriteWithLocation.legend = selectedSprite;
    //                selectedSpriteWithLocation.position = { i,j };
    //                // 记录当前被点击的精灵
    //                return selectedSpriteWithLocation;
    //            }
    //        }
    //        j++;
    //    }
    //    i++;
    //}

    //auto myPlayer=dynamic_cast<Player*>(this->getChildByName("player1"));
    //int i = 0, j = 0;
    //for (auto selectedSprite : myPlayer->getPreparedLegends()) {
    //    if (selectedSprite != nullptr) {
    //        if (selectedSprite->getBoundingBox().containsPoint(Vec2(event->getCursorX(), event->getCursorY())))
    //        {
    //            selectedSpriteWithLocation.legend = selectedSprite;
    //            selectedSpriteWithLocation.position = { i,-1 };
    //            // 记录当前被点击的精灵
    //            return selectedSpriteWithLocation;
    //        }
    //    }
    //    i++;
    //}
    //i = 0; j = 0;
    //for (auto& array : myPlayer->getBattlingLegends()) {
    //    for (auto& selectedSprite : array) {
    //        if (selectedSprite != nullptr) {
    //            if (selectedSprite->getBoundingBox().containsPoint(Vec2(event->getCursorX(), event->getCursorY())))
    //            {
    //                selectedSpriteWithLocation.legend = selectedSprite;
    //                selectedSpriteWithLocation.position = { i,j };
    //                // 记录当前被点击的精灵
    //                return selectedSpriteWithLocation;
    //            }
    //        }
    //        j++;
    //    }
    //    i++;
    //}

    return selectedSpriteWithLocation;
}

void BaseRoundScene::dragLegend(EventMouse* event, LegendWithLocation selectedSpriteWithLocation)
{
    if (selectedSpriteWithLocation.legend)
   {
       // 移动被选中的精灵
        selectedSpriteWithLocation.legend->setPosition(Vec2(event->getCursorX(), event->getCursorY()));
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
    targetPosition.x = clampf(targetPosition.x, visibleSize.width / 2 - visibleSize.width / 3, visibleSize.width / 2 + visibleSize.width / 3 + offset_x);
    targetPosition.y = clampf(targetPosition.y, visibleSize.height / 2.8, visibleSize.height - visibleSize.height / 2.8 + offset_y);

    // 计算精灵移动的时间
    float duration = 1.0f;

    // 创建精灵的运动动作
    auto moveAction = MoveTo::create(duration, targetPosition);
    auto myPlayer = dirs->getChildByName("player1");
    myPlayer->runAction(moveAction);

    myPlayer->stopAllActions();    // 停止之前的动作
    myPlayer->runAction(moveAction);
}

//购买经验值按钮回调函数
void BaseRoundScene::buyButtonClickCallback(Ref* pSender)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto dirs = Director::getInstance()->getRunningScene();
    auto myPlayer = dynamic_cast<Player*>(dirs->getChildByName("player1"));
    if (myPlayer->buyExperience()) {
        //显示我方小小英雄金币数量
        Label* labelCoins;
        labelCoins = Label::createWithTTF("My Coins", "fonts/UbuntuNFMono.ttf", 20);
        int myCoins = myPlayer->getCoin();
        labelCoins->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 12 + 120));
        this->addChild(labelCoins);
        labelCoins->setName("labelCoins");
        labelCoins->setString(StringUtils::format("My Coins : %d", myCoins));
        this->removeChild(dirs->getChildByName("labelCoins"));
    }
    //displayBuyButton();
}

//刷新按钮回调函数
void BaseRoundScene::refreshButtonClickCallback(Ref* pSender)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto dirs = Director::getInstance()->getRunningScene();

    //捕获节点
    auto myPlayer = dynamic_cast<Player*>(dirs->getChildByName("player1"));

    //刷新商店，同时扣金币
    if (myPlayer->refreshStore()) {
        Label* labelCoins;
        labelCoins = Label::createWithTTF("My Coins", "fonts/UbuntuNFMono.ttf", 20);
        int myCoins = myPlayer->getCoin();
        labelCoins->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 12 + 120));
        this->addChild(labelCoins);
        labelCoins->setName("labelCoins");
        labelCoins->setString(StringUtils::format("My Coins : %d", myCoins));
        this->removeChild(dirs->getChildByName("labelCoins"));

        //刷新商店，随机生成英雄卡牌
        displayStoreLegend();
    }
    

    //displayRefreshButton();
}

//购买英雄回调函数
void BaseRoundScene::buyLegendCallback(Ref* pSender)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();

    //buyLegend();

    //二、其次判断备战区是否已满

    //return;

    //三。然后判断买入后是否存在三个一样的英雄  如果有 要进行升级



    //四、然后，才在备战区添加一位英雄

    auto dirs = Director::getInstance()->getRunningScene();
    auto player = dynamic_cast<Player*>(this->getChildByName("player1"));
    if (player == nullptr) {
        exit(0);
    }

    //player->buyLegend(legend);


    //for (auto i : player->getPreparedLegends()) {
    //    // TODO: 英雄 setName 待规范，LegendInfo 的任务，暂时使用序号作为测试
    //    if (i == nullptr)
    //        continue;
    //    auto legend = Legend::create(i);
    //    if (legend == nullptr) {
    //        problemLoading(legend->getImagePath());
    //    }
    //    else {
    //        player->buyLegend(legend);
    //        for (auto sprite : sprites) {
    //            // 从场景中移除Sprite
    //            sprite->removeFromParent();
    //        }

    //        // 清空sprites vector
    //        sprites.clear();
    //        displayMyPrepareLegend();
           /* legend->setName(id);
            sprites.push_back(legend);
            legend->setPosition(Vec2(visibleSize.width / 4.8 + count * 100, visibleSize.height / 4));
            addChild(legend);
            id = '0' + count;
            count++;*/
      /*  }
    }*/


    //auto prepareLegend = Sprite::create("HelloWorld.png");
    //prepareLegend->setScale(2.2);
    //prepareLegend->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 4, visibleSize.height / 10));
    ///*refreshButton->addClickEventListener(CC_CALLBACK_1(PreparationScene::buyLegendCallback, this));*/
    //addChild(prepareLegend, 2);

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
    //int totalTimeInSeconds = 60;
    int totalTimeInSeconds = 100;
    remainingTimeInSeconds = totalTimeInSeconds;

    // 在屏幕上创建一个标签用于显示剩余时间
    labelRemainTime = Label::createWithTTF("Time: 01:00", "fonts/UbuntuNFMono.ttf", 24);
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
        Director::getInstance()->popScene();
    }
}
