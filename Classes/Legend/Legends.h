#pragma once
#include "Legend/BaseLegend.h"

//adc
class Aphelios : public Legend
{
public:
	Aphelios(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	// 由于英雄的信息指针只由玩家信息保管，因此不做特殊处理，生成的指针统一由 PlayerInfo 销毁
	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 580, 2, 70, 26, 30, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};

// TODO: createInfo 暂未改，仅为复制补贴的 Aphelios 的 createInfo
// 另外所有英雄默认贴图为豌豆射手，待修改
class Caitlyn :public Legend
{
public:
	Caitlyn(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Caitlyn", 480, 4, 62, 28, 30, 5);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



class Ezreal :public Legend
{
public:
	Ezreal(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Ezreal", 600, 2, 60, 24, 30, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};

class Lucian :public Legend
{
public:
	Lucian(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Lucian", 641, 2, 60, 28, 30, 3);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



class Miss_Fortune :public Legend
{
public:
	Miss_Fortune(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Miss_Fortune", 640, 2, 52, 28, 30, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



class Graves :public Legend
{
public:
	Graves(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Graves", 625, 2, 68, 33, 50, 3);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



class Varus :public Legend
{
public:
	Varus(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Varus", 600, 2, 62, 27, 30, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



//ap

class Katarina :public Legend
{
public:
	Katarina(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Katarina", 672, 2, 58, 28, 10, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



class Akali :public Legend
{
public:
	Akali(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Akali", 570, 2, 62, 23, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};



class Annie :public Legend
{
public:
	Annie(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Annie", 594, 2, 50, 19, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Viktor :public Legend
{
public:
	Viktor(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 600, 2, 53, 23, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Sona :public Legend
{
public:
	Sona(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Sona", 550, 2, 49, 26, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Jhin :public Legend
{
public:
	Jhin(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Jhin", 655, 2, 70, 24, 40, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


//打野

class Viego :public Legend
{
public:
	Viego(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Viego", 630, 2, 70, 34, 70, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Qiyana :public Legend
{
public:
	Qiyana(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Qiyana", 590, 2, 66, 28, 10, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Kayn :public Legend
{
public:
	Kayn(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Kayn", 600, 2, 70, 28, 10, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Bel_Veth :public Legend
{
public:
	Bel_Veth(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Bel_Veth", 610, 2, 60, 32, 20, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Ekko :public Legend
{
public:
	Ekko(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Ekko", 655, 2, 58, 32, 10, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


//上单

class Riven : public Legend
{
public:
	Riven(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Riven", 630, 2, 64, 33, 10, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Fiora :public Legend
{
public:
	Fiora(LegendInfo* const info)
		: Legend(info) { }
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Fiora", 620, 2, 68, 33, 10, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Camille :public Legend
{
public:
	Camille(LegendInfo* const info)
		: Legend(info) { }
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Camille", 646, 2, 68, 33, 5, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Irelia :public Legend
{
public:
	Irelia(LegendInfo* const info)
		: Legend(info) { }
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Irelia", 590, 2, 65, 36, 10, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};

class Sett :public Legend
{
public:
	Sett(LegendInfo* const info)
		: Legend(info) { }
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Aphelios", 670, 2, 60, 33, 10, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
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
		LegendInfo* info = new LegendInfo("Ganplank", 600, 2, 64, 31, 10, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


//辅助

class Thresh :public Legend
{
public:
	Thresh(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Thresh", 1000, 2, 10, 31, 0, 3);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Renata_Glasc :public Legend
{
public:
	Renata_Glasc(LegendInfo* const info)
		: Legend(info) { }
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Renta_Glasc", 700, 2, 10, 28, 20, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Rakan :public Legend
{
public:
	Rakan(LegendInfo* const info)
		: Legend(info) { }
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Rakan", 1000, 2, 10, 32, 10, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Bard :public Legend
{
public:
	Bard(LegendInfo* const info)
		: Legend(info) { }
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Bard", 1200, 2, 10, 34, 10, 4);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Nautilus :public Legend
{
public:
	Nautilus(LegendInfo* const info)
		: Legend(info) { }
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Nautilus", 1600, 2, 5, 39, 10, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};


class Pyke :public Legend
{
public:
	Pyke(LegendInfo* const info)
		: Legend(info) { }
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LegendInfo("Pyke", 900, 2, 60, 45, 10, 1);
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

    static const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};

