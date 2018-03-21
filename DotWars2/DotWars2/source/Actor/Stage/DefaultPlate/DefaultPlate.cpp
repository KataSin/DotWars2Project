#include "DefaultPlate.h"

#include "../../../Graphic/Model/Model.h"
//HP
const int HP = 5;
//リスポーンタイム
const float RESPAWN_TIME = 20.0f;

DefaultPlate::DefaultPlate(IWorld & world, const Matrix4 & mat) :
	Actor(world)
{
	mParameter.mat = mat;
	mParameter.isDead = false;
	//HPを設定
	mPlateHp = HP;
	mIsBreak = false;
}

DefaultPlate::~DefaultPlate()
{
}

void DefaultPlate::Start()
{
}

void DefaultPlate::Update()
{
	//壊れてた場合
	if (mPlateHp <= 0) {
		mIsBreak = true;
	}
	if (!mIsBreak) {
		mWorld.Collision(ACTOR_ID::PLAYER_ACTOR, COL_ID::PLAYER_PLATE_COL, *this);

	}


}

void DefaultPlate::Draw() const
{
	Model::GetInstance().Draw(MODEL_ID::DEFAULT_PLATE_MODEL, mParameter.mat);
}

void DefaultPlate::Collision(Actor & other, const CollisionParameter & parameter)
{
	//if (true) {
	//	mPlateHp--;
	//}
}
