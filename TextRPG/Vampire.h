#pragma once
#include "Monster.h"

class Vampire : public Monster
{
	//-흡혈귀
	// 	- 정보 : 이름, 체력, 공격력, 방어력
	//	- 기능 : 공격 하기, 흡혈, 방어 하기, 박쥐화

	// 공격기능
	//  - 흡혈(10회복)
	// 
	// 방어기능
	//  - 50% 확률로 회피
	//  - 50% 확률로 대미지 2배
	//

public:
	virtual void Attack(Warrior& warrior);
	virtual int DamageOnDefence(int damage);
	virtual void Defend();

public:
	Vampire(const char* name, int hp, int atk, int def);
	~Vampire() = default;

};

