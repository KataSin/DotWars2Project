#include "Action.h"
#include "../../../World/IWorld.h"
#include "../ActionManager/ActionManager.h"
#include "../../Actor.h"
Action::Action(IWorld & world, IActionManager& actionManager, Parameter& parameter):
	mParameter(parameter),
	mWorld(world),
	mActionManager(actionManager),
	mIsEnd(false)
{
}

Action::~Action()
{
}

bool Action::GetEnd()
{
	return mIsEnd;
}
