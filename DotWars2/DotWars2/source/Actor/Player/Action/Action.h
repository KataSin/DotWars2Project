#pragma once
#include "../../Actor.h"
class IWorld;
class IActionManager;
class Action {
public:
	Action(IWorld & world, IActionManager& actionManager, Parameter& parameter);
	virtual ~Action();

	virtual void Start() = 0;

	virtual void Update() = 0;

	virtual void End() = 0;


	bool GetEnd();
protected:
	Parameter& mParameter;
	IWorld& mWorld;
	IActionManager& mActionManager;
	bool mIsEnd;
};