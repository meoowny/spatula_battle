#include "Player/Player.h"

USING_NS_CC;

Player::Player(const std::string& filename, bool isAI)
	: _isAI(isAI), _coins(5), _health(100), _preparedLegends(preparationSize)
{
	player = Sprite::create(filename);
	player->setScale(1.4);
}

int Player::getLevel(void) const
{
	int level = 1;
	int exp = _experience;
	for (int i = 1; exp >= 0 && i < maxLevel; i++) {
		exp -= levelUpExp[i];
		level++;
	}
	return level;
}

bool Player::buyExperience(void)
{
	if (_coins < purchaseExpCost) {
		return false;
	}
	else {
		_coins -= purchaseExpCost;
		_experience += purchaseExpCost;
		return true;
	}
}

bool Player::buyLegend(Legend* legend)
{
	if (_coins < legend->GetCost()) {
		return false;
	}
	else {
		_coins -= legend->GetCost();

		bool isFull = true;
		for (int i = 0; i < preparationSize; i++) {
			if (_preparedLegends[i] != NULL) {
				_preparedLegends[i] = legend;
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

void testCallBack(Ref* sender) {
	auto dirs = Director::getInstance()->getRunningScene();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	dirs->removeChildByName("mySprite", false);
	dirs->getChildByName("mySprite");

	static auto player = new Player("Peashooter_0.png", false);
	player->player->setPosition(visibleSize.width / 4, visibleSize.height / 4);

	//static auto mySprite = Sprite::create("Peashooter_0.png");
	auto mySprite = player->player;
	mySprite->setName("mySprite");
	mySprite->setPosition(Vec2(origin.x + visibleSize.width / 3, origin.y + visibleSize.height / 2));
	dirs->addChild(mySprite, 9);

	auto moveBy = MoveBy::create(2.0f, Vec2(0, 300));
	auto moveRight = MoveBy::create(2.0f, Vec2(500, 0));

	mySprite->runAction(moveBy);
	mySprite->runAction(moveRight);

	// now lets animate the sprite we moved
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(13);
	animFrames.pushBack(SpriteFrame::create("Peashooter_0.png", Rect(0, 0, 71, 71)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_1.png", Rect(0, 0, 71, 71)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_2.png", Rect(0, 0, 71, 71)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_3.png", Rect(0, 0, 71, 71)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_4.png", Rect(0, 0, 71, 71)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_5.png", Rect(0, 0, 71, 71)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_6.png", Rect(0, 0, 71, 71)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_7.png", Rect(0, 0, 71, 71)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_8.png", Rect(0, 0, 71, 71)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_9.png", Rect(0, 0, 71, 71)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_10.png", Rect(0, 0, 71, 71)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_11.png", Rect(0, 0, 71, 71)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_12.png", Rect(0, 0, 71, 71)));

	// create the animation out of the frames
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);

	Action* action = RepeatForever::create(animate);
	action->setTag(2);

	if (mySprite->getActionByTag(2) == NULL)
		mySprite->runAction(action);
}

