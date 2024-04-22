#pragma once
#include <iostream>
#include "Random.h"
using namespace std;

class Entity
{
protected:
	char* name;
	int hp, atk, def;
	bool defence;// ��� ����

public:
	void DecreaseDef(int amount);

public:
	
	virtual int DamageOnDefence(int damage) = 0;
	virtual void TakeDamage(int damage);
	virtual void Defend();
	// �й� ����
	bool IsDefeated();
	virtual void Show();


public:
	Entity(const char* name, int hp, int atk, int def);
	virtual ~Entity(); // �Ҹ��� ����ȭ
};

