#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include "cocos2d.h"

#include "Legend/Legends.h"

USING_NS_CC;
//using namespace std;


//传递的初始玩家信息
struct StartPlayerInfo
{
	char fileName[30];
	bool isAI;
};


template <int size>
using LegendInfoArray = std::array<LegendInfo*, size>;
template <int row, int col>
using LegendInfoMatrix = std::array<std::array<LegendInfo*, col>, row>;
using Position = std::pair<int, int>;

const int maxLevel = 10;
const int levelUpExp[maxLevel] = { 0, 4, 10, 20, 40, 50, 80, 120, 160, 210 };
const int refreshStoreCost = 2;
const int purchaseExpCost = 4;
// TODO: 记得改为 include
const int battleBoardWidth = 7;
const int battleBoardHeight = 3;
const int preparationSize = 9;

// Player 继承自 Sprite 类，需要使用 create 函数及相关函数，参考 cocos2d 写法
// 新增 PlayerInfo 类，新的 Player 类将会包含一个 PlayerInfo 指针用于获取和修改玩家信息，且 Player 从结点删除后不影响 PlayerInfo 的继续存在

class PlayerInfo: public Node
{
	friend class Player;

public:
	PlayerInfo(const std::string& filename, bool isAI);
	//PlayerInfo(const char* filename, bool isAI);
	~PlayerInfo();
	
	static PlayerInfo* create(const std::string& filename, bool isAI);
	//static PlayerInfo* create(const char* filename, bool isAI);
private:
	bool _isAI;
	int _coins;
	int _experience;
	int _health;
	const std::string _image_path;//Vector<char>
	//char _image_path[30];
	//array<LegendWithPlace> _battlingLegends;
	//array<Legend*> _preparedLegends;
	LegendInfoMatrix<battleBoardHeight, battleBoardWidth> _battlingLegends;
	LegendInfoArray<preparationSize> _preparedLegends;
};

class Player: public Sprite
{
public:
	//Player(const string& filename, bool isAI);
	Player(PlayerInfo* const info) : _info(info) { }
	int getCoin(void) const { return _info->_coins; }
	//bool increaseCoin(int coins);
	int getLevel(void) const;

	bool refreshStore(void);//刷新商店，同时扣金币
	bool buyExperience(void); // 买经验，同时扣金币
	bool checkout(bool isWinner, int attack = 0); // 关卡结算，经验、金币，同时负责小小英雄的扣血

	bool buyLegend(Legend* legend);// 买英雄，同时扣金币
	//bool sellLegend(Legend* legend);  // 卖英雄，获取一定金币
	// 卖英雄，获取一定金币，传入英雄在场上的位置，位置约定同 moveLegend
	bool sellLegend(const Position& postion);
	bool sellLegend(const int postion);

	// 英雄移动函数，根据传入参数判断是从哪（准备区为 int/战斗区为 Position）到哪
	LegendInfo* moveLegend(const Position& src, const Position& dst);
	LegendInfo* moveLegend(const int src, const Position& dst);
	LegendInfo* moveLegend(const Position& src, const int dst);
	LegendInfo* moveLegend(const int src, const int dst);
	//bool toggleLegendStatus(Legend* legend, bool toBattle, int x = 0, int y = 0);

	const LegendInfoArray<preparationSize>& getPreparedLegends() const { return _info->_preparedLegends; }
	const LegendInfoMatrix<battleBoardHeight, battleBoardWidth>& getBattlingLegends() const { return _info->_battlingLegends; }

	static Player* create(PlayerInfo* const info);
private:
	PlayerInfo* const _info;
};

void testCallBack(PlayerInfo* playerInfo, Ref* sender);

#endif

