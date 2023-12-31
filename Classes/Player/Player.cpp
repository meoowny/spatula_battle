#include "Player/Player.h"

USING_NS_CC;

PlayerInfo::PlayerInfo(const std::string& filename, bool isAI)
	: _isAI(isAI), _coins(200), _health(100), _image_path(filename)
{
	for (auto& i : _preparedLegends) {
		i = NULL;
	}
	for (auto& i : _battlingLegends) {
		for (auto& j : i) {
			j = NULL;
		}
	}
}

////��playerinfo����Ϣ���иĶ�
//int PlayerInfo::changePlayerInfo(char fileName[30], bool isAI, int coins, int experience, int health, int* preparadLegends, int* battleLegend)
//{
//	for (int i = 0; i < 30; i++)
//	{
//		_image_path += fileName[i];
//		if (fileName[i] == '\0')
//		{
//			break;
//		}
//	}
//	_isAI = isAI;
//	_coins = coins;
//	_experience = experience;
//	_health = health;
//	return 0;
//}



/*PlayerInfo::PlayerInfo(const char* filename, bool isAI)
	: _isAI(isAI), _coins(5), _health(100), _image_path("0")
{
	for (auto& i : _preparedLegends) {
		i = NULL;
	}
	for (auto& i : _battlingLegends) {
		for (auto& j : i) {
			j = NULL;
		}
	}
	strcpy(_image_path, filename);
}*/


PlayerInfo::~PlayerInfo()
{
	// array ���������⣬ȥ�����
	for (auto i : _battlingLegends) {
		for (auto j : i) {
			if (j != NULL) {
				delete j;
			}
		}
	}
	for (auto i : _preparedLegends) {
		if (i != NULL) {
			delete i;
		}
	}
}

PlayerInfo* PlayerInfo::create(const std::string& filename, bool isAI)
{
	PlayerInfo* info = new (std::nothrow) PlayerInfo(filename, isAI);
	if (info && info->init()) {
		info->autorelease();
		return info;
	}
	else {
		CC_SAFE_DELETE(info);
		return nullptr;
	}
}
/*
PlayerInfo* PlayerInfo::create(const char* filename, bool isAI)
{
	PlayerInfo* info = new (std::nothrow) PlayerInfo(filename, isAI);
	if (info && info->init()) {
		info->autorelease();
		return info;
	}
	else {
		CC_SAFE_DELETE(info);
		return nullptr;
	}
}
*/
Player* Player::create(PlayerInfo* const info)
{
	Player* player = new (std::nothrow) Player(info);
	if (player && player->initWithFile(info->_image_path)) {
		player->autorelease();
		return player;
	}
	else {
		CC_SAFE_DELETE(player);
		return nullptr;
	}
}

int Player::getLevel(void) const
{
	int level = 1;
	int exp = _info->_experience;
	for (int i = 1; exp >= 0 && i < maxLevel; i++) {
		exp -= levelUpExp[i];
		level++;
	}
	return level;
}

bool Player::refreshStore(void) {
	if (_info->_coins < refreshStoreCost) {
		return false;
	}
	else {
		_info->_coins -= refreshStoreCost;
		//�����������̵�ˢ�µĺ���
		// 
		// .....
		// 
		//���·����̵꿨��
		return true;
	}
}

bool Player::buyExperience(void)
{
	if (_info->_coins < purchaseExpCost) {
		return false;
	}
	else {
		_info->_coins -= purchaseExpCost;
		_info->_experience += purchaseExpCost;
		return true;
	}
}

bool Player::buyLegend(Legend* legend)
{
	if (_info->_coins < legend->getCost()) {
		return false;
	}
	else {
		_info->_coins -= legend->getCost();

		bool isFull = true;
		for (int i = 0; i < preparationSize; i++) {
			if (_info->_preparedLegends[i] == NULL) {
				_info->_preparedLegends[i] = legend->_info;
				isFull = false;
				break;
			}
		}

		if (isFull) {
			return false;
		}
		else {
			return true;
		}
	}
}

bool Player::sellLegend(const Position& position)
{
	// ����ָ��
	auto legendInfo = _info->_battlingLegends[position.first][position.second];
	if (legendInfo == NULL) {
		return false;
	}

	auto tmpLegend = Legend::create(legendInfo);
	_info->_coins += tmpLegend->getCost();

	delete legendInfo;

	return true;
}

bool Player::sellLegend(const int position)
{
	// ����ָ��
	auto legendInfo = _info->_preparedLegends[position];
	if (legendInfo == NULL) {
		return false;
	}

	auto tmpLegend = Legend::create(legendInfo);
	_info->_coins += tmpLegend->getCost();

	delete legendInfo;

	return true;
}

bool Player::checkout(bool isWinner, int attack)
{
	return true;
}

LegendInfo* Player::moveLegend(const Position& src, const Position& dst)
{
	if (_info->_battlingLegends[src.first][src.second] == NULL
		|| _info->_battlingLegends[dst.first][dst.second] != NULL) {
		return NULL;
	}
	_info->_battlingLegends[dst.first][dst.second] = _info->_battlingLegends[src.first][src.second];
	_info->_battlingLegends[src.first][src.second] = NULL;
	return _info->_battlingLegends[dst.first][dst.second];
}

LegendInfo* Player::moveLegend(const int src, const Position& dst)
{
	if (_info->_preparedLegends[src] == NULL
		|| _info->_battlingLegends[dst.first][dst.second] != NULL) {
		return NULL;
	}
	_info->_battlingLegends[dst.first][dst.second] = _info->_preparedLegends[src];
	_info->_preparedLegends[src] = NULL;
	return _info->_battlingLegends[dst.first][dst.second];
}

LegendInfo* Player::moveLegend(const Position& src, const int dst)
{
	if (_info->_battlingLegends[src.first][src.second] == NULL
		|| _info->_preparedLegends[dst] != NULL) {
		return NULL;
	}
	_info->_preparedLegends[dst] = _info->_battlingLegends[src.first][src.second];
	_info->_battlingLegends[src.first][src.second] = NULL;
	return _info->_preparedLegends[dst];
}

LegendInfo* Player::moveLegend(const int src, const int dst)
{
	if (_info->_preparedLegends[src] == NULL
		|| _info->_preparedLegends[dst] != NULL) {
		return NULL;
	}
	_info->_preparedLegends[dst] = _info->_preparedLegends[src];
	_info->_preparedLegends[src] = NULL;
	return _info->_preparedLegends[dst];
}

void testCallBack(PlayerInfo* playerInfo, Ref* sender) {
	auto dirs = Director::getInstance()->getRunningScene();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	dirs->removeChildByName("player", false);
	dirs->removeChildByName("testLegend");

	// ���ɴӳ�����ȡ playerInfo ��㣬ԭ���������ô���Ĳ���
	//auto node = dirs->getChildByName("playerInfo");
	//if (node == NULL) {
	//	exit(0);
	//}
	auto player = Player::create(playerInfo);
	player->setPosition(visibleSize.width / 4, visibleSize.height / 4);

	player->setName("player");
	player->setPosition(Vec2(origin.x + visibleSize.width / 3, origin.y + visibleSize.height / 2));
	player->setRotation(-50.5);
	dirs->addChild(player, 3);

	auto moveBy = MoveBy::create(2.0f, Vec2(0, 300));
	auto delay = DelayTime::create(0.5f);
	auto moveRight = MoveBy::create(2.0f, Vec2(500, 0));
	auto moveOrigin = MoveBy::create(2.0f, Vec2(-500, -300));

	player->runAction(RepeatForever::create(Sequence::create(moveBy, delay, moveRight, delay->clone(), moveOrigin, delay->clone(), NULL)));

	// now lets animate the sprite we moved
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(13);
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_0.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_1.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_2.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_3.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_4.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_5.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_6.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_7.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_8.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_9.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_10.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_11.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_12.png", Rect(0, 0, 72, 72)));

	// ʹ�������زĴ���һ��֡�����Ķ���
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);

	Action* action = RepeatForever::create(animate);

	player->runAction(action);

	// Ϊ��ҹ���һ��Ӣ�۲����ڳ��ϣ��������Ѿ���һ��Ӣ����Ϊ���Ӣ�����һ������
	auto info = player->getPreparedLegends().at(0);
	if (info == NULL) {
		log("heel");
		info = Aphelios::createInfo();
		player->buyLegend(Legend::create(info));
	}

	auto legend = Legend::create(info);
	legend->setPosition(Vec2::ZERO);
	legend->setName("testLegend");
	legend->setAnchorPoint(Vec2::ZERO);
	legend->runAction(MoveBy::create(2.0f, Vec2(0, 300)));
	legend->runAction(action->clone());
	dirs->addChild(legend, 3);
}


