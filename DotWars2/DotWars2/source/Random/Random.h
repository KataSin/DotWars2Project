
#pragma once

#include <random>

class Random
{
private:
	Random();
	Random(int seed);
	~Random() = default;

public:
	static Random &GetInstance() {
		static Random m;
		return m;
	}

	///<summary>
	/// �V�[�h���Z�b�g����
	///</summary>
	void SetSeed(int seed);

	///<summary>
	/// �����^�̗����𐶐�����i�ŏ��l�A�ő�l�j
	///</summary>
	int Range(int min, int max);

	///<summary>
	/// �����^�̗����𐶐�����i�ŏ��l�A�ő�l�j
	///</summary>
	float Range(float min, float max);

	///<summary>
	/// �N�_�l�̗����𐶐�����i�N�_�l�A���U�l�j
	///</summary>
	float Point(float point, float variance);

private:
	std::random_device mRandDev;	// �����V�[�h
	std::mt19937 mMt;			// ����������
};