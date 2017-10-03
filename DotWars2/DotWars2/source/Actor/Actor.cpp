#include "Actor.h"

Actor::Actor(IWorld & world)
{
	mParameter.isDead = false;
	mParameter.mat = Matrix4::Identity;
}

Actor::~Actor()
{
}

bool Actor::GetIsDead() const
{
	return mParameter.isDead;
}

Parameter Actor::GetParameter() const
{
	return mParameter;
}
