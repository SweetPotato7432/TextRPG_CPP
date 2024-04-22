#include "Random.h"

random_device Random::rd;
mt19937_64 Random::gen(rd());

// random_device : ������ ��ġ(���� �����ϰ� ��ǻ���� �ϵ���� �߿��� � ���ڸ� ������ ��)
// mt19937 : mt(�޸��� Ʈ������) : ���� �õ�

// �ּҰ� �̻� ~ �ִ밪 ������ '����'�� ��ȯ.
// Range(1, 5) : 1 2 3 4 5
int Random::Range(int minInclusive, int maxInclusive)
{
    // �յ� ���� : ������ ���ڰ� �����ϰ� ���� �� �ֵ��� ��������.
    uniform_int_distribution<int> dis(minInclusive, maxInclusive);
    return dis(gen);
}

// �ּҰ� �̻� ~ �ִ밪 ������ '�Ǽ�'�� ��ȯ.
// Range(1.0f, 5.0f) : 1.0 ~ 5.0������ ������ �Ǽ� ��ȯ.
float Random::Range(float minInclusive, float maxInclusive)
{
    uniform_real_distribution<float> dis(minInclusive, maxInclusive);
    return dis(gen);
}
