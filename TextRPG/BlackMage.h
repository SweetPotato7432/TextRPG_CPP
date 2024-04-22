#pragma once
#include "Monster.h"

//	- �渶����
//		- ���� : �̸�, ü��, ���ݷ�, ����, ����, ����(�ִ� 100)
//		- ��� : ���� �ϱ�, ���� ����(����), ��� �ϱ�

// �׻� ���� ����(10 ȸ��)
// 
// �����ϱ�
// - ������ �ֵθ���
// - ������ �����ϸ� ������ ���(�Ϲ� ���ݷ�)
// ���� ����
// - ���� ���� ���(���� ���ݷ�)
//	- ���簡 ����� ����
//	- ���� ����
// - ������ ���� ���� ����(30 �Ҹ�)
// - ������ ����ϸ� ���� ���� ���
// 
// 
// ����ϱ�
// - ���� ��
//	- ü�� ��� ������ ��� ���ݷ¸�ŭ �Ҹ�
//

class BlackMage : public Monster
{
private:
	int magicAtk, mp;
	const int requiredMp = 30;
	const int restoredMp = 10;

public:
	virtual void Attack(Warrior& warrior);

	virtual int DamageOnDefence(int damage);
	virtual void TakeDamage(int damage);
	virtual void Defend();
	virtual void Show();


private:
	void UseMp(int mp); // ���� ��� ���
	void RestoreMp(int mp); // ���� ȸ�� ���

public :
	BlackMage(const char* name, int hp, int atk, int def, int magicAtk, int mp);
	~BlackMage() = default;
};

