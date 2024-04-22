#include "Vampire.h"

void Vampire::Attack(Warrior& warrior)
{
	defence = false;

	cout << "흡혈귀 " << name << "은(는) 흡혈을 사용했다!" << endl;
	warrior.TakeDamage(atk);
	cout << "흡혈귀 " << name << "은(는) 체력을 10만큼 회복했다!" << endl;
	hp += 10;
	
}

int Vampire::DamageOnDefence(int damage)
{
	

	// 0.0f ~ 1.0f까지의 실수 중. 0.5f보다 작거나 같은 실수가 나올 확률 = 50%
	// 확률 50%를 구현한 코드
	bool dodgeSuccess = Random::Range(0.0f, 1.0f) <= 0.5f;
	if (dodgeSuccess) { // 회피에 성공했을때
		cout << "흡혈귀 " << name << "은(는) 박쥐로 변신하여 공격을 회피했다!" << endl;
		return 0;
	}
	else { // 회피에 실패 했을때
		cout << "흡혈귀 " << name << "은(는) 박쥐로 변신 도중 공격을 받았다!" << endl;
		int calcDamage = damage * 2 - def;

		return calcDamage;
	}
}

void Vampire::Defend()
{
	Entity::Defend();
	cout << "흡혈귀 " << name << "은(는) 박쥐로 변신을 시도했다!" << endl;

}

Vampire::Vampire(const char* name, int hp, int atk, int def)
	:Monster(name, hp, atk, def)
{
}
