#pragma once
#include "Legend/BaseLegend.h"

//adc
class Aphelios : public Legend
{
public:
	Aphelios(LegendInfo* const info)
		: Legend(info) { }
	//Aphelios() :Legend("Aphelios", 580, 2)
	//{
	//	_attack_damage = 70;
	//	_armor = 26;
	//	_critical_strike_chance = 10;
	//	_range = 4;
	//}
	int abilityAttack();

	// 由于英雄的信息指针只由玩家信息保管，因此不做特殊处理，生成的指针统一由 PlayerInfo 销毁
	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};

// TODO: createInfo 暂未改，仅为复制补贴的 Aphelios 的 createInfo
// 另外所有英雄默认贴图为豌豆射手，待修改
class Caitlyn :public Legend
{
public:
	Caitlyn(LegendInfo* const info)
		: Legend(info) { }
	//Caitlyn() :Legend("Caitlyn", 480, 4)
	//{
	//	_attack_damage = 62;
	//	_armor = 28;
	//	_critical_strike_chance = 10;
	//	_range = 5;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



class Ezreal :public Legend
{
public:
	Ezreal(LegendInfo* const info)
		: Legend(info) { }
	//Ezreal() :Legend("Ezreal", 600, 2)
	//{
	//	_attack_damage = 60;
	//	_armor = 24;
	//	_critical_strike_chance = 10;
	//	_range = 4;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};

class Lucian :public Legend
{
public:
	Lucian(LegendInfo* const info)
		: Legend(info) { }
	//Lucian() :Legend("Lucian", 641, 2)
	//{
	//	_attack_damage = 60;
	//	_armor = 28;
	//	_critical_strike_chance = 10;
	//	_range = 3;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



class Miss_Fortune :public Legend
{
public:
	Miss_Fortune(LegendInfo* const info)
		: Legend(info) { }
	//Miss_Fortune() :Legend("Miss_Fortune", 640, 2)
	//{
	//	_attack_damage = 52;
	//	_armor = 28;
	//	_critical_strike_chance = 10;
	//	_range = 4;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



class Graves :public Legend
{
public:
	Graves(LegendInfo* const info)
		: Legend(info) { }
	//Graves() :Legend("Graves", 625, 2)
	//{
	//	_attack_damage = 68;
	//	_armor = 33;
	//	_critical_strike_chance = 10;
	//	_range = 3;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



class Varus :public Legend
{
public:
	Varus(LegendInfo* const info)
		: Legend(info) { }
	//Varus() :Legend("Varus", 600, 2)
	//{
	//	_attack_damage = 62;
	//	_armor = 27;
	//	_critical_strike_chance = 10;
	//	_range = 4;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



//ap

class Katarina :public Legend
{
public:
	Katarina(LegendInfo* const info)
		: Legend(info) { }
	//Katarina() :Legend("Katarina", 672, 2)
	//{
	//	_attack_damage = 58;
	//	_armor = 28;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



class Akali :public Legend
{
public:
	Akali(LegendInfo* const info)
		: Legend(info) { }
	//Akali() :Legend("Akali", 570, 2)
	//{
	//	_attack_damage = 62;
	//	_armor = 23;
	//	_critical_strike_chance = 10;
	//	_range = 4;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



class Annie :public Legend
{
public:
	Annie(LegendInfo* const info)
		: Legend(info) { }
	//Annie() :Legend("Annie", 594, 2)
	//{
	//	_attack_damage = 50;
	//	_armor = 19;
	//	_critical_strike_chance = 10;
	//	_range = 4;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Viktor :public Legend
{
public:
	Viktor(LegendInfo* const info)
		: Legend(info) { }
	//Viktor() :Legend("Viktor", 600, 2)
	//{
	//	_attack_damage = 53;
	//	_armor = 23;
	//	_critical_strike_chance = 10;
	//	_range = 4;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Sona :public Legend
{
public:
	Sona(LegendInfo* const info)
		: Legend(info) { }
	//Sona() :Legend("Sona", 550, 2)
	//{
	//	_attack_damage = 49;
	//	_armor = 26;
	//	_critical_strike_chance = 10;
	//	_range = 4;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Jhin :public Legend
{
public:
	Jhin(LegendInfo* const info)
		: Legend(info) { }
	//Jhin() :Legend("Jhin", 655, 2)
	//{
	//	_attack_damage = 70;
	//	_armor = 24;
	//	_critical_strike_chance = 10;
	//	_range = 4;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


//打野

class Viego :public Legend
{
public:
	Viego(LegendInfo* const info)
		: Legend(info) { }
	//Viego() :Legend("Viego", 630, 2)
	//{
	//	_attack_damage = 70;
	//	_armor = 34;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Qiyana :public Legend
{
public:
	Qiyana(LegendInfo* const info)
		: Legend(info) { }
	//Qiyana() :Legend("Qiyana", 590, 2)
	//{
	//	_attack_damage = 66;
	//	_armor = 28;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Kayn :public Legend
{
public:
	Kayn(LegendInfo* const info)
		: Legend(info) { }
	//Kayn() :Legend("Kayn", 600, 2)
	//{
	//	_attack_damage = 70;
	//	_armor = 28;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Bel_Veth :public Legend
{
public:
	Bel_Veth(LegendInfo* const info)
		: Legend(info) { }
	//Bel_Veth() :Legend("Bel_Veth", 610, 2)
	//{
	//	_attack_damage = 60;
	//	_armor = 32;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Ekko :public Legend
{
public:
	Ekko(LegendInfo* const info)
		: Legend(info) { }
	//Ekko() :Legend("Ekko", 655, 2)
	//{
	//	_attack_damage = 58;
	//	_armor = 32;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


//上单

class Riven : public Legend
{
public:
	Riven(LegendInfo* const info)
		: Legend(info) { }
	//Riven() :Legend("Riven", 630, 2)
	//{
	//	_attack_damage = 64;
	//	_armor = 33;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Fiora :public Legend
{
public:
	Fiora(LegendInfo* const info)
		: Legend(info) { }
	//Fiora() :Legend("Fiora", 620, 2)
	//{
	//	_attack_damage = 68;
	//	_armor = 33;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Camille :public Legend
{
public:
	Camille(LegendInfo* const info)
		: Legend(info) { }
	//Camille() :Legend("Camille", 646, 2)
	//{
	//	_attack_damage = 68;
	//	_armor = 33;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Irelia :public Legend
{
public:
	Irelia(LegendInfo* const info)
		: Legend(info) { }
	//Irelia() :Legend("Irelia", 590, 2)
	//{
	//	_attack_damage = 65;
	//	_armor = 36;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};

class Sett :public Legend
{
public:
	Sett(LegendInfo* const info)
		: Legend(info) { }
	//Sett() :Legend("Sett", 670, 2)
	//{
	//	_attack_damage = 60;
	//	_armor = 33;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Ganplank :public Legend
{
public:
	Ganplank(LegendInfo* const info)
		: Legend(info) { }
	//Ganplank() :Legend("Ganplank", 600, 2)
	//{
	//	_attack_damage = 64;
	//	_armor = 31;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


//辅助

class Thresh :public Legend
{
public:
	Thresh(LegendInfo* const info)
		: Legend(info) { }
	//Thresh() :Legend("Thresh", 1000, 2)
	//{
	//	_attack_damage = 56;
	//	_armor = 31;
	//	_critical_strike_chance = 10;
	//	_range = 3;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Renata_Glasc :public Legend
{
public:
	Renata_Glasc(LegendInfo* const info)
		: Legend(info) { }
	//Renata_Glasc() :Legend("Renata_Glasc", 500, 2)
	//{
	//	_attack_damage = 56;
	//	_armor = 28;
	//	_critical_strike_chance = 10;
	//	_range = 4;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Rakan :public Legend
{
public:
	Rakan(LegendInfo* const info)
		: Legend(info) { }
	//Rakan() :Legend("Rakan", 1000, 2)
	//{
	//	_attack_damage = 62;
	//	_armor = 32;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Bard :public Legend
{
public:
	Bard(LegendInfo* const info)
		: Legend(info) { }
	//Bard() :Legend("Bard", 1200, 2)
	//{
	//	_attack_damage = 52;
	//	_armor = 34;
	//	_critical_strike_chance = 10;
	//	_range = 4;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Nautilus :public Legend
{
public:
	Nautilus(LegendInfo* const info)
		: Legend(info) { }
	//Nautilus() :Legend("Nautilus", 1600, 2)
	//{
	//	_attack_damage = 50;
	//	_armor = 39;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Pyke :public Legend
{
public:
	Pyke(LegendInfo* const info)
		: Legend(info) { }
	//Pyke() :Legend("Pyke", 900, 2)
	//{
	//	_attack_damage = 70;
	//	_armor = 45;
	//	_critical_strike_chance = 10;
	//	_range = 1;
	//}
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};

