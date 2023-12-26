#include "Player/Player.h"

USING_NS_CC;

PlayerInfo::PlayerInfo(const std::string& filename, bool isAI)
	: _isAI(isAI), _coins(5), _health(100), _preparedLegends(preparationSize), _image_path(filename)
{ }

PlayerInfo::~PlayerInfo()
{
	for (auto i : _battlingLegends) {
		delete i.legend;
	}
	for (auto i : _preparedLegends) {
		delete i;
	}
}

PlayerInfo* PlayerInfo::create(const string& filename, bool isAI)
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

bool Player::sellLegend(Legend* legend)
{
	// 销毁指针
	return true;
}

bool Player::checkout(bool isWinner, int attack)
{
	return true;
}

bool Player::moveLegend(Legend* legend, Region src, Region dst, int dst_x, int dst_y)
{
	return true;
}

void testCallBack(PlayerInfo* playerInfo, Ref* sender) {
	auto dirs = Director::getInstance()->getRunningScene();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	dirs->removeChildByName("player", false);
	dirs->removeChildByName("testLegend");

	// 不可从场景获取 playerInfo 结点，原因不明，改用传入的参数
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

	// 使用如上素材创建一个帧动画的动作
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);

	Action* action = RepeatForever::create(animate);

	player->runAction(action);

	// 为玩家购买一个英雄并放在场上，如果玩家已经有一个英雄则为这个英雄添加一个动作
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


