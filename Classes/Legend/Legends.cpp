#include "Legend/Legends.h"

int Aphelios::abilityAttack()
{
	int ability_damage;
	int basic_damage;
	switch (getLevel()) {
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
		ability_damage = basic_damage + 0.2 * getAttackDamage();
		return ability_damage;
	}
}

int Caitlyn::abilityAttack() {
	int ability_damage;
	int basic_damage;
	switch (getLevel()) {
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
		ability_damage = basic_damage + 0.3 * getAttackDamage();
		return ability_damage;
	}
}

int Ezreal::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 0.9 * getAttackDamage();
		return result;
	}

}

int Lucian::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 2 * getAttackDamage();
		return result;
	}
}

int Miss_Fortune::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 0.85 * getAttackDamage();
		return result;
	}
}

int Graves::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 0.75 * getAttackDamage();
		return result;
	}
}

int Varus::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 3 * getAttackDamage();
		return result;
	}
}



//ap
int Katarina::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 2.85 * getAttackDamage();
		return result;
	}
}

int Akali::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 0.9 * getAttackDamage();
		return result;
	}
}

int Annie::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 0.65 * getAttackDamage();
		return result;
	}
}

int Viktor::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 0.9 * getAttackDamage();
		return result;
	}
}

int Sona::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 0.5 * getAttackDamage();
		return result;
	}
}

int Jhin::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 2 * getAttackDamage();
		return result;
	}
}

int Viego::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 2 * getAttackDamage();
		return result;
	}
}

int Qiyana::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 5 * getAttackDamage();
		return result;
	}
}

int Kayn::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 2 * getAttackDamage();
		return result;
	}
}

int Bel_Veth::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 4 * getAttackDamage();
		return result;
	}
}

int Ekko::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 1.5 * getAttackDamage();
		return result;
	}
}

int Riven::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 1.8 * getAttackDamage();
		return result;
	}
}

int Fiora::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 4 * getAttackDamage();
		return result;
	}
}

int Camille::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 6 * getAttackDamage();
		return result;
	}
}

int Irelia::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 0.9 * getAttackDamage();
		return result;
	}
}

int Sett::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 3 * getAttackDamage();
		return result;
	}
}

int Ganplank::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 2 * getAttackDamage();
		return result;
	}
}

int Thresh::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 1 * getAttackDamage();
		return result;
	}
}

int Renata_Glasc::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 1 * getAttackDamage();
		return result;
	}
}

int Rakan::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 1 * getAttackDamage();
		return result;
	}
}

int Bard::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 3 * getAttackDamage();
		return result;
	}
}

int Nautilus::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 0.8 * getAttackDamage();
		return result;
	}
}

int Pyke::abilityAttack()
{
	int basic_damage;
	int result;
	switch (getLevel()) {
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
		result = basic_damage + 0.8 * getAttackDamage();
		return result;
	}
}
