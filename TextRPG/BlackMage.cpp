#include "BlackMage.h"

void BlackMage::Attack(Warrior& warrior)
{
	defence = false;

	if (mp >= 30) {
		// 저주 마법
		// - 저주 마법 사용(마법 공격력)
		//	- 전사가 대미지 입음
		//	- 방어력 감소(3)
		// - 마법을 쓰면 마나 감소(30 소모)
		// - 마나가 충분하면 저주 마법 사용
		cout << "흑마법사 " << name << "은(는) 저주 마법을 시전했다!" << endl;
		warrior.TakeDamage(magicAtk);
		warrior.DecreaseDef(3);
		UseMp(requiredMp);
	}
	else {
		// 지팡이 공격
		// - 지팡이 휘두르기
		// - 마나가 부족하면 지팡이 사용(일반 공격력)
		cout << "흑마법사 " << name << "은(는) 지팡이를 휘둘렀다!" << endl;
		warrior.TakeDamage(atk);
		RestoreMp(restoredMp);
	}
}

// 방어하기
// - 마나 방어막
//	- 체력 대신 마나가 대신 공격력만큼 소모
int BlackMage::DamageOnDefence(int damage)
{
	

	return damage;
}

void BlackMage::TakeDamage(int damage)
{
	int calcDamage = 0;
	if (defence) {
		defence = false;
		calcDamage = DamageOnDefence(damage);
		
		// 남아있는 마나가 대미지보다 적을 경우
		// 마나 소모 후, 남은 대미지는 체력을 소모한다.

		int remain = calcDamage - mp;
		UseMp(calcDamage);
		if (remain > 0) {
			damage = remain;
		}
		else {
			return;
		}
		
	}
	
	calcDamage = damage - def;
	if (calcDamage <= 0) {
		calcDamage = 1;
	}
	hp -= calcDamage;
	if (hp < 0) {
		hp = 0;
	}
	cout << name << "은(는)" << calcDamage << "의 피해를 입었다!" << endl;

	cout << "남은 체력 : " << hp<<endl;
}

void BlackMage::Defend()
{
	Entity::Defend();
	cout << "흑마법사 " << name << "은(는) 마나 방어막을 시전했다!" << endl;
}

void BlackMage::Show()
{
	Entity::Show();
	cout << "마력 : " << magicAtk << endl;
	cout << "마나 : " << mp << endl;

}

void BlackMage::UseMp(int mp)
{
	this->mp -= mp;
	// 추가 : 마나가 0이하로 떨어졌을시
	if (this->mp < 0) {
		this->mp = 0;
	}
	cout << "흑마법사 " << name << "은(는) " << mp << "의 마나를 소모했다." << endl;
	cout << "남은 마나 : " << this->mp << endl;
}

void BlackMage::RestoreMp(int mp)
{
	this->mp += mp;
	cout << "흑마법사 " << name << "은(는) " << mp << "의 마나를 회복했다." << endl;
	cout << "남은 마나 : " << this->mp << endl;
}

BlackMage::BlackMage(const char* name, int hp, int atk, int def, int magicAtk, int mp)
	:Monster(name,hp,atk,def), magicAtk(magicAtk),mp(mp)
{
}
