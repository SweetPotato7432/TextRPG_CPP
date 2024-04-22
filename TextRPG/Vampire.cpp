#include "Vampire.h"

void Vampire::Attack(Warrior& warrior)
{
	defence = false;

	cout << "������ " << name << "��(��) ������ ����ߴ�!" << endl;
	warrior.TakeDamage(atk);
	cout << "������ " << name << "��(��) ü���� 10��ŭ ȸ���ߴ�!" << endl;
	hp += 10;
	
}

int Vampire::DamageOnDefence(int damage)
{
	

	// 0.0f ~ 1.0f������ �Ǽ� ��. 0.5f���� �۰ų� ���� �Ǽ��� ���� Ȯ�� = 50%
	// Ȯ�� 50%�� ������ �ڵ�
	bool dodgeSuccess = Random::Range(0.0f, 1.0f) <= 0.5f;
	if (dodgeSuccess) { // ȸ�ǿ� ����������
		cout << "������ " << name << "��(��) ����� �����Ͽ� ������ ȸ���ߴ�!" << endl;
		return 0;
	}
	else { // ȸ�ǿ� ���� ������
		cout << "������ " << name << "��(��) ����� ���� ���� ������ �޾Ҵ�!" << endl;
		int calcDamage = damage * 2 - def;

		return calcDamage;
	}
}

void Vampire::Defend()
{
	Entity::Defend();
	cout << "������ " << name << "��(��) ����� ������ �õ��ߴ�!" << endl;

}

Vampire::Vampire(const char* name, int hp, int atk, int def)
	:Monster(name, hp, atk, def)
{
}
