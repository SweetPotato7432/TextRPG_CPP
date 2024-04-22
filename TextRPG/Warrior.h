#pragma once

#include "Entity.h"
#include "Monster.h"

class Monster;

// - ���ΰ� ĳ����(�˻�)
//	- ���� : �̸�, ü��, ���ݷ�, ����
//  - ��� : ���� �ϱ�, ��� �ϱ�

// ���� ���
//  - ���� �ֵθ���.
//  - ��ƼƼ�� ������� �Դ´�. 
//  - ��ƼƼ�� ��� ���ο� ����, ������� �ٸ��� ����ȴ�.
//  - �� ������ -> ĳ���͸��� �ٸ���.
//  - �� �������� -> ���� ��ŭ�� ���ݷ��� ����
//  - ��ƼƼ�� ü���� 0�� �Ǹ� �״´�.
//
// ��� ���
//	- ������ ���´�.
//  - ���ݷ� ��ŭ ������ ����. 
//

class Warrior : public Entity
{
public:
	void Attack(Monster& monster);
	virtual int DamageOnDefence(int damage);

	virtual void Defend();


public:
	Warrior(const char* name, int hp, int atk, int def);
	~Warrior() = default;
};

