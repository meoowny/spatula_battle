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
	Legend(const string &name,int most_health,int cost)
		:_name(name),_most_health(most_health),_health(most_health),_mana(0),_level(1),_cost(cost){}

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

bool Legend::Refresh()
{
	_health = _most_health;
	_mana = 0;
	return true;
}

bool Legend::LevelUp()
{
	if (_level >= 3) {
		return false;
	}
	else {
		_level++;
		_most_health *= 1.1;
		_health *= 1.1;
		//_critical_strike_chance += 10;
		_attack_damage += 10;
		_armor *= 1.2;
		return true;
	}

}
int Legend::GetCost() const
{
	int result = _cost;
	for (int i = 1; i < _level; i++) {
		result = result * 3 - 1;
	}
	return result;
}

int Legend::GetHealth() const
{
	if (_health <= 0)
		return 0;
	return _health;

}
//还有许多get函数需要完善！
int Legend::GetAttackDamage() const
{
	if (_attack_damage <= 0)
		return 0;
	return _attack_damage;
}

int Legend::GetAttack() 
{
	if (_mana < 100) {
		_mana += 10;  //每次攻击增加十点蓝量，每到100点释放技能
		int result = _attack_damage;
		if (rand() / RAND_MAX * 100 < _critical_strike_chance)
			result *= 2;            //随机数判断是否暴击
		return result;  //返回伤害
	}
	else {
		_mana = 0;
		return ability_attack();
	}
}

int Legend::BeingAttack(int attack_damage)
{
	int be_damaged;
	if (_armor >= 0) {
		double damage_reduction = _armor / (_armor + 100.0);  //计算伤害减免，物理伤害减免 = 护甲 / (护甲 + 100)
		be_damaged = (1 - damage_reduction) * attack_damage;  //计算受到的伤害
	}
	else {
		be_damaged = attack_damage;  //护甲小于0等于受到真实伤害
	}

	_health = _health - be_damaged;  //血量减少函数
	if (_health <= 0) {
		_health = 0;
		cout << "您已阵亡！" << endl;
	}
	return be_damaged;
}


int Legend::BeingHealed(int be_healed)
{
	_health = _health + be_healed;
	if (_health >= _most_health) {
		_health = _most_health;
	}
	return be_healed;
}

/*int _attack_damage;
int _armor;
int _critical_strike_chance;
int _range;*/


//adc
class Aphelios: public Legend 
{
public:
	Aphelios():Legend("Aphelios",580,2)
	{
		_attack_damage = 70;
		_armor = 26;
		_critical_strike_chance = 10;
		_range = 4;
	}
	int ability_attack();
};

int Aphelios::ability_attack() 
{
	int ability_damage;
	int basic_damage;
	switch (_level) {
		case 1:
			basic_damage = 125;
			break;
		case 2:
			basic_damage = 175;
			break;
		case 3:
			basic_damage = 225;
			break;
		default:
			basic_damage = 225;
			break;
	}
	if (_mana < 100) {
		//cout << "魔法值尚未达到100！" << endl;
		return -1;
	}
	else {
		_mana = 0;
		ability_damage = basic_damage + 0.2 * _attack_damage;
		return ability_damage;
	}
}

class Caitlyn :public Legend
{
public:
	Caitlyn() :Legend("Caitlyn", 480, 4)
	{
		_attack_damage = 62;
		_armor = 28;
		_critical_strike_chance = 10;
		_range = 5;
	}
	int ability_attack();
};

int Caitlyn::ability_attack() {
	int ability_damage;
	int basic_damage;
	switch (_level) {
		case 1:
			basic_damage = 200;
			break;
		case 2:
			basic_damage = 300;
			break;
		case 3:
			basic_damage = 400;
			break;
		default:
			basic_damage = 400;
			break;
	}
	if (_mana < 100) {
		//cout << "魔法值尚未达到100！" << endl;
		return -1;
	}
	else {
		_mana = 0;
		ability_damage = basic_damage + 0.3 * _attack_damage;
		return ability_damage;
	}
}

class Ezreal :public Legend
{
public:
	Ezreal() :Legend("Ezreal", 600, 2)
	{
		_attack_damage = 60;
		_armor = 24;
		_critical_strike_chance = 10;
		_range = 4;
	}
	int ability_attack();
};

int Ezreal::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 200;
			break;
		case 2:
			basic_damage = 275;
			break;
		case 3:
			basic_damage = 350;
			break;
		default:
			basic_damage = 350;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 0.9 * _attack_damage;
		return result;
	}

}

class Lucian :public Legend
{
public:
	Lucian() :Legend("Lucian", 641, 2)
	{
		_attack_damage = 60;
		_armor = 28;
		_critical_strike_chance = 10;
		_range = 3;
	}
	int ability_attack();
};

int Lucian::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 165;
			break;
		case 2:
			basic_damage = 200;
			break;
		case 3:
			basic_damage = 235;
			break;
		default:
			basic_damage = 235;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 2 * _attack_damage;
		return result;
	}
}

class Miss_Fortune :public Legend
{
	Miss_Fortune() :Legend("Miss_Fortune", 640, 2)
	{
		_attack_damage = 52;
		_armor = 28;
		_critical_strike_chance = 10;
		_range = 4;
	}
	int ability_attack();
};

int Miss_Fortune::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 160;
			break;
		case 2:
			basic_damage = 200;
			break;
		case 3:
			basic_damage = 240;
			break;
		default:
			basic_damage = 240;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 0.85 * _attack_damage;
		return result;
	}
}

class Graves :public Legend
{
	Graves() :Legend("Graves", 625, 2)
	{
		_attack_damage = 68;
		_armor = 33;
		_critical_strike_chance = 10;
		_range = 3;
	}
	int ability_attack();
};

int Graves::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 250;
			break;
		case 2:
			basic_damage = 400;
			break;
		case 3:
			basic_damage = 550;
			break;
		default:
			basic_damage = 550;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 0.75 * _attack_damage;
		return result;
	}
}

class Varus :public Legend
{
	Varus() :Legend("Varus", 600, 2)
	{
		_attack_damage = 62;
		_armor = 27;
		_critical_strike_chance = 10;
		_range = 4;
	}
	int ability_attack();
};

int Varus::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 120;
			break;
		case 2:
			basic_damage = 170;
			break;
		case 3:
			basic_damage = 220;
			break;
		default:
			basic_damage = 220;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 3 * _attack_damage;
		return result;
	}
}

//ap

class Katarina :public Legend
{
public:
	Katarina() :Legend("Katarina", 672, 2)
	{
		_attack_damage = 58;
		_armor = 28;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Katarina::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 375;
			break;
		case 2:
			basic_damage = 562.5;
			break;
		case 3:
			basic_damage = 750;
			break;
		default:
			basic_damage = 750;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 2.85 * _attack_damage;
		return result;
	}
}

class Akali :public Legend
{
public:
	Akali() :Legend("Akali", 570, 2)
	{
		_attack_damage = 62;
		_armor = 23;
		_critical_strike_chance = 10;
		_range = 4;
	}
	int ability_attack();
};

int Akali::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 225;
			break;
		case 2:
			basic_damage = 435;
			break;
		case 3:
			basic_damage = 645;
			break;
		default:
			basic_damage = 645;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 0.9 * _attack_damage;
		return result;
	}
}

class Annie :public Legend
{
public:
	Annie() :Legend("Annie", 594, 2)
	{
		_attack_damage = 50;
		_armor = 19;
		_critical_strike_chance = 10;
		_range = 4;
	}
	int ability_attack();
};

int Annie::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 150;
			break;
		case 2:
			basic_damage = 275;
			break;
		case 3:
			basic_damage = 400;
			break;
		default:
			basic_damage = 400;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 0.65 * _attack_damage;
		return result;
	}
}

class Viktor :public Legend
{
public:
	Viktor() :Legend("Viktor", 600, 2)
	{
		_attack_damage = 53;
		_armor = 23;
		_critical_strike_chance = 10;
		_range = 4;
	}
	int ability_attack();
};

int Viktor::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 225;
			break;
		case 2:
			basic_damage = 435;
			break;
		case 3:
			basic_damage = 645;
			break;
		default:
			basic_damage = 645;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 0.9 * _attack_damage;
		return result;
	}   
}

class Sona :public Legend
{
public:
	Sona() :Legend("Sona", 550, 2)
	{
		_attack_damage = 49;
		_armor = 26;
		_critical_strike_chance = 10;
		_range = 4;
	}
	int ability_attack();
};

int Sona::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 150;
			break;
		case 2:
			basic_damage = 250;
			break;
		case 3:
			basic_damage = 350;
			break;
		default:
			basic_damage = 350;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 0.5 * _attack_damage;
		return result;
	}
}

class Jhin :public Legend
{
public:
	Jhin() :Legend("Jhin", 655, 2)
	{
		_attack_damage = 70;
		_armor = 24;
		_critical_strike_chance = 10;
		_range = 4;
	}
	int ability_attack();
};

int Jhin::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 150;
			break;
		case 2:
			basic_damage = 375;
			break;
		case 3:
			basic_damage = 600;
			break;
		default:
			basic_damage = 600;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 2 * _attack_damage;
		return result;
	}
}

//打野

class Viego :public Legend
{
public:
	Viego() :Legend("Viego", 630, 2)
	{
		_attack_damage = 70;
		_armor = 34;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Viego::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 300;
			break;
		case 2:
			basic_damage = 600;
			break;
		case 3:
			basic_damage = 900;
			break;
		default:
			basic_damage = 900;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 2 * _attack_damage;
		return result;
	}
}

class Qiyana :public Legend
{
public:
	Qiyana() :Legend("Qiyana", 590, 2)
	{
		_attack_damage = 66;
		_armor = 28;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Qiyana::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 100;
			break;
		case 2:
			basic_damage = 200;
			break;
		case 3:
			basic_damage = 300;
			break;
		default:
			basic_damage = 300;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 5 * _attack_damage;
		return result;
	}
}

class Kayn :public Legend
{
public:
	Kayn() :Legend("Kayn", 600, 2)
	{
		_attack_damage = 70;
		_armor = 28;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Kayn::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 300;
			break;
		case 2:
			basic_damage = 350;
			break;
		case 3:
			basic_damage = 400;
			break;
		default:
			basic_damage = 400;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 2 * _attack_damage;
		return result;
	}
}

class Bel_Veth :public Legend
{
public:
	Bel_Veth() :Legend("Bel_Veth", 610, 2)
	{
		_attack_damage = 60;
		_armor = 32;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Bel_Veth::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 100;
			break;
		case 2:
			basic_damage = 150;
			break;
		case 3:
			basic_damage = 200;
			break;
		default:
			basic_damage = 200;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 4 * _attack_damage;
		return result;
	}
}

class Ekko :public Legend
{
public:
	Ekko() :Legend("Ekko", 655, 2)
	{
		_attack_damage = 58;
		_armor = 32;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Ekko::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 150;
			break;
		case 2:
			basic_damage = 300;
			break;
		case 3:
			basic_damage = 450;
			break;
		default:
			basic_damage = 450;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 1.5 * _attack_damage;
		return result;
	}
}

//上单

class Riven : public Legend
{
public:
	Riven() :Legend("Riven", 630, 2)
	{
		_attack_damage = 64;
		_armor = 33;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Riven::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 300;
			break;
		case 2:
			basic_damage = 450;
			break;
		case 3:
			basic_damage = 600;
			break;
		default:
			basic_damage = 600;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 1.8 * _attack_damage;
		return result;
	}
}

class Fiora :public Legend
{
public:
	Fiora() :Legend("Fiora", 620, 2)
	{
		_attack_damage = 68;
		_armor = 33;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Fiora::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 200;
			break;
		case 2:
			basic_damage = 300;
			break;
		case 3:
			basic_damage = 400;
			break;
		default:
			basic_damage = 400;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage +4  * _attack_damage;
		return result;
	}
}

class Camille :public Legend
{
public:
	Camille() :Legend("Camille", 646, 2)
	{
		_attack_damage = 68;
		_armor = 33;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Camille::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 300;
			break;
		case 2:
			basic_damage = 350;
			break;
		case 3:
			basic_damage = 400;
			break;
		default:
			basic_damage = 400;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 6 * _attack_damage;
		return result;
	}
}

class Irelia :public Legend
{
public:
    Irelia() :Legend("Irelia", 590, 2)
	{
		_attack_damage = 65;
		_armor = 36;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Irelia::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 125;
			break;
		case 2:
			basic_damage = 250;
			break;
		case 3:
			basic_damage = 375;
			break;
		default:
			basic_damage = 375;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 0.9 * _attack_damage;
		return result;
	}
}
class Sett :public Legend
{
public:
	Sett() :Legend("Sett", 670, 2)
	{
		_attack_damage = 60;
		_armor = 33;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Sett::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 125;
			break;
		case 2:
			basic_damage = 140;
			break;
		case 3:
			basic_damage = 160;
			break;
		default:
			basic_damage = 160;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 3 * _attack_damage;
		return result;
	}
}

class Ganplank :public Legend
{
public:
	Ganplank() :Legend("Ganplank", 600, 2)
	{
		_attack_damage = 64;
		_armor = 31;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Ganplank::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 120;
			break;
		case 2:
			basic_damage = 200;
			break;
		case 3:
			basic_damage = 280;
			break;
		default:
			basic_damage = 280;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 2 * _attack_damage;
		return result;
	}
}

//辅助

class Thresh:public Legend
{
public:
	Thresh() :Legend("Thresh", 1000, 2)
	{
		_attack_damage = 56;
		_armor = 31;
		_critical_strike_chance = 10;
		_range = 3;
	}
	int ability_attack();
};

int Thresh::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 250;
			break;
		case 2:
			basic_damage = 400;
			break;
		case 3:
			basic_damage = 500;
			break;
		default:
			basic_damage = 500;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 1 * _attack_damage;
		return result;
	}
}

class Renata_Glasc:public Legend
{
public:
	Renata_Glasc() :Legend("Renata_Glasc", 500, 2)
	{
		_attack_damage = 56;
		_armor = 28;
		_critical_strike_chance = 10;
		_range = 4;
	}
	int ability_attack();
};

int Renata_Glasc::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 100;
			break;
		case 2:
			basic_damage = 200;
			break;
		case 3:
			basic_damage = 300;
			break;
		default:
			basic_damage =300;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 1 * _attack_damage;
		return result;
	}
}

class Rakan:public Legend
{
public:
	Rakan() :Legend("Rakan", 1000, 2)
	{
		_attack_damage = 62;
		_armor = 32;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Rakan::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 70;
			break;
		case 2:
			basic_damage = 115;
			break;
		case 3:
			basic_damage = 160;
			break;
		default:
			basic_damage = 160;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 1 * _attack_damage;
		return result;
	}
}

class Bard:public Legend
{
public:
	Bard() :Legend("Bard", 1200, 2)
	{
		_attack_damage = 52;
		_armor = 34;
		_critical_strike_chance = 10;
		_range = 4;
	}
	int ability_attack();
};

int Bard::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 80;
			break;
		case 2:
			basic_damage = 125;
			break;
		case 3:
			basic_damage = 175;
			break;
		default:
			basic_damage = 175;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 3 * _attack_damage;
		return result;
	}
}

class Nautilus :public Legend
{
public:
	Nautilus() :Legend("Nautilus", 1600, 2)
	{
		_attack_damage = 50;
		_armor = 39;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Nautilus::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 150;
			break;
		case 2:
			basic_damage = 160;
			break;
		case 3:
			basic_damage = 170;
			break;
		default:
			basic_damage = 170;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 0.8 * _attack_damage;
		return result;
	}
}

class Pyke :public Legend
{
public:
    Pyke() :Legend("Pyke", 900, 2)
	{
		_attack_damage = 70;
		_armor = 45;
		_critical_strike_chance = 10;
		_range = 1;
	}
	int ability_attack();
};

int Pyke::ability_attack()
{
	int basic_damage;
	int result;
	switch (_level) {
		case 1:
			basic_damage = 250;
			break;
		case 2:
			basic_damage = 290;
			break;
		case 3:
			basic_damage = 330;
			break;
		default:
			basic_damage = 330;
			break;
	}
	if (_mana < 100) {
		return -1;
	}
	else {
		_mana = 0;
		result = basic_damage + 0.8 * _attack_damage;
		return result;
	}
}