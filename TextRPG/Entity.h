#pragma once
#include <iostream>
#include "Random.h"
using namespace std;

class Entity
{
protected:
	char* name;
	int hp, atk, def;
	bool defence;// 방어 여부

public:
	void DecreaseDef(int amount);

public:
	
	virtual int DamageOnDefence(int damage) = 0;
	virtual void TakeDamage(int damage);
	virtual void Defend();
	// 패배 여부
	bool IsDefeated();
	virtual void Show();


public:
	Entity(const char* name, int hp, int atk, int def);
	virtual ~Entity(); // 소멸자 가상화
};

