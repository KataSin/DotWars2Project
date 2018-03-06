#pragma once

#include "../Action.h"
class PlayerIdle :public Action
{
public:
	PlayerIdle(IWorld & world, IActionManager& actionManager, Parameter& parameter);
	virtual ~PlayerIdle() override;

	virtual void Start() override;

	virtual void Update() override;

	virtual void End() override;

private:
	Vector3 mPosition;

};