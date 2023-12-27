#pragma once
#include <iostream>
#include "AppDelegate.h"
#include "cocos2d.h"
#include <string>
#include <vector>
#include <Windows.h>
//using namespace std;
using namespace cocos2d;

// 类似于 Player 类，Legend 类也有对应的 LegendInfo，但 LegendInfo 存放英雄的固有属性，Legend 存放的是实时属性，每回合会刷新

class LegendInfo
{
	friend class Legend;

public:
	LegendInfo(const std::string& name, int most_health, int cost, int attackDamage, int armor, int criticalStrikeChance, int range)
		:_name(name), _most_health(most_health), _cost(cost),
		_attack_damage(attackDamage), _armor(armor), _critical_strike_chance(criticalStrikeChance), _range(range), _level(1)
	{ }

private:
	const std::string _name;
	int _most_health;
	const int _cost;
	//派生类中的初始化列表
	int _attack_damage;
	int _armor;
	int _critical_strike_chance;
	int _range;
	int _level;
};

class Legend: public Sprite
{
	friend class Player;
public:
	//get函数
	virtual std::string getLegendName() const { return _info->_name; }
	virtual int getHealth() const;
	virtual int getMana() const { return _mana; }
	virtual int getLevel() const { return _info->_level; }
	virtual int getAttackDamage() const;
	virtual int getArmor() const { return _info->_armor; }
	virtual int getCriticalStrike_Chance() const { return _info->_critical_strike_chance; }
	virtual int getRange() { return _info->_range; }
	virtual int getCost() const;

	int getAttack(void);
	bool levelUp(void);
	virtual int beingAttack(int attack_damage);
	virtual int beingHealed(int be_healed);
	virtual int abilityAttack() { return 0; }

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }

	static Legend* create(LegendInfo* const info);

protected:
	Legend(LegendInfo* const info) : _info(info), _health(_info->_most_health), _mana(0)
	{ }

	//Legend(const string& name, int most_health, int cost)
	//	:_name(name), _most_health(most_health), _health(most_health), _mana(0), _level(1), _cost(cost)
	//{
	//	sprite = Sprite::create("HelloWorld.png");
	//}
protected:
	LegendInfo* const _info;
	int _health;
	int _mana;

	//const string _name;
	//int _most_health;
	//int _health;
	//int _mana;
	//int _level;
	//const int _cost;
	////派生类中的初始化列表
	//int _attack_damage;
	//int _armor;
	//int _critical_strike_chance;
	//int _range;

};
