#pragma once
#include "../../Actor.h"
class IWorld;
class IActionManager;
class Action {
public:
	Action(Actor* actor, IWorld & world, IActionManager& actionManager, Parameter& parameter);
	virtual ~Action();

	virtual void Start() = 0;

	virtual void Update() = 0;

	virtual void End() = 0;

	virtual void Collision(Actor& other, const CollisionParameter& parameter) = 0;

	bool GetEnd();
protected:
	//自身のアクター
	Actor* mMyActor;

	Parameter& mParameter;
	IWorld& mWorld;
	IActionManager& mActionManager;
	bool mIsEnd;
};