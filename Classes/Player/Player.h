#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "cocos2d.h"

#include "Legend/Legends.h"

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
	LegendInfo* legend;
	int x;
	int y;

	LegendWithPlace(LegendInfo* l = NULL, int px = 0, int py = 0)
		: legend(l), x(px), y(py)
	{ }
};

// Player 继承自 Sprite 类，需要使用 create 函数及相关函数，参考 cocos2d 写法
// 新增 PlayerInfo 类，新的 Player 类将会包含一个 PlayerInfo 指针用于获取和修改玩家信息，且 Player 从结点删除后不影响 PlayerInfo 的继续存在

class PlayerInfo: public Node
{
	friend class Player;

public:
	PlayerInfo(const string& filename, bool isAI);
	~PlayerInfo();

	static PlayerInfo* create(const string& filename, bool isAI);
private:
	bool _isAI;
	int _coins;
	int _experience;
	int _health;
	const string _image_path;
	//vector<LegendWithPlace> _battlingLegends;
	//vector<Legend*> _preparedLegends;
	vector<LegendWithPlace> _battlingLegends;
	vector<LegendInfo*> _preparedLegends;
};

class Player: public Sprite
{
public:
	//Player(const string& filename, bool isAI);
	Player(PlayerInfo* const info) : _info(info) { }
	int getCoin(void) const { return _info->_coins; }
	//bool increaseCoin(int coins);
	int getLevel(void) const;

	bool buyExperience(void); // 买经验，同时扣金币
	bool checkout(bool isWinner, int attack = 0); // 关卡结算，经验、金币，同时负责小小英雄的扣血

	bool buyLegend(Legend* legend);// 买英雄，同时扣金币
	bool sellLegend(Legend* legend);  // 卖英雄，获取一定金币

	bool moveLegend(Legend* legend, Region src, Region dst, int dst_x, int dst_y = 0);
	//bool toggleLegendStatus(Legend* legend, bool toBattle, int x = 0, int y = 0);

	const vector<LegendInfo*>& getPreparedLegends() const { return _info->_preparedLegends; }
	const vector<LegendWithPlace>& getBattlingLegends() const { return _info->_battlingLegends; }

	static Player* create(PlayerInfo* const info);
private:
	PlayerInfo* const _info;
};

void testCallBack(PlayerInfo* playerInfo, Ref* sender);

#endif

