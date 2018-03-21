#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(IWorld& world, const Vector3& position) :
	Actor(world)
{
	mParameter.mat =
		Matrix4::Scale(0.0f)*
		Matrix4::RotateX(0.0f)*
		Matrix4::RotateY(0.0f)*
		Matrix4::RotateZ(0.0f)*
		Matrix4::Translate(position);
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Start()
{
}

void PlayerBullet::Update()
{
}

void PlayerBullet::Draw() const
{
}

void PlayerBullet::Collision(Actor & other, const CollisionParameter & parameter)
{
}
