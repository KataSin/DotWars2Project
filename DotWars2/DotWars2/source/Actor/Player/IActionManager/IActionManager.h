#pragma once
enum ActionBehavior
{
	IDLE,
	MOVE,
	ATTACK_MOVE,
	DUSH,
	JUMP
};
class IActionManager {

public:
	virtual ~IActionManager() {};

	virtual void ChangeAction(ActionBehavior behavior, bool topPriority = false) = 0;

};