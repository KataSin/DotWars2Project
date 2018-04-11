#include "EnemyPlayer.h"

EnemyPlayer::EnemyPlayer(IWorld& world, const EnemyPlayerState& state) :
	Actor(world)
{
	mParameter.isDead = false;


}

EnemyPlayer::~EnemyPlayer()
{
}

void EnemyPlayer::Start()
{
}

void EnemyPlayer::Update()
{

	mParameter.mat =
		Matrix4::Scale(1.0f)*
		Matrix4::RotateX(0.0f)*
		Matrix4::RotateY(0.0f)*
		Matrix4::RotateZ(0.0f)*
		Matrix4::Translate(mState.pos);

	//ƒxƒNƒgƒ‹‚ğ‹‚ß‚é
	mVec = mSeveVec - mState.pos;
	mSeveVec = mState.pos;

}

void EnemyPlayer::Draw() const
{

}

void EnemyPlayer::Collision(Actor & other, const CollisionParameter & parameter)
{
}

void EnemyPlayer::SetEnemyPlayerState(const EnemyPlayerState & state)
{
	mState = state;
}
