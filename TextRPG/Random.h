#pragma once
#include <random>
using namespace std;

// mt19937_64 : 메르센 트위스터.(랜덤 시드 설정)

class Random
{
private:
	static random_device rd;
	static mt19937_64 gen;

public:
	static int Range(int minInclusive, int maxExclusive);
	static float Range(float minInclusive, float maxInclusive);
};

// 랜덤
// 적 비행기 추가
// 발사 간격.
// 

// 시간 측정
// 매 프레임마다 deltaTime을 계속 더한다.
// 언젠가는 [설정한 시간]보다 크거나 같아진다. = [설정한 시간]이 지났다.
// 실행할 코드를 작성.
// 누적했던 deltaTime을 초기화.

// 적 비행기 추가
// 원래 있던 Plane 클래스를 활용(추가 메서드, 추가 변수)

