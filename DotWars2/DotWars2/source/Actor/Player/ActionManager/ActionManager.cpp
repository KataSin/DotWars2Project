#include "ActionManager.h"

ActionManager::ActionManager()
{
}

ActionManager::~ActionManager()
{
}

void ActionManager::AddAction(Action * action)
{

}

void ActionManager::Update()
{
	if (!mActions.empty()) {
		mActions.front()->Update();
	}
}
