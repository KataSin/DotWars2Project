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
	//���݂̃A�N�V����
	std::queue<Action*>mActions;
};