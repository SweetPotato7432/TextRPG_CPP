#include "Dragon.h"

// 공격 기능
//  - 브레스
void Dragon::Attack(Warrior& warrior)
{
	defence = false;

	cout << "드래곤 " << name << "은(는) 브레스를 사용했다!" << endl;
	warrior.TakeDamage(atk);
}
// 방어 기능
//  - 방어력이 2배 증가
int Dragon::DamageOnDefence(int damage)
{
	

	int calcDamage = damage - def * 2;
	if (calcDamage <= 0) {
		calcDamage = 1;
	}
	return calcDamage;
}

void Dragon::Defend()
{
	Entity::Defend();
	cout << "드래곤 " << name << "은(는) 방어 자세를 취했다!" << endl;

}

Dragon::Dragon(const char* name, int hp, int atk, int def)
	:Monster(name, hp, atk, def)
{
}
