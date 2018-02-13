#pragma once
#include "../Action/Action.h"
#include "../IActionManager/IActionManager.h"
#include <queue>
#include <unordered_map>

class ActionManager :IActionManager {

public:
	struct ActionState
	{
		ActionBehavior behacior;
		bool initializeFlag;	//������

		bool interrupt;			//�D��x
		bool topPriority;		//�ŗD��@���݂̍s���S������
	};

public:
	ActionManager(IWorld & world, Parameter& parameter);
	virtual ~ActionManager() override;

	virtual void ChangeAction(ActionBehavior behavior, bool topPriority = false) override;

	void Update();
	/// <summary>
	/// �A�N�V�����̎擾
	/// </summary>
	/// <returns></returns>
	ActionState GetState();
private:

	//���݂̃A�N�V����
	std::queue<ActionState>mActionStates;

	std::unordered_map<ActionBehavior, Action*>mActions;
};