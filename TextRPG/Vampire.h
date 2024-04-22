#pragma once
#include "Monster.h"

class Vampire : public Monster
{
	//-������
	// 	- ���� : �̸�, ü��, ���ݷ�, ����
	//	- ��� : ���� �ϱ�, ����, ��� �ϱ�, ����ȭ

	// ���ݱ��
	//  - ����(10ȸ��)
	// 
	// �����
	//  - 50% Ȯ���� ȸ��
	//  - 50% Ȯ���� ����� 2��
	//

public:
	virtual void Attack(Warrior& warrior);
	virtual int DamageOnDefence(int damage);
	virtual void Defend();

public:
	Vampire(const char* name, int hp, int atk, int def);
	~Vampire() = default;

};

