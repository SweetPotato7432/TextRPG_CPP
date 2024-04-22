#include "Dragon.h"

// ���� ���
//  - �극��
void Dragon::Attack(Warrior& warrior)
{
	defence = false;

	cout << "�巡�� " << name << "��(��) �극���� ����ߴ�!" << endl;
	warrior.TakeDamage(atk);
}
// ��� ���
//  - ������ 2�� ����
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
	cout << "�巡�� " << name << "��(��) ��� �ڼ��� ���ߴ�!" << endl;

}

Dragon::Dragon(const char* name, int hp, int atk, int def)
	:Monster(name, hp, atk, def)
{
}
