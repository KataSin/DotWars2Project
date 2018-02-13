#include "ActionManager.h"
#include "../Action/Move/PlayerMove.h"
ActionManager::ActionManager(IWorld & world, Parameter& parameter)
{
	mActions[ActionBehavior::WALK] = new PlayerMove(world, *this, parameter);
}

ActionManager::~ActionManager()
{
	delete mActions[ActionBehavior::WALK];
}

void ActionManager::ChangeAction(ActionBehavior behavior, bool topPriority)
{
	ActionState state;
	state.behacior = behavior;
	state.topPriority = topPriority;

	//最優先に実行させる場合
	if (topPriority&&!mActionStates.empty()) {
		mActions[mActionStates.front().behacior]->End();
		//要素を全て消す
		while (!mActionStates.empty())mActionStates.pop();
	}
	//アクション追加
	mActionStates.push(state);
	//最優先の場合ここでスタートを呼んでしまう
	if (topPriority)
		mActions[mActionStates.front().behacior]->Start();


}
void ActionManager::Update()
{
	if (!mActionStates.empty()) {
		//アップデート
		mActions[mActionStates.front().behacior]->Update();
		//アクションが終わってたら先頭から消す
		if (mActions[mActionStates.front().behacior]->GetEnd()) {
			//消す前にエンドを呼ぶ
			mActions[mActionStates.front().behacior]->End();
			mActionStates.pop();
			//次のアクションのスタートを呼ぶ
			if (!mActionStates.empty())
				mActions[mActionStates.front().behacior]->Start();
		}
	}
}

ActionManager::ActionState ActionManager::GetState()
{
	return mActionStates.front();
}
