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

    //��ʾ����
    displayBackground();

    //��ʾ�̵�
    displayStore();

    //��ʾ������ֵ��ť
    displayBuyButton();

    //��ʾˢ�°�ť
    displayRefreshButton();

    //��ʾ�̵�Ӣ�ۿ���
    displayStoreLegend();

    //��ʾ�ҷ�ССӢ��
    displayMyPlayer();

    //��ʾ�ҷ���ս��Ӣ��
    displayMyPrepareLegend();

    //��ʾ�ҷ�ս����Ӣ��
    displayMyBattleLegend();

    //��ʾ����
    displayBoard();

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
    selectedSprite = selectLegend(event);
    //�����Ӣ�۱�ѡ�У�����ʾ����
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

//����ƶ��Ļص�����
void PreparationScene::onMouseMove(EventMouse* event)
{
    dragLegend(event, selectedSprite);
    boardCellSelected(event);  
}

//��ʾ����
void PreparationScene::displayBoard()
{
    //ս����
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
    //��ս��
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

//���̻���
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

        //������ɿ������̲�����ʾ
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

        // �ж��Ƿ���ָ��������
        bool isInBoard = false;

        for (int i = 0; i < battleBoardWidth; i++) {
            for (int j = 0; j < battleBoardHeight; j++) {
                Rect targetRect= battleChessboard[i][j]->getBoundingBox();
                if (targetRect.containsPoint(mouseLocation))
                {
                    // �ƶ���ָ�����������
                    selectedSprite->setPosition(targetRect.getMidX(), targetRect.getMidY());

                    //moveLegend
                    isInBoard = true;
                    break;
                }
               
                 //����ص���ʼλ��
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
        }
        
        // ����ѡ�еľ���
        selectedSprite = nullptr;
    }
}