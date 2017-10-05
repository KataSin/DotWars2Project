#include "Enemy.h"

Enemy::Enemy(IWorld & world, const Matrix4 & mat) :
	Actor(world)
{
	mParameter.mat =
		Matrix4::Scale(Vector3::One)*
		Matrix4::RotateX(0)*
		Matrix4::RotateY(0)*
		Matrix4::RotateZ(0)*
		Matrix4::Translate(Vector3(50,0,50));
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	
}

void Enemy::Draw() const
{
	SetUseLighting(false);
	DrawSphere3D(Vector3::ToVECTOR(mParameter.mat.GetPosition()), 20, 20, GetColor(255, 0, 255), GetColor(255, 0, 255), FALSE);
	SetUseLighting(true);
}

void Enemy::Collision(Actor & other)
{
}
