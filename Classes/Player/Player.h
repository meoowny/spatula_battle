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

enum Region {BOARD, PREPARATION};

struct LegendWithPlace
{
	Legend* legend;
	int x;
	int y;
};

// ׼���̳��� Sprite �࣬��Ҫʹ�� create ��������غ������ο� cocos2d д��
// �ƻ������� PlayerInfo �࣬�µ� Player �ཫ�����һ�� PlayerInfo ָ�����ڻ�ȡ���޸������Ϣ���� Player �ӽ��ɾ����Ӱ�� PlayerInfo �ļ�������

class Player
{
public:
	Player(const string& filename, bool isAI);
	int getCoin(void) const { return _coins; }
	//bool increaseCoin(int coins);
	int getLevel(void) const;

	bool buyExperience(void); // ���飬ͬʱ�۽��
	bool checkout(bool isWinner, int attack = 0); // �ؿ����㣬���顢��ң�ͬʱ����ССӢ�۵Ŀ�Ѫ

	bool buyLegend(Legend* legend);// ��Ӣ�ۣ�ͬʱ�۽��
	bool sellLegend(Legend* legend);  // ��Ӣ�ۣ���ȡһ�����

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

