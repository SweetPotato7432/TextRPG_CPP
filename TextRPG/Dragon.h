#pragma once
#include "Monster.h"

// -드래곤
//	- 정보 : 이름, 체력, 공격력, 방어력
//	- 기능 : 공격 하기, 브레스, 방어 하기, 비행

// 공격 기능
//  - 브레스
// 
// 방어 기능
//  - 방어력이 2배 증가
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

