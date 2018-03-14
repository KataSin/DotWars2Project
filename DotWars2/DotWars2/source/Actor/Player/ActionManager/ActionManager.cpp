#include "ActionManager.h"

ActionManager::ActionManager(IWorld & world, Parameter& parameter)
{
	//mActions[ActionBehavior::WALK] = new PlayerMove(world, *this, parameter);
	//mActions[ActionBehavior::IDLE] = new PlayerIdle(world, *this, parameter);
}

ActionManager::~ActionManager()
{
	for (const auto& i: mActions) {
		delete i.second;
	}
}

void ActionManager::ChangeAction(ActionBehavior behavior, bool topPriority)
{
	ActionState state;
	state.behacior = behavior;
	state.topPriority = topPriority;

	//�ŗD��Ɏ��s������ꍇ
	if (topPriority&&!mActionStates.empty()) {
		mActions[mActionStates.front().behacior]->End();
		//�v�f��S�ď���
		while (!mActionStates.empty())mActionStates.pop();
	}
	//�A�N�V�����ǉ�
	mActionStates.push(state);
	//�ŗD��̏ꍇ�����ŃX�^�[�g���Ă�ł��܂�
	if (topPriority)
		mActions[mActionStates.front().behacior]->Start();


}
void ActionManager::AddAction(ActionBehavior state, Action * action)
{
	mActions[state] = action;
}
void ActionManager::Update()
{
	if (!mActionStates.empty()) {
		//�A�b�v�f�[�g
		mActions[mActionStates.front().behacior]->Update();
		//�A�N�V�������I����Ă���擪�������
		if (mActions[mActionStates.front().behacior]->GetEnd()) {
			//�����O�ɃG���h���Ă�
			mActions[mActionStates.front().behacior]->End();
			mActionStates.pop();
			//���̃A�N�V�����̃X�^�[�g���Ă�
			if (!mActionStates.empty())
				mActions[mActionStates.front().behacior]->Start();
			else
				mActions[ActionBehavior::IDLE]->Start();
		}
	}
	else
	{
		mActions[ActionBehavior::IDLE]->Update();
	}
}

ActionBehavior ActionManager::GetState()
{
	return mActionStates.front().behacior;
}

void ActionManager::Collision(Actor & other, const CollisionParameter & parameter)
{
	mActions[mActionStates.front().behacior]->Collision(other, parameter);
}
