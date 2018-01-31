#pragma once
#include "../Action/Action.h"
#include <queue>
class ActionManager {
public:
	ActionManager();
	~ActionManager();

	void AddAction(Action* action);

	void Update();
private:
	//Œ»İ‚ÌƒAƒNƒVƒ‡ƒ“
	std::queue<Action*>mActions;
};