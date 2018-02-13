#pragma once
enum ActionBehavior
{
	IDLE,
	WALK,
	DUSH
};
class IActionManager {

public:
	virtual ~IActionManager() {};

	virtual void ChangeAction(ActionBehavior behavior, bool topPriority = false) = 0;

};