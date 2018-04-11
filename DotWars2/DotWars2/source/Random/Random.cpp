#include "Random.h"

// �R���X�g���N�^
Random::Random()
	: mMt(mRandDev())
{

}
Random::Random(int seed)
	: mMt(seed)
{}

void Random::SetSeed(int seed)
{
	mMt.seed(seed);
}

// �����^�̗����𐶐�����i�ŏ��l�A�ő�l�j
int Random::Range(int min, int max)
{
	// min����max�܂ł͈̔͐ݒ�
	std::uniform_int_distribution<> rand(min, max - 1);

	// �͈͓��ŗ����𐶐����A�Ԃ�
	return rand(mMt);
}

// �����^�̗����𐶐�����i�ŏ��l�A�ő�l�j
float Random::Range(float min, float max)
{
	// min����max�܂ł͈̔͐ݒ�
	std::uniform_real_distribution<float> rand(min, max);

	// �͈͓��ŗ����𐶐����A�Ԃ�
	return rand(mMt);
}

// �����^�̗����𐶐�����i�N�_�l�A���U�l�j
float Random::Point(float point, float variance)
{
	// point�𒆐S��variance�̒l�ŕ��U���ꂽ�͈͐ݒ�
	std::normal_distribution<float> rand(point, variance);

	// �͈͓��ŗ����𐶐����A�Ԃ�
	return rand(mMt);
}