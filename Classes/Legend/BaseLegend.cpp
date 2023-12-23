#include "Legend/BaseLegend.h"

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
//�������get������Ҫ���ƣ�
int Legend::GetAttackDamage() const
{
	if (_attack_damage <= 0)
		return 0;
	return _attack_damage;
}

int Legend::GetAttack() 
{
	if (_mana < 100) {
		_mana += 10;  //ÿ�ι�������ʮ��������ÿ��100���ͷż���
		int result = _attack_damage;
		if (rand() / RAND_MAX * 100 < _critical_strike_chance)
			result *= 2;            //������ж��Ƿ񱩻�
		return result;  //�����˺�
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
		double damage_reduction = _armor / (_armor + 100.0);  //�����˺����⣬�����˺����� = ���� / (���� + 100)
		be_damaged = (1 - damage_reduction) * attack_damage;  //�����ܵ����˺�
	}
	else {
		be_damaged = attack_damage;  //����С��0�����ܵ���ʵ�˺�
	}

	_health = _health - be_damaged;  //Ѫ�����ٺ���
	if (_health <= 0) {
		_health = 0;
		cout << "����������" << endl;
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


