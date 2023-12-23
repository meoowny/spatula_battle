#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "cocos2d.h"

#include "Legend/BaseLegend.h"

USING_NS_CC;
using namespace std;

const int maxLevel = 10;
const int levelUpExp[maxLevel] = { 0, 4, 10, 20, 40, 50, 80, 120, 160, 210 };
const int purchaseExpCost = 4;
// TODO: 记得改为 include
const int preparationSize = 9;

enum Region {BOARD, PREPARATION};

struct LegendWithPlace
{
	Legend* legend;
	int x;
	int y;
};

class Player
{
public:
	Player(const string& filename, bool isAI);
	int getCoin(void) const { return _coins; }
	//bool increaseCoin(int coins);
	int getLevel(void) const;

	bool buyExperience(void); // 买经验，同时扣金币
	bool checkout(bool isWinner, int attack = 0); // 关卡结算，经验、金币，同时负责小小英雄的扣血

	bool buyLegend(Legend* legend);// 买英雄，同时扣金币
	bool sellLegend(Legend* legend);  // 卖英雄，获取一定金币

	bool moveLegend(Legend* legend, Region src, Region dst, int dst_x, int dst_y = 0);
	//bool toggleLegendStatus(Legend* legend, bool toBattle, int x = 0, int y = 0);

	const vector<Legend*>& getPreparedLegends() const { return _preparedLegends; }
	const vector<LegendWithPlace>& getBattlingLegends() const { return _battlingLegends; }

	Sprite* player;
private:
	bool _isAI;
	int _coins;
	int _experience;
	int _health;
	vector<LegendWithPlace> _battlingLegends;
	vector<Legend*> _preparedLegends;
};

void testCallBack(Ref* sender);

#endif

