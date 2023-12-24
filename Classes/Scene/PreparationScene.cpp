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

    //��ʾ����
    displayBackground();

    //��ʾ�̵�
    displayStore();

    //��ʾ������ֵ��ť
    displayBuyButton();

    //��ʾˢ�°�ť
    displayRefreshButton();

    //��ʾ�̵�Ӣ�ۿ���
    /*displayStoreLegend();*/

    //��ʾ��ս��Ӣ��
    displayPrepareLegend();

    //��ʾս����Ӣ��
    displayBattleLegend();

    //��ʾССӢ��
    displayPlayer();

    // �����������
    auto listener = EventListenerMouse::create();
    listener->onMouseDown = CC_CALLBACK_1(PreparationScene::onMouseDown, this);
    listener->onMouseMove = CC_CALLBACK_1(PreparationScene::onMouseMove, this);
    listener->onMouseUp = CC_CALLBACK_1(PreparationScene::onMouseUp, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    //��ʼ����ʱ������Ϊ1����
    countdown();
    return true;
}

//��ʾССӢ��
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
  //        // ��¼��ǰ������ľ���
  //        selectedSprite = sprite;

  //        /*offset = event->getLocation() - selectedSprite->getPosition();*/
  //        break;
  //    }
  //}
}

void PreparationScene::mouseRightClick(EventMouse* event)
{
    auto dirs = Director::getInstance()->getRunningScene();
    // ��ȡ�������Ŀ��λ��
    Vec2 targetPosition = Vec2(event->getCursorX(), event->getCursorY());

    Size visibleSize = Director::getInstance()->getVisibleSize();
    targetPosition.x = clampf(targetPosition.x, visibleSize.width / 2 - visibleSize.width / 2.5, visibleSize.width / 2 + visibleSize.width / 2.5);
    targetPosition.y = clampf(targetPosition.y, visibleSize.height / 2 - visibleSize.height / 5, visibleSize.height / 2 + visibleSize.height / 5 + 50);

    // ���㾫���ƶ���ʱ��
    float duration = 1.0f;

    // ����������˶�����
    auto moveAction = MoveTo::create(duration, targetPosition);
    myPlayer->runAction(moveAction);

    myPlayer->stopAllActions();    // ֹ֮ͣǰ�Ķ���
    myPlayer->runAction(moveAction);
}

void PreparationScene::onMouseMove(EventMouse* event)
{
    //if (selectedSprite)
    //{
    //    // �ƶ���ѡ�еľ���
    //    selectedSprite->setPosition(Vec2(event->getCursorX(), event->getCursorY())/*- offset*/);
    //}
}

void PreparationScene::onMouseUp(EventMouse* event)
{
    //if (selectedSprite)
    //{
    //    // �ж��Ƿ���ָ��������
    //    Rect targetRect = Rect(500, 500, 300, 300);

    //    if (targetRect.containsPoint(event->getLocation()))
    //    {
    //        // �ƶ���ָ�����������
    //        selectedSprite->setPosition(targetRect.getMidX(), targetRect.getMidY());
    //    }
    //    else
    //    {
    //        // �ص���ʼλ��
    //        selectedSprite->setPosition(Vec2(350 * (sprites.getIndex(selectedSprite) + 1) - 200, 200));
    //    }
    //    // ����ѡ�еľ���
    //    selectedSprite = nullptr;
    //}
}