#include "PlayerIdle.h"
#include "../../IActionManager/IActionManager.h" 

#include "../../../../Utility/Input/Keyboard/Keyboard.h"
#include "../../../../Graphic/ModelAnim/ModelAnim.h"
PlayerIdle::PlayerIdle(IWorld & world, IActionManager & actionManager, Parameter & parameter) :
	Action(world, actionManager, parameter)
{
	 
}

PlayerIdle::~PlayerIdle()
{
}

void PlayerIdle::Start()
{
	ModelAnim::GetInstance().ChangeAnim(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_IDLE);
}

void PlayerIdle::Update()
{
	DrawString(0, 32, "Ž~‚Ü‚Á‚Ä‚Ü‚·", GetColor(255, 255, 255));

	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::A) ||
		Keyboard::GetInstance().KeyStateDown(KEYCODE::S) ||
		Keyboard::GetInstance().KeyStateDown(KEYCODE::D) ||
		Keyboard::GetInstance().KeyStateDown(KEYCODE::W)) {
		mActionManager.ChangeAction(ActionBehavior::WALK,true);
	}
}

void PlayerIdle::End()
{
}
