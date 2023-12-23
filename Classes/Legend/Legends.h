#pragma once
#include "Legend/BaseLegend.h"

//adc
class Aphelios : public Legend
{
public:
	Aphelios() :Legend("Aphelios", 580, 2)
	{
		_attack_damage = 70;
		_armor = 26;
		_critical_strike_chance = 10;
		_range = 4;
	}
	int ability_attack();
};

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


//¥Ú“∞

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


//…œµ•

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


//∏®÷˙

class Thresh :public Legend
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


class Renata_Glasc :public Legend
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


class Rakan :public Legend
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


class Bard :public Legend
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

