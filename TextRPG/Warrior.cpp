#include "Warrior.h"

void Warrior::Attack(Monster& monster)
{
	defence = false;
	cout << "검사 " << name << "은(는) 검을 휘둘렀다!" << endl;
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
	cout << "검사 " << name << "은(는) 검으로 방어 했다!" << endl;
}

Warrior::Warrior(const char* name, int hp, int atk, int def)
	:Entity(name, hp, atk, def)
{
}
