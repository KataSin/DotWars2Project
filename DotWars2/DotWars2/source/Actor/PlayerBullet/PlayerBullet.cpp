#include "PlayerBullet.h"

#include "../../Graphic/Model/Model.h"

#include "../../Random/Random.h"
#include "../../Time/Time.h"

const float BULLET_SPEED = 0.01f;

PlayerBullet::PlayerBullet(IWorld& world, const BulletState& state) :
	Actor(world)
{
	//パラメーター初期化
	mParameter.playerID = state.playerID;


	mParameter.mat =
		Matrix4::Scale(1.0f)*
		Matrix4::RotateX(0.0f)*
		Matrix4::RotateY(0.0f)*
		Matrix4::RotateZ(0.0f)*
		Matrix4::Translate(state.spawnPos);


	//ランダムで拡散する
	mRandVec = Vector3(
		Random::GetInstance().Range(-state.rand.x, state.rand.x),
		Random::GetInstance().Range(-state.rand.y + 0.5f, state.rand.y - 0.5f),
		Random::GetInstance().Range(-state.rand.z, state.rand.z));



	mRandRotate = Vector3(
		Random::GetInstance().Range(-100, 100),
		Random::GetInstance().Range(-100, 100),
		Random::GetInstance().Range(-100, 100));

	//bulletstateを代入
	mPosition = state.spawnPos;
	mVertexPoint = state.vertexPos;
	mStartPos = state.spawnPos;
	//距離を求める計算
	mDistance = (mVertexPoint + mRandVec - mStartPos);
	mCoppyPosY = mStartPos.y;


	mTime = 0.0f;
	mVec = (state.vertexPos - state.spawnPos).Normalized()*1000.0f;
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Start()
{
}

void PlayerBullet::Update()
{
	//タイム加算
	mTime += Time::GetInstance().DeltaTime();

	mVec.y -=2000.0f*Time::GetInstance().DeltaTime();
	mPosition += mVec*Time::GetInstance().DeltaTime();
	////頂点が出現位置よりも高かったら(頂点と出現位置の引き算がマイナスになり平方根で求められなくなるため)
	//if (mCoppyPosY <= mVertexPoint.y)
	//{
	//	//最高高度をもとに初速度を求める(鉛直投げ上げ)
	//	float InitializeVec = Math::Sqrt((mVertexPoint.y - mCoppyPosY) * 2.0f * 9.8f);
	//	//初速度を元に頂点に達する時間を求める
	//	float vertexTime = InitializeVec / 9.8f;
	//	//距離と頂点に達する時間が分かったので1フレームに動くx軸z軸の移動量を求める
	//	mVec = Vector3(
	//		mDistance.x / vertexTime  *BULLET_SPEED* Time::GetInstance().DeltaTime(),
	//		0.0f,
	//		mDistance.z / vertexTime *BULLET_SPEED* Time::GetInstance().DeltaTime());
	//	//y軸の位置を求める
	//	mPosition.y = InitializeVec*mTime*BULLET_SPEED - 9.8f / 2.0f * pow(mTime*BULLET_SPEED, 2) + mCoppyPosY;
	//	//移動量を足す
	//	mPosition += mVec;
	//}
	////低かったら(初速度が求められないため)
	//else
	//{
	//	//騙す(バレない)
	//	mVecY -= 10.0f*Time::GetInstance().DeltaTime();
	//	Vector3 mVec = mDistance + Vector3(0.0f, mVecY, 0.0f);
	//	mPosition += mVec*BULLET_SPEED*1.5f*Time::GetInstance().DeltaTime();
	//}
	mRotate += mRandRotate*Time::GetInstance().DeltaTime();

	//テスト
	if (mTime >= 2.0f) {
		mParameter.isDead = true;
	}

	mParameter.mat =
		Matrix4::Scale(1.0f)*
		Matrix4::RotateX(mRotate.x)*
		Matrix4::RotateY(mRotate.y)*
		Matrix4::RotateZ(mRotate.z)*
		Matrix4::Translate(mPosition);
}

void PlayerBullet::Draw() const
{
	Model::GetInstance().Draw(MODEL_ID::PLAYER_BULLET_MODEL, mParameter.mat);
}

void PlayerBullet::Collision(Actor & other, const CollisionParameter & parameter)
{
	if (parameter.colID == COL_ID::PLATE_BULLET_COL){
		mParameter.isDead = true;
	}
}
