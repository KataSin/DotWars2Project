#include "Action.h"

Action::Action(IWorld & world, ActionManager& actionManager, ActorPtr actor):
	mActor(actor),
	mWorld(world)
{
}

Action::~Action()
{
}
