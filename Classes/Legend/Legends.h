#ifndef LEGEND_H
#define LEGEND_H

#include "Legend/BaseLegend.h"
#include "Legend/LegendInfos.h"


//在每个英雄里面多加一个参数type，以表示此英雄的类别
//并在Legend里面加一个返回此英雄类别的函数
enum legendType
{
	aphelios=1, caitlyn=2, ezreal=3, lucian=4, miss_fortune=5, graves=6,
};

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
		LegendInfo* info = new ApheliosInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new CaitlynInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new EzrealInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new LucianInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new Miss_FortuneInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new GravesInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new VarusInfo();
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

	virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};

//Varus, Katarina, Akali, Annie,

//ap

class Katarina :public Legend
{
public:
	Katarina(LegendInfo* const info)
		: Legend(info) { }
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new KatarinaInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new AkaliInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new AnnieInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new ViktorInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new SonaInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new JhinInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new ViegoInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new QiyanaInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new KaynInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new Bel_VethInfo();

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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new EkkoInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new RivenInfo();

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
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new FioraInfo();
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
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new CamilleInfo();
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
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new IreliaInfo();
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
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new SettInfo();
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
		LegendInfo* info = new GanplankInfo();
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
	
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new ThreshInfo();
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
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new Renata_GlascInfo();
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
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new RakanInfo();
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
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new BardInfo();
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
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new NautilusInfo();
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
	int abilityAttack();

	static LegendInfo* createInfo()
	{
		LegendInfo* info = new PykeInfo();
		if (info == NULL) {
			throw "Error";
		}
		else {
			return info;
		}
	}

	virtual const char* getImagePath() { return "Peashooter/Peashooter_0.png"; }
};
#endif
