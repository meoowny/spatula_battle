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
			if (_preparedLegends[i] == NULL) {
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

void testCallBack(Ref* sender) {
	auto dirs = Director::getInstance()->getRunningScene();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	dirs->removeChildByName("mySprite", false);

	static auto player = new Player("Peashooter_0.png", false);
	player->player->setPosition(visibleSize.width / 4, visibleSize.height / 4);
	//player->player->cleanup();

	// 将 Player 改写为 Sprite 子类后这里需要重写
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
	animFrames.pushBack(SpriteFrame::create("Peashooter_0.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_1.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_2.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_3.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_4.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_5.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_6.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_7.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_8.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_9.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_10.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_11.png", Rect(0, 0, 72, 72)));
	animFrames.pushBack(SpriteFrame::create("Peashooter_12.png", Rect(0, 0, 72, 72)));

	// create the animation out of the frames
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);

	Action* action = RepeatForever::create(animate);
	action->setTag(2);

	if (mySprite->getActionByTag(2) == NULL)
		mySprite->runAction(action);

	// 为玩家购买一个英雄并放在场上，如果玩家已经有一个英雄则为这个英雄添加一个动作
	//player->buyLegend(Aphelios::create(""));
	auto legend = player->getPreparedLegends().at(0);
	if (legend == NULL) {
		legend = new Aphelios();
		if (legend == NULL)
			exit(2);
		player->buyLegend(legend);
		
		// 暂时无法运行，需要在修改 Legend 为 Sprite 子类并实现 create 函数后重写这里的调用方式
		// 如需运行可以先将这个 if 语句整体注释掉
		legend->sprite->setPosition(Vec2::ZERO);
		legend->sprite->setName("testLegend");
		legend->sprite->setAnchorPoint(Vec2::ZERO);
		dirs->addChild(player->getPreparedLegends()[0]->sprite, 3);
	}
	else {
		auto iii = dynamic_cast<Sprite*>(dirs->getChildByName("testLegend"));
		//legend->sprite->removeFromParent();
		//dirs->removeChild(iii, false);
		legend->sprite->setPosition(Vec2(10, 10));
		legend->sprite->runAction(MoveBy::create(2.0f, Vec2(0, 300)));
		if (legend->sprite->getActionByTag(2) == NULL)
			legend->sprite->runAction(action);
		//iii->runAction(MoveBy::create(2.0f, Vec2(0, 300)));
		//iii->setPosition(Vec2(10, 10));
		//dirs->addChild(player->getPreparedLegends()[0]->sprite, 3);
	}
}


