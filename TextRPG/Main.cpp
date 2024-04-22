#include <iostream>
using namespace std;

#include "Warrior.h"
#include "BlackMage.h"
#include "Dragon.h"
#include "Vampire.h"

//<TextRPG>
// - 주인공 캐릭터(검사)
//	- 정보 : 이름, 체력, 공격력, 방어력
//  - 기능 : 공격 하기, 방어 하기
// 
// - 몬스터 3가지
//	- 흑마법사
//		- 정보 : 이름, 체력, 공격력, 방어력, 마력, 마나, 쿨타임
//		- 기능 : 공격 하기(마법 공격), 방어 하기
//  - 드래곤
//		- 정보 : 이름, 체력, 공격력, 방어력
//		- 기능 : 공격 하기(브레스), 방어 하기
//  - 흡혈귀
// 		- 정보 : 이름, 체력, 공격력, 방어력
//		- 기능 : 공격 하기(흡혈), 방어 하기(박쥐화)

// 전투를 진행하기 전에 검사와 몬스터의 행동 설정

// 공격기능
//	- 엔티티는 대미지를 입는다. 
//  - 엔티티의 방어 여부에 따라서, 대미지가 다르게 적용된다.
//  - 방어를 했을때 -> 캐릭터마다 다르다.
//  - 방어를 안했을때 -> 방어력 만큼만 공격력을 감소
//  - 엔티티의 체력이 0이 되면 죽는다.

// 전투 기능
// 무한 전투 : 전사 vs 3가지 랜덤한 몬스터 중 하나
// 둘 중 하나가 패배할때까지 전투
// 
// 전사 패배 : 게임 오버
// 몬스터 패배 : 다음 몬스터
// 
// 패배 확인 : Entity의 멤버 변수 hp가 0보다 작거나 같다.
// 

Monster* CreateRandomMonster();
int SelectMenu();

int main()
{
	Warrior warrior("홍길동", 300, 10, 5);

	// 몬스터는 랜덤하게 생성되기 때문에 어떤 저장공간을 만들어야하는지 정할 수 없음
	// 다만 몬스터는 모두 Monster클래스를 상속 받기 때문에 Monster*로 동적할당할 준비를 함
	Monster* pMonster;

	pMonster = CreateRandomMonster();
	int count = 1;
	while (1)
	{
		cout <<"<" << count<<"번째 전투>" << endl;

		warrior.Show();
		cout << "-------------------------------------------" << endl;
		pMonster->Show();
		cout << endl;
		int index = SelectMenu();

		system("cls"); // 화면 초기화

		switch (index)
		{
			case 1: 
				{
					index = Random::Range(1, 2);
					if (index == 1) {
						warrior.Attack(*pMonster);
						cout << "-------------------------------------------" << endl;
						pMonster->Attack(warrior);
					}
					else {
						pMonster->Defend();
						cout << "-------------------------------------------" << endl;
						warrior.Attack(*pMonster);
					}
				}
				break;
			case 2:
				warrior.Defend();
				cout << "-------------------------------------------" << endl;
				index = Random::Range(1, 2);
				if (index == 1) {
					pMonster->Attack(warrior);
				}
				else {
					pMonster->Defend();
				}
				break;
		}

		if (warrior.IsDefeated()) {
			cout << "전투에서 패배하였다..." << endl;
			cout << "총 " << count << "번의 전투를 했습니다." << endl;
			delete pMonster;
			break;
		}
		else if (pMonster->IsDefeated()) {
			cout << "전투에서 승리했다!" << endl;
			cout << "다음 전투로 이동 합니다." << endl;

			count++;
			
			delete pMonster;
			pMonster = CreateRandomMonster();
			
		}
		else {
			cout << "계속 진행 하려면 Enter 키를 누르시오." << endl;
		}
		getchar(); //입력 대기용		
		system("cls");

	}

	return 0;
}

Monster* CreateRandomMonster()
{
	// 0 : 흑마법사
	// 1 : 드래곤
	// 2 : 흡혈귀
	int index = Random::Range(0, 2);
	Monster* monster = nullptr;
	switch (index)
	{
		case 0:
			monster = new BlackMage("김철수", 100, 3, 3, 10, 100);
			break;
		case 1:
			monster = new Dragon("용용이", 150, 8 ,5);
			break;
		case 2:
			monster = new Vampire("나영희", 80, 10, 0);
			break;
	}
	return monster;
}

int SelectMenu()
{
	int index;
	cout << "<메뉴>" << endl;
	cout << "1. 공격" << endl;
	cout << "2. 방어" << endl;
	cout << "행동을 선택하시오 : ";
	cin >> index;
	cin.ignore(); // 입력 버퍼에 있는 내용을 하나(1바이트) 제거하는 함수

	return index;	
}
