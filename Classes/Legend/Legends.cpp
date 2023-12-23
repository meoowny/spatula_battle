#include "Legend/Legends.h"

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
		result = basic_damage + 4 * _attack_damage;
		return result;
	}
}

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
			basic_damage = 300;
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
