#include "Random.h"

random_device Random::rd;
mt19937_64 Random::gen(rd());

// random_device : 랜덤한 장치(정말 랜덤하게 컴퓨터의 하드웨어 중에서 어떤 숫자를 가지고 옴)
// mt19937 : mt(메르센 트위스터) : 랜덤 시드

// 최소값 이상 ~ 최대값 이하의 '정수'를 반환.
// Range(1, 5) : 1 2 3 4 5
int Random::Range(int minInclusive, int maxInclusive)
{
    // 균등 분포 : 랜덤한 숫자가 균일하게 나올 수 있도록 설정해줌.
    uniform_int_distribution<int> dis(minInclusive, maxInclusive);
    return dis(gen);
}

// 최소값 이상 ~ 최대값 이하의 '실수'를 반환.
// Range(1.0f, 5.0f) : 1.0 ~ 5.0까지의 랜덤한 실수 반환.
float Random::Range(float minInclusive, float maxInclusive)
{
    uniform_real_distribution<float> dis(minInclusive, maxInclusive);
    return dis(gen);
}
