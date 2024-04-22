#pragma once
#include "Monster.h"

// -�巡��
//	- ���� : �̸�, ü��, ���ݷ�, ����
//	- ��� : ���� �ϱ�, �극��, ��� �ϱ�, ����

// ���� ���
//  - �극��
// 
// ��� ���
//  - ������ 2�� ����
//

class Dragon : public Monster
{
	

public:
	virtual void Attack(Warrior& warrior);
	virtual int DamageOnDefence(int damage);
	virtual void Defend();

public:
	Dragon(const char* name, int hp, int atk, int def);
	~Dragon() = default;
};

