#include "Entity.h"

void Entity::DecreaseDef(int amount)
{
	def -= amount;
	if (def < 0) {
		def = 0;
	}
	cout << name << "�� ������ " << amount << " ��ŭ �����Ͽ���." << endl;
}

//  - ��ƼƼ�� ������� �Դ´�.
//  - ��ƼƼ�� ��� ���ο� ����, ������� �ٸ��� ����ȴ�.
//  - �� ������ -> ĳ���͸��� �ٸ���.
//  - �� �������� -> ���� ��ŭ�� ���ݷ��� ����
//  - ��ƼƼ�� ü���� 0�� �Ǹ� �״´�.
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
	cout << name << "��(��)" << calcDamage << "�� ���ظ� �Ծ���!" << endl;
	cout << "���� ü�� : " << hp << endl;
	
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
	cout << "�̸� : " << name << endl;
	cout << "ü�� : " << hp << endl;
	cout << "���ݷ� : " << atk << endl;
	cout << "���� : " << def << endl;

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

