#include "Warrior.h"

void Warrior::Attack(Monster& monster)
{
	defence = false;
	cout << "�˻� " << name << "��(��) ���� �ֵѷ���!" << endl;
	monster.TakeDamage(atk);
}

int Warrior::DamageOnDefence(int damage)
{
	int calcDamage = damage - (atk + def);

	if (calcDamage <= 0) {
		calcDamage = 1;
	}

	return calcDamage;
}

void Warrior::Defend()
{
	Entity::Defend();
	cout << "�˻� " << name << "��(��) ������ ��� �ߴ�!" << endl;
}

Warrior::Warrior(const char* name, int hp, int atk, int def)
	:Entity(name, hp, atk, def)
{
}
