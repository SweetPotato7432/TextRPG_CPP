#pragma once
#include "Entity.h";
#include "Warrior.h"

class Warrior;

class Monster : public Entity
{
public :
	virtual void Attack(Warrior& warrior) = 0;

public:
	Monster(const char* name, int hp, int atk, int def);
	~Monster() = default;
};

