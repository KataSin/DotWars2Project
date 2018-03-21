#include "Action.h"
#include "../../../World/IWorld.h"
#include "../IActionManager/IActionManager.h"
#include "../../Actor.h"
Action::Action(Actor* actor, IWorld & world, IActionManager& actionManager, Parameter& parameter):
	mParameter(parameter),
	mWorld(world),
	mActionManager(actionManager),
	mIsEnd(false),
	mMyActor(actor)
{
}

Action::~Action()
{
}

bool Action::GetEnd()
{
	return mIsEnd;
}
