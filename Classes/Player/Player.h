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
// TODO: �ǵø�Ϊ include
const int preparationSize = 9;
const int battleBoardWidth = 7;
const int battleBoardHeight = 3;

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

// Player �̳��� Sprite �࣬��Ҫʹ�� create ��������غ������ο� cocos2d д��
// ���� PlayerInfo �࣬�µ� Player �ཫ�����һ�� PlayerInfo ָ�����ڻ�ȡ���޸������Ϣ���� Player �ӽ��ɾ����Ӱ�� PlayerInfo �ļ�������

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

	bool buyExperience(void); // ���飬ͬʱ�۽��
	bool checkout(bool isWinner, int attack = 0); // �ؿ����㣬���顢��ң�ͬʱ����ССӢ�۵Ŀ�Ѫ

	bool buyLegend(Legend* legend);// ��Ӣ�ۣ�ͬʱ�۽��
	bool sellLegend(Legend* legend);  // ��Ӣ�ۣ���ȡһ�����

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

