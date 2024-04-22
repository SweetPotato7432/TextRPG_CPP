#include "Entity.h"

void Entity::DecreaseDef(int amount)
{
	def -= amount;
	if (def < 0) {
		def = 0;
	}
	cout << name << "의 방어력이 " << amount << " 만큼 감소하였다." << endl;
}

//  - 엔티티는 대미지를 입는다.
//  - 엔티티의 방어 여부에 따라서, 대미지가 다르게 적용된다.
//  - 방어를 했을때 -> 캐릭터마다 다르다.
//  - 방어를 안했을때 -> 방어력 만큼만 공격력을 감소
//  - 엔티티의 체력이 0이 되면 죽는다.
void Entity::TakeDamage(int damage)
{
	int calcDamage = 0;
	if (defence) {
		defence = false;
		calcDamage = DamageOnDefence(damage);
		
	}
	else {
		calcDamage = damage - def;
		if (calcDamage <= 0) {
			calcDamage = 1;
		}
	}
	hp -= calcDamage;
	if (hp < 0) {
		hp = 0;
	}
	cout << name << "은(는)" << calcDamage << "의 피해를 입었다!" << endl;
	cout << "남은 체력 : " << hp << endl;
	
}

void Entity::Defend()
{
	defence = true;
}

bool Entity::IsDefeated()
{
	return hp <= 0;
}

void Entity::Show()
{
	cout << "이름 : " << name << endl;
	cout << "체력 : " << hp << endl;
	cout << "공격력 : " << atk << endl;
	cout << "방어력 : " << def << endl;

}


Entity::Entity(const char* name, int hp, int atk, int def)
	: hp(hp), atk(atk), def(def), defence(false)
{
	int length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

Entity::~Entity()
{
	if (name != nullptr) {
		delete[] name;
		name = nullptr;
	}
	
}

