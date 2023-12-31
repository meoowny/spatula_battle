#include "BaseRoundScene.h"
#include "Store/Store.h"

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

//��ʾ����
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

//��ʾ�̵�
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

//��ʾ������ֵ��ť
void BaseRoundScene::displayBuyButton()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //���δ�ﵽ�������򴴽���ť
    auto dirs = Director::getInstance()->getRunningScene();
    

    /*

     if�ж�   ���޸�



    */



    if (true) {
        auto buyExperienceButton = Button::create("BuyExperienceButton.jpg");
        buyExperienceButton->setScale(2.2);
        buyExperienceButton->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 2.62, visibleSize.height / 12 + 45));
        buyExperienceButton->addClickEventListener(CC_CALLBACK_1(BaseRoundScene::buyButtonClickCallback, this));
        addChild(buyExperienceButton, 2);
    }
    //�����ܵ������
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

// ��ʾˢ�°�ť
void BaseRoundScene::displayRefreshButton()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //�����һ���ʣ�࣬�򴴽���ť



     /*

     if�ж�   ���޸�



    */



    if (true) {
        auto refreshButton = Button::create("RefreshButton.jpg");
        refreshButton->setScale(2.2);
        refreshButton->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 2.62, visibleSize.height / 12 - 45));
        refreshButton->addClickEventListener(CC_CALLBACK_1(BaseRoundScene::refreshButtonClickCallback, this));
        addChild(refreshButton, 2);
    }
    //�����ܵ��ˢ��
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

//��ʾ�̵�Ӣ�ۿ���
void BaseRoundScene::displayStoreLegend()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    auto st = new Store;
    Vector<LegendInfo*> legendPointer = st->refresh();
    Vector<Button*> storeLegends;
    for (auto info : legendPointer) {
        auto legend = Button::create(info->getCardPath(), "emptyStore.jpg", "emptyStore.jpg");
        legend->addClickEventListener([=](Ref* pSender) {
            //������ӹ���Ӣ�۵��߼�
            //�����ť�󣬶�Ӧ�̵�λ��Ӣ�۱����ߣ���ť��ɲ���ѡ��״̬����Ӧ�������ù���Ӣ�ۺ���������Ӣ��
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

//��ʾ�ҷ���ս��Ӣ��
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
        // TODO: Ӣ�� setName ���淶��LegendInfo ��������ʱʹ�������Ϊ����
        if (i == nullptr)
            continue;
        auto legend = Legend::create(i);
        if (legend == nullptr) {
            problemLoading(legend->getImagePath());
        }
		else {
			legend->setName(id);
			legend->setPosition(Vec2(visibleSize.width / 4.8 + count * 100, visibleSize.height / 4));
            addChild(legend);
			id = '0' + count;
			count++;
        }
    }
}

//��ʾ�ҷ�ս����Ӣ��
void BaseRoundScene::displayMyBattleLegend()
{
    //���޸�
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
            // TODO: Ӣ�� setName ���淶��LegendInfo ��������ʱʹ�������Ϊ����
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

//��ʾ�ҷ�ССӢ��
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
    //�����������
    auto listener = EventListenerMouse::create();
    listener->onMouseDown = CC_CALLBACK_1(BaseRoundScene::moveMyPlayer, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

//��ʾ�ҷ�ССӢ�۽������
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
    LegendWithLocation selectedSpriteWithLocation;
    selectedSpriteWithLocation.legend = nullptr;
    selectedSpriteWithLocation.position = { -1,-1 };
    int i = 0, j = 0;
    for (auto selectedSprite : myPlayer->getPreparedLegends()) {
        if (selectedSprite != nullptr) {
            if (selectedSprite->getBoundingBox().containsPoint(Vec2(event->getCursorX(), event->getCursorY())))
            {
                selectedSpriteWithLocation.legend = selectedSprite;
                selectedSpriteWithLocation.position = { i,-1 };
                // ��¼��ǰ������ľ���
                return selectedSpriteWithLocation;
            }
        }
        i++;
    }
    i = 0; j = 0;
    for (auto& array : myPlayer->getBattlingLegends()) {
        for (auto& selectedSprite : array) {
            if (selectedSprite != nullptr) {
                if (selectedSprite->getBoundingBox().containsPoint(Vec2(event->getCursorX(), event->getCursorY())))
                {
                    selectedSpriteWithLocation.legend = selectedSprite;
                    selectedSpriteWithLocation.position = { i,j };
                    // ��¼��ǰ������ľ���
                    return selectedSpriteWithLocation;
                }
            }
            j++;
        }
        i++;
    }

    return selectedSpriteWithLocation;
}

void BaseRoundScene::dragLegend(EventMouse* event, LegendWithLocation selectedSpriteWithLocation)
{
    if (selectedSpriteWithLocation.legend)
   {
       // �ƶ���ѡ�еľ���
        selectedSpriteWithLocation.legend->setPosition(Vec2(event->getCursorX(), event->getCursorY()));
   }
}

//�ƶ�ССӢ�ۻص�����
void BaseRoundScene::moveMyPlayer(EventMouse* event)
{
    if (event->getMouseButton() != EventMouse::MouseButton::BUTTON_RIGHT) {
        return;
    }
    auto dirs = Director::getInstance()->getRunningScene();
    // ��ȡ�������Ŀ��λ��
    Vec2 targetPosition = Vec2(event->getCursorX(), event->getCursorY());

    Size visibleSize = Director::getInstance()->getVisibleSize();
    targetPosition.x = clampf(targetPosition.x, visibleSize.width / 2 - visibleSize.width / 3, visibleSize.width / 2 + visibleSize.width / 3 + offset_x);
    targetPosition.y = clampf(targetPosition.y, visibleSize.height / 2.8, visibleSize.height - visibleSize.height / 2.8 + offset_y);

    // ���㾫���ƶ���ʱ��
    float duration = 1.0f;

    // ����������˶�����
    auto moveAction = MoveTo::create(duration, targetPosition);
    auto myPlayer = dirs->getChildByName("player1");
    myPlayer->runAction(moveAction);

    myPlayer->stopAllActions();    // ֹ֮ͣǰ�Ķ���
    myPlayer->runAction(moveAction);
}

//������ֵ��ť�ص�����
void BaseRoundScene::buyButtonClickCallback(Ref* pSender)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto dirs = Director::getInstance()->getRunningScene();
    auto myPlayer = dynamic_cast<Player*>(dirs->getChildByName("player1"));
    myPlayer->buyExperience();
    //��ʾ�ҷ�ССӢ�۽������
    Label* labelCoins;
    labelCoins = Label::createWithTTF("My Coins", "fonts/UbuntuNFMono.ttf", 20);
    int myCoins = myPlayer->getCoin();
    labelCoins->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 12 + 120));
    this->addChild(labelCoins);
    labelCoins->setName("labelCoins");
    labelCoins->setString(StringUtils::format("My Coins : %d", myCoins));
    this->removeChild(dirs->getChildByName("labelCoins"));
    //displayBuyButton();
}

//ˢ�°�ť�ص�����
void BaseRoundScene::refreshButtonClickCallback(Ref* pSender)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto dirs = Director::getInstance()->getRunningScene();

    //����ڵ�
    auto myPlayer = dynamic_cast<Player*>(dirs->getChildByName("player1"));

    //ˢ���̵꣬ͬʱ�۽��
    myPlayer->refreshStore();
    Label* labelCoins;
    labelCoins = Label::createWithTTF("My Coins", "fonts/UbuntuNFMono.ttf", 20);
    int myCoins = myPlayer->getCoin();
    labelCoins->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 12 + 120));
    this->addChild(labelCoins);
    labelCoins->setName("labelCoins");
    labelCoins->setString(StringUtils::format("My Coins : %d", myCoins));
    this->removeChild(dirs->getChildByName("labelCoins"));

    //ˢ���̵꣬�������Ӣ�ۿ���
    displayStoreLegend();

    //displayRefreshButton();
}

//����Ӣ�ۻص�����
void BaseRoundScene::buyLegendCallback(Ref* pSender)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();

    //buyLegend();

    //��������жϱ�ս���Ƿ�����

    //return;

    //����Ȼ���ж�������Ƿ��������һ����Ӣ��  ����� Ҫ��������



    //�ġ�Ȼ�󣬲��ڱ�ս�����һλӢ��

    auto dirs = Director::getInstance()->getRunningScene();
    auto player = dynamic_cast<Player*>(this->getChildByName("player1"));
    if (player == nullptr) {
        exit(0);
    }

    //player->buyLegend(legend);


    //for (auto i : player->getPreparedLegends()) {
    //    // TODO: Ӣ�� setName ���淶��LegendInfo ��������ʱʹ�������Ϊ����
    //    if (i == nullptr)
    //        continue;
    //    auto legend = Legend::create(i);
    //    if (legend == nullptr) {
    //        problemLoading(legend->getImagePath());
    //    }
    //    else {
    //        player->buyLegend(legend);
    //        for (auto sprite : sprites) {
    //            // �ӳ������Ƴ�Sprite
    //            sprite->removeFromParent();
    //        }

    //        // ���sprites vector
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

    // ��������ð�ťΪ���ɵ��״̬
    auto button = dynamic_cast<Button*>(pSender);
    if (button) {
        button->setTouchEnabled(false);
        button->setEnabled(false);
    }
}

//��ʼ����ʱ
void BaseRoundScene::countdown()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //��ʼ����ʱ������Ϊ1����
    int totalTimeInSeconds = 60;
    //int totalTimeInSeconds = 5;
    remainingTimeInSeconds = totalTimeInSeconds;

    // ����Ļ�ϴ���һ����ǩ������ʾʣ��ʱ��
    labelRemainTime = Label::createWithTTF("Time: 01:00", "fonts/UbuntuNFMono.ttf", 24);
    labelRemainTime->setScale(4);
    labelRemainTime->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 50));
    this->addChild(labelRemainTime);

    // ��������ʱ��ʱ��
    schedule(CC_SCHEDULE_SELECTOR(BaseRoundScene::updateTimerCallback), 1.0f, kRepeatForever, 0);

}

// ��ʱ���ص����������ڸ���ʣ��ʱ��
void BaseRoundScene::updateTimerCallback(float dt)
{
    /* ��������
        auto blueBar = DrawNode::create();
    blueBar->drawSolidRect(Vec2(origin.x, visibleSize.height - 50), Vec2(origin.x + visibleSize.width, visibleSize.height), Color4F::BLUE);
    this->addChild(blueBar);*/

    //float totalTime = 60.0f; // ��ʱ�䣨����Ϊ��λ��
    //float decreaseRate = 1.0f; // ÿ����ٵĳ���

    //float initialWidth = visibleSize.width; // ��ʼ��������
    //float currentWidth = initialWidth; // ��ǰ��������

    //this->schedule([=](float dt) mutable {
    //    float decreaseAmount = decreaseRate * dt; // ���㵱ǰ֡Ӧ�ü��ٵĳ���
    //    currentWidth -= decreaseAmount; // ���µ�ǰ����

    //    if (currentWidth < 0.0f) {
    //        currentWidth = 0.0f; // ȷ�����Ȳ�Ϊ����
    //    }

    //    blueBar->clear(); // ���֮ǰ�Ļ���
    //    blueBar->drawSolidRect(Vec2(origin.x, visibleSize.height - 50), Vec2(origin.x + currentWidth, visibleSize.height), Color4F::BLUE);
    //    }, 1.0f, "decrease_bar"); // ÿ��ִ��һ��


    if (remainingTimeInSeconds > 0) {
        remainingTimeInSeconds--;

        // ������Ӻ�����
        int minutes = remainingTimeInSeconds / 60;
        int seconds = remainingTimeInSeconds % 60;

        // ������ʾʣ��ʱ��ı�ǩ
        labelRemainTime->setString(StringUtils::format("Time: %02d:%02d", minutes, seconds));
    }
    else {
        // ʱ��������л�����һ������
        unschedule(CC_SCHEDULE_SELECTOR(BaseRoundScene::updateTimerCallback));
        //switchToNextScene();
        Director::getInstance()->popScene();
    }
}
