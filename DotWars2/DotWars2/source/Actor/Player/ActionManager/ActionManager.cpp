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
		}
	}
}

ActionManager::ActionState ActionManager::GetState()
{
	return mActionStates.front();
}
