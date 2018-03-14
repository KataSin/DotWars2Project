#pragma once
#include "../Action/Action.h"
#include "../IActionManager/IActionManager.h"
#include <queue>
#include <unordered_map>

class ActionManager :public IActionManager {

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
	/// <summary>
	/// �A�N�V�����̕ύX
	/// </summary>
	/// <param name="behavior">�s��</param>
	/// <param name="topPriority">�D��x�͂ǂ���</param>
	virtual void ChangeAction(ActionBehavior behavior, bool topPriority = false) override;
	/// <summary>
	/// �A�N�V�����̒ǉ�
	/// </summary>
	/// <param name="state"></param>
	/// <param name="action"></param>
	void AddAction(ActionBehavior state, Action* action);
	/// <summary>
	/// �A�N�V�����A�b�v�f�[�g
	/// </summary>
	void Update();
	/// <summary>
	/// �A�N�V�����̎擾
	/// </summary>
	/// <returns></returns>
	ActionBehavior GetState();

	void Collision(Actor& other, const CollisionParameter& parameter);

private:

	//���݂̃A�N�V����
	std::queue<ActionState>mActionStates;

	std::unordered_map<ActionBehavior, Action*>mActions;
};