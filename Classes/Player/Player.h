#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include "cocos2d.h"

#include "Legend/Legends.h"

USING_NS_CC;
//using namespace std;

template <int size>
using LegendInfoArray = std::array<LegendInfo*, size>;
template <int row, int col>
using LegendInfoMatrix = std::array<std::array<LegendInfo*, col>, row>;
using Position = std::pair<int, int>;

const int maxLevel = 10;
const int levelUpExp[maxLevel] = { 0, 4, 10, 20, 40, 50, 80, 120, 160, 210 };
const int purchaseExpCost = 4;
// TODO: �ǵø�Ϊ include
const int battleBoardWidth = 7;
const int battleBoardHeight = 3;
const int preparationSize = 9;

// Player �̳��� Sprite �࣬��Ҫʹ�� create ��������غ������ο� cocos2d д��
// ���� PlayerInfo �࣬�µ� Player �ཫ�����һ�� PlayerInfo ָ�����ڻ�ȡ���޸������Ϣ���� Player �ӽ��ɾ����Ӱ�� PlayerInfo �ļ�������

class PlayerInfo: public Node
{
	friend class Player;

public:
	PlayerInfo(const std::string& filename, bool isAI);
	~PlayerInfo();

	static PlayerInfo* create(const std::string& filename, bool isAI);
private:
	bool _isAI;
	int _coins;
	int _experience;
	int _health;
	const std::string _image_path;
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

	bool buyExperience(void); // ���飬ͬʱ�۽��
	bool checkout(bool isWinner, int attack = 0); // �ؿ����㣬���顢��ң�ͬʱ����ССӢ�۵Ŀ�Ѫ

	bool buyLegend(Legend* legend);// ��Ӣ�ۣ�ͬʱ�۽��
	//bool sellLegend(Legend* legend);  // ��Ӣ�ۣ���ȡһ�����
	// ��Ӣ�ۣ���ȡһ����ң�����Ӣ���ڳ��ϵ�λ�ã�λ��Լ��ͬ moveLegend
	bool sellLegend(const Position& postion);
	bool sellLegend(const int postion);

	// Ӣ���ƶ����������ݴ�������ж��Ǵ��ģ�׼����Ϊ int/ս����Ϊ Position������
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

