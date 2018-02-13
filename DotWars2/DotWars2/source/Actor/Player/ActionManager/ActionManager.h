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
		bool initializeFlag;	//初期化

		bool interrupt;			//優先度
		bool topPriority;		//最優先　現在の行動全部消す
	};

public:
	ActionManager(IWorld & world, Parameter& parameter);
	virtual ~ActionManager() override;

	virtual void ChangeAction(ActionBehavior behavior, bool topPriority = false) override;

	void Update();
	/// <summary>
	/// アクションの取得
	/// </summary>
	/// <returns></returns>
	ActionState GetState();
private:

	//現在のアクション
	std::queue<ActionState>mActionStates;

	std::unordered_map<ActionBehavior, Action*>mActions;
};