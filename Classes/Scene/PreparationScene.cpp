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

    //��ʾ�ҷ�ССӢ��
    displayMyPlayer();

    // �����������
    auto listener = EventListenerMouse::create();
    listener->onMouseDown = CC_CALLBACK_1(PreparationScene::onMouseDown, this);
    listener->onMouseMove = CC_CALLBACK_1(PreparationScene::onMouseMove, this);
    listener->onMouseUp = CC_CALLBACK_1(PreparationScene::onMouseUp, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
   
    //��ʼ����ʱ
    countdown();
    return true;
}

//��갴�µĻص�����
void PreparationScene::onMouseDown(EventMouse* event)
{
    selectLegend(event);
    //�����Ӣ�۱�ѡ�У�����ʾ����
    if (selectedSprite) {
        displayBoard();
    }
}

//����ƶ��Ļص�����
void PreparationScene::onMouseMove(EventMouse* event)
{
    dragLegend(event);
}

//��ʾ����
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

        // �ж��Ƿ���ָ��������
        bool isInBoard = false;
        // �ж��Ƿ���ָ��������
        for (int i = 0; i < boardWidth; i++) {
            for (int j = 0; j < boardHeight; j++) {           

                //������ɿ������̲�����ʾ
                //if (chessboard[i][j]) {    //����ᱨ��
                //   chessboard[i][j]->removeFromParentAndCleanup(true);
                //}

                Rect targetRect= chessboard[i][j]->getBoundingBox();               
                if (targetRect.containsPoint(mouseLocation))
                {
                    // �ƶ���ָ�����������
                    selectedSprite->setPosition(targetRect.getMidX(), targetRect.getMidY());
                    isInBoard = true;
                    break;
                }
               
                 //����ص���ʼλ��
                auto it = std::find(sprites.begin(), sprites.end(), selectedSprite);
                if (it != sprites.end()) {
                    int position = std::distance(sprites.begin(), it);
                    selectedSprite->setPosition(Vec2(visibleSize.width / 4.8 + position * 100, visibleSize.height / 4));
                }
            }
            if (isInBoard) break;
        }
        // ����ѡ�еľ���
        selectedSprite = nullptr;
    }
}