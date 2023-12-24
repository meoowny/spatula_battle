#include "BaseRoundScene.h"

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

//��ʾ����
void BaseRoundScene::displayBackground()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto preparationBackground = Sprite::create("PreparationBackground.png");
    if (preparationBackground == nullptr)
    {
        problemLoading("'PreparationBackground.png'");
    }
    else
    {
        preparationBackground->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 80));
        preparationBackground->setScale(3.5);
        addChild(preparationBackground, 0);
    }
}

//��ʾ�̵�
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

//��ʾ������ֵ��ť
void BaseRoundScene::displayBuyButton()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //���δ�ﵽ�������򴴽���ť


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




    // for()






    auto StoreLegend = Button::create("Peashooter_0.png", "Peashooter_0.png", "Peashooter_1.png");
    StoreLegend->setScale(2.2);
    StoreLegend->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 4, visibleSize.height / 12));
    StoreLegend->addClickEventListener(CC_CALLBACK_1(BaseRoundScene::buyLegendCallback, this));
    addChild(StoreLegend, 2);




}

//��ʾ��ս��Ӣ��
void BaseRoundScene::displayPrepareLegend()
{

}

//��ʾս����Ӣ��
void BaseRoundScene::displayBattleLegend()
{

}

//������ֵ��ť�ص�����
void BaseRoundScene::buyButtonClickCallback(Ref* pSender)
{
    //�����������

    // ...

    //displayBuyButton();
}

//ˢ�°�ť�ص�����
void BaseRoundScene::refreshButtonClickCallback(Ref* pSender)
{
    //  ���������  ��Ҫ���»�ȡӢ�ۿ�����Ϣ

    //  ...

    //displayRefreshButton();
}

//����Ӣ�ۻص�����
void BaseRoundScene::buyLegendCallback(Ref* pSender)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //һ�������ж�Ǯ������

    //return;

    //��������жϱ�ս���Ƿ�����

    //return;

    //����Ȼ���ж�������Ƿ��������һ����Ӣ��  ����� Ҫ��������



    //�ġ�Ȼ�󣬲��ڱ�ս������һλӢ��
    auto prepareLegend = Sprite::create("HelloWorld.png");
    prepareLegend->setScale(2.2);
    prepareLegend->setPosition(Vec2(visibleSize.width / 2 - visibleSize.width / 4, visibleSize.height / 10));
    /*refreshButton->addClickEventListener(CC_CALLBACK_1(PreparationScene::buyLegendCallback, this));*/
    addChild(prepareLegend, 2);

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
    remainingTimeInSeconds = totalTimeInSeconds;

    // ����Ļ�ϴ���һ����ǩ������ʾʣ��ʱ��
    labelRemainTime = Label::createWithTTF("Time: 01:00", "fonts/arial.ttf", 24);
    labelRemainTime->setScale(4);
    labelRemainTime->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 50));
    this->addChild(labelRemainTime);

    // ��������ʱ��ʱ��
    schedule(CC_SCHEDULE_SELECTOR(BaseRoundScene::updateTimerCallback), 1.0f, kRepeatForever, 0);

}

// ��ʱ���ص����������ڸ���ʣ��ʱ��
void BaseRoundScene::updateTimerCallback(float dt)
{
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