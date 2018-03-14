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
		bool initializeFlag;	//初期化

		bool interrupt;			//優先度
		bool topPriority;		//最優先　現在の行動全部消す
	};

public:
	ActionManager(IWorld & world, Parameter& parameter);
	virtual ~ActionManager() override;
	/// <summary>
	/// アクションの変更
	/// </summary>
	/// <param name="behavior">行動</param>
	/// <param name="topPriority">優先度はどうか</param>
	virtual void ChangeAction(ActionBehavior behavior, bool topPriority = false) override;
	/// <summary>
	/// アクションの追加
	/// </summary>
	/// <param name="state"></param>
	/// <param name="action"></param>
	void AddAction(ActionBehavior state, Action* action);
	/// <summary>
	/// アクションアップデート
	/// </summary>
	void Update();
	/// <summary>
	/// アクションの取得
	/// </summary>
	/// <returns></returns>
	ActionBehavior GetState();

	void Collision(Actor& other, const CollisionParameter& parameter);

private:

	//現在のアクション
	std::queue<ActionState>mActionStates;

	std::unordered_map<ActionBehavior, Action*>mActions;
};