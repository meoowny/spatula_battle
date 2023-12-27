#include "Legend/BaseLegend.h"

Legend* Legend::create(LegendInfo* const info)
{
	Legend* legend = new (std::nothrow) Legend(info);
	if (legend && legend->initWithFile(getImagePath())) {
		legend->autorelease();
		return legend;
	}
	else {
		CC_SAFE_DELETE(legend);
		return nullptr;
	}
}

bool Legend::levelUp()
{
	if (_info->_level >= 3) {
		return false;
	}
	else {
		_info->_level++;
		_info->_most_health *= 1.1;
		_health *= 1.1;
		//_critical_strike_chance += 10;
		_info->_attack_damage += 10;
		_info->_armor *= 1.2;
		return true;
	}

}
int Legend::getCost() const
{
	int result = _info->_cost;
	for (int i = 1; i < _info->_level; i++) {
		result = result * 3 - 1;
	}
	return result;
}

int Legend::getHealth() const
{
	if (_health <= 0)
		return 0;
	return _health;

}
//�������get������Ҫ���ƣ�
int Legend::getAttackDamage() const
{
	if (_info->_attack_damage <= 0)
		return 0;
	return _info->_attack_damage;
}

int Legend::getAttack()
{
	if (_mana < 100) {
		_mana += 10;  //ÿ�ι�������ʮ��������ÿ��100���ͷż���
		int result = _info->_attack_damage;
		if (rand() / RAND_MAX * 100 < _info->_critical_strike_chance)
			result *= 2;            //������ж��Ƿ񱩻�
		return result;  //�����˺�
	}
	else {
		_mana = 0;
		return abilityAttack();
	}
}

int Legend::beingAttack(int attack_damage)
{
	int be_damaged;
	if (_info->_armor >= 0) {
		double damage_reduction = _info->_armor / (_info->_armor + 100.0);  //�����˺����⣬�����˺����� = ���� / (���� + 100)
		be_damaged = (1 - damage_reduction) * attack_damage;  //�����ܵ����˺�
	}
	else {
		be_damaged = attack_damage;  //����С��0�����ܵ���ʵ�˺�
	}

	_health = _health - be_damaged;  //Ѫ�����ٺ���
	if (_health <= 0) {
		_health = 0;
		std::cout << "����������" << std::endl;
	}
	return be_damaged;
}


int Legend::beingHealed(int be_healed)
{
	_health = _health + be_healed;
	if (_health >= _info->_most_health) {
		_health = _info->_most_health;
	}
	return be_healed;
}

/*int _attack_damage;
int _armor;
int _critical_strike_chance;
int _range;*/


