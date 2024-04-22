#include <iostream>
using namespace std;

#include "Warrior.h"
#include "BlackMage.h"
#include "Dragon.h"
#include "Vampire.h"

//<TextRPG>
// - ���ΰ� ĳ����(�˻�)
//	- ���� : �̸�, ü��, ���ݷ�, ����
//  - ��� : ���� �ϱ�, ��� �ϱ�
// 
// - ���� 3����
//	- �渶����
//		- ���� : �̸�, ü��, ���ݷ�, ����, ����, ����, ��Ÿ��
//		- ��� : ���� �ϱ�(���� ����), ��� �ϱ�
//  - �巡��
//		- ���� : �̸�, ü��, ���ݷ�, ����
//		- ��� : ���� �ϱ�(�극��), ��� �ϱ�
//  - ������
// 		- ���� : �̸�, ü��, ���ݷ�, ����
//		- ��� : ���� �ϱ�(����), ��� �ϱ�(����ȭ)

// ������ �����ϱ� ���� �˻�� ������ �ൿ ����

// ���ݱ��
//	- ��ƼƼ�� ������� �Դ´�. 
//  - ��ƼƼ�� ��� ���ο� ����, ������� �ٸ��� ����ȴ�.
//  - �� ������ -> ĳ���͸��� �ٸ���.
//  - �� �������� -> ���� ��ŭ�� ���ݷ��� ����
//  - ��ƼƼ�� ü���� 0�� �Ǹ� �״´�.

// ���� ���
// ���� ���� : ���� vs 3���� ������ ���� �� �ϳ�
// �� �� �ϳ��� �й��Ҷ����� ����
// 
// ���� �й� : ���� ����
// ���� �й� : ���� ����
// 
// �й� Ȯ�� : Entity�� ��� ���� hp�� 0���� �۰ų� ����.
// 

Monster* CreateRandomMonster();
int SelectMenu();

int main()
{
	Warrior warrior("ȫ�浿", 300, 10, 5);

	// ���ʹ� �����ϰ� �����Ǳ� ������ � ��������� �������ϴ��� ���� �� ����
	// �ٸ� ���ʹ� ��� MonsterŬ������ ��� �ޱ� ������ Monster*�� �����Ҵ��� �غ� ��
	Monster* pMonster;

	pMonster = CreateRandomMonster();
	int count = 1;
	while (1)
	{
		cout <<"<" << count<<"��° ����>" << endl;

		warrior.Show();
		cout << "-------------------------------------------" << endl;
		pMonster->Show();
		cout << endl;
		int index = SelectMenu();

		system("cls"); // ȭ�� �ʱ�ȭ

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
			cout << "�������� �й��Ͽ���..." << endl;
			cout << "�� " << count << "���� ������ �߽��ϴ�." << endl;
			delete pMonster;
			break;
		}
		else if (pMonster->IsDefeated()) {
			cout << "�������� �¸��ߴ�!" << endl;
			cout << "���� ������ �̵� �մϴ�." << endl;

			count++;
			
			delete pMonster;
			pMonster = CreateRandomMonster();
			
		}
		else {
			cout << "��� ���� �Ϸ��� Enter Ű�� �����ÿ�." << endl;
		}
		getchar(); //�Է� ����		
		system("cls");

	}

	return 0;
}

Monster* CreateRandomMonster()
{
	// 0 : �渶����
	// 1 : �巡��
	// 2 : ������
	int index = Random::Range(0, 2);
	Monster* monster = nullptr;
	switch (index)
	{
		case 0:
			monster = new BlackMage("��ö��", 100, 3, 3, 10, 100);
			break;
		case 1:
			monster = new Dragon("�����", 150, 8 ,5);
			break;
		case 2:
			monster = new Vampire("������", 80, 10, 0);
			break;
	}
	return monster;
}

int SelectMenu()
{
	int index;
	cout << "<�޴�>" << endl;
	cout << "1. ����" << endl;
	cout << "2. ���" << endl;
	cout << "�ൿ�� �����Ͻÿ� : ";
	cin >> index;
	cin.ignore(); // �Է� ���ۿ� �ִ� ������ �ϳ�(1����Ʈ) �����ϴ� �Լ�

	return index;	
}
