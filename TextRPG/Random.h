#pragma once
#include <random>
using namespace std;

// mt19937_64 : �޸��� Ʈ������.(���� �õ� ����)

class Random
{
private:
	static random_device rd;
	static mt19937_64 gen;

public:
	static int Range(int minInclusive, int maxExclusive);
	static float Range(float minInclusive, float maxInclusive);
};

// ����
// �� ����� �߰�
// �߻� ����.
// 

// �ð� ����
// �� �����Ӹ��� deltaTime�� ��� ���Ѵ�.
// �������� [������ �ð�]���� ũ�ų� ��������. = [������ �ð�]�� ������.
// ������ �ڵ带 �ۼ�.
// �����ߴ� deltaTime�� �ʱ�ȭ.

// �� ����� �߰�
// ���� �ִ� Plane Ŭ������ Ȱ��(�߰� �޼���, �߰� ����)

