#pragma once

#include "Entity.h"
#include "Monster.h"

class Monster;

// - 주인공 캐릭터(검사)
//	- 정보 : 이름, 체력, 공격력, 방어력
//  - 기능 : 공격 하기, 방어 하기

// 공격 기능
//  - 검을 휘두른다.
//  - 엔티티는 대미지를 입는다. 
//  - 엔티티의 방어 여부에 따라서, 대미지가 다르게 적용된다.
//  - 방어를 했을때 -> 캐릭터마다 다르다.
//  - 방어를 안했을때 -> 방어력 만큼만 공격력을 감소
//  - 엔티티의 체력이 0이 되면 죽는다.
//
// 방어 기능
//	- 검으로 막는다.
//  - 공격력 만큼 방어력이 증가. 
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

