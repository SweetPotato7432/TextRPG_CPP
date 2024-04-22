#include "BlackMage.h"

void BlackMage::Attack(Warrior& warrior)
{
	defence = false;

	if (mp >= 30) {
		// ���� ����
		// - ���� ���� ���(���� ���ݷ�)
		//	- ���簡 ����� ����
		//	- ���� ����(3)
		// - ������ ���� ���� ����(30 �Ҹ�)
		// - ������ ����ϸ� ���� ���� ���
		cout << "�渶���� " << name << "��(��) ���� ������ �����ߴ�!" << endl;
		warrior.TakeDamage(magicAtk);
		warrior.DecreaseDef(3);
		UseMp(requiredMp);
	}
	else {
		// ������ ����
		// - ������ �ֵθ���
		// - ������ �����ϸ� ������ ���(�Ϲ� ���ݷ�)
		cout << "�渶���� " << name << "��(��) �����̸� �ֵѷ���!" << endl;
		warrior.TakeDamage(atk);
		RestoreMp(restoredMp);
	}
}

// ����ϱ�
// - ���� ��
//	- ü�� ��� ������ ��� ���ݷ¸�ŭ �Ҹ�
int BlackMage::DamageOnDefence(int damage)
{
	

	return damage;
}

void BlackMage::TakeDamage(int damage)
{
	int calcDamage = 0;
	if (defence) {
		defence = false;
		calcDamage = DamageOnDefence(damage);
		
		// �����ִ� ������ ��������� ���� ���
		// ���� �Ҹ� ��, ���� ������� ü���� �Ҹ��Ѵ�.

		int remain = calcDamage - mp;
		UseMp(calcDamage);
		if (remain > 0) {
			damage = remain;
		}
		else {
			return;
		}
		
	}
	
	calcDamage = damage - def;
	if (calcDamage <= 0) {
		calcDamage = 1;
	}
	hp -= calcDamage;
	if (hp < 0) {
		hp = 0;
	}
	cout << name << "��(��)" << calcDamage << "�� ���ظ� �Ծ���!" << endl;

	cout << "���� ü�� : " << hp<<endl;
}

void BlackMage::Defend()
{
	Entity::Defend();
	cout << "�渶���� " << name << "��(��) ���� ���� �����ߴ�!" << endl;
}

void BlackMage::Show()
{
	Entity::Show();
	cout << "���� : " << magicAtk << endl;
	cout << "���� : " << mp << endl;

}

void BlackMage::UseMp(int mp)
{
	this->mp -= mp;
	// �߰� : ������ 0���Ϸ� ����������
	if (this->mp < 0) {
		this->mp = 0;
	}
	cout << "�渶���� " << name << "��(��) " << mp << "�� ������ �Ҹ��ߴ�." << endl;
	cout << "���� ���� : " << this->mp << endl;
}

void BlackMage::RestoreMp(int mp)
{
	this->mp += mp;
	cout << "�渶���� " << name << "��(��) " << mp << "�� ������ ȸ���ߴ�." << endl;
	cout << "���� ���� : " << this->mp << endl;
}

BlackMage::BlackMage(const char* name, int hp, int atk, int def, int magicAtk, int mp)
	:Monster(name,hp,atk,def), magicAtk(magicAtk),mp(mp)
{
}
