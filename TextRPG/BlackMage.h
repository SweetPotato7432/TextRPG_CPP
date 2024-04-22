#pragma once
#include "Monster.h"

//	- 흑마법사
//		- 정보 : 이름, 체력, 공격력, 방어력, 마력, 마나(최대 100)
//		- 기능 : 공격 하기, 마법 공격(저주), 방어 하기

// 항상 마나 충전(10 회복)
// 
// 공격하기
// - 지팡이 휘두르기
// - 마나가 부족하면 지팡이 사용(일반 공격력)
// 마법 공격
// - 저주 마법 사용(마법 공격력)
//	- 전사가 대미지 입음
//	- 방어력 감소
// - 마법을 쓰면 마나 감소(30 소모)
// - 마나가 충분하면 저주 마법 사용
// 
// 
// 방어하기
// - 마나 방어막
//	- 체력 대신 마나가 대신 공격력만큼 소모
//

class BlackMage : public Monster
{
private:
	int magicAtk, mp;
	const int requiredMp = 30;
	const int restoredMp = 10;

public:
	virtual void Attack(Warrior& warrior);

	virtual int DamageOnDefence(int damage);
	virtual void TakeDamage(int damage);
	virtual void Defend();
	virtual void Show();


private:
	void UseMp(int mp); // 마나 사용 기능
	void RestoreMp(int mp); // 마나 회복 기능

public :
	BlackMage(const char* name, int hp, int atk, int def, int magicAtk, int mp);
	~BlackMage() = default;
};

