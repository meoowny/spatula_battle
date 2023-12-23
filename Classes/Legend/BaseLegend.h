#pragma once
#include <iostream>
#include "AppDelegate.h"
#include "cocos2d.h"
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
using namespace cocos2d;

class Legend :public Sprite
{
public:
	//get函数
	virtual string Get_Name() const { return _name; }
	virtual int GetHealth() const;
	virtual int GetMana() const { return _mana; }
	virtual int GetAttackDamage() const;
	virtual int GetArmor() const { return _armor; }
	virtual int GetCriticalStrike_Chance() const { return _critical_strike_chance; }
	virtual int GetRange() { return _range; }
	virtual int GetCost() const;

	int GetAttack(void);
	bool LevelUp(void);
	bool Refresh(void);
	virtual int BeingAttack(int attack_damage);
	virtual int BeingHealed(int be_healed);
	virtual int ability_attack() = 0;

protected:
	Legend(const string& name, int most_health, int cost)
		:_name(name), _most_health(most_health), _health(most_health), _mana(0), _level(1), _cost(cost) {}

protected:
	const string _name;
	int _most_health;
	int _health;
	int _mana;
	int _level;
	const int _cost;
	//派生类中的初始化列表
	int _attack_damage;
	int _armor;
	int _critical_strike_chance;
	int _range;

};
