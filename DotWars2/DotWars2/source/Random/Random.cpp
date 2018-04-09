#include "Random.h"

// コンストラクタ
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

// 整数型の乱数を生成する（最小値、最大値）
int Random::Range(int min, int max)
{
	// minからmaxまでの範囲設定
	std::uniform_int_distribution<> rand(min, max - 1);

	// 範囲内で乱数を生成し、返す
	return rand(mMt);
}

// 実数型の乱数を生成する（最小値、最大値）
float Random::Range(float min, float max)
{
	// minからmaxまでの範囲設定
	std::uniform_real_distribution<float> rand(min, max);

	// 範囲内で乱数を生成し、返す
	return rand(mMt);
}

// 実数型の乱数を生成する（起点値、分散値）
float Random::Point(float point, float variance)
{
	// pointを中心にvarianceの値で分散された範囲設定
	std::normal_distribution<float> rand(point, variance);

	// 範囲内で乱数を生成し、返す
	return rand(mMt);
}