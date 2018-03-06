#include "PlayerMove.h"

#include "../../IActionManager/IActionManager.h"
#include "../../../../Graphic/ModelAnim/ModelAnim.h"
#include "../../../../Utility/Input/Keyboard/Keyboard.h"
#include "../../../../Time/Time.h"
PlayerMove::PlayerMove(IWorld & world, IActionManager& actionManager, Parameter& parameter) :
	Action(world, actionManager, parameter)
{
}

PlayerMove::~PlayerMove()
{
}

void PlayerMove::Start()
{
	mPosition = mParameter.mat.GetPosition();
	ModelAnim::GetInstance().ChangeAnim(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_WALK);
}

void PlayerMove::Update()
{
	DrawString(0, 32, "•à‚¢‚Ä‚Ü‚·", GetColor(255, 255, 255));
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::A)) {
		mPosition.x -= 5.0f*Time::GetInstance().DeltaTime();
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::D)) {
		mPosition.x += 5.0f*Time::GetInstance().DeltaTime();

	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::W)) {
		mPosition.y += 5.0f*Time::GetInstance().DeltaTime();

	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::S)) {
		mPosition.y -= 5.0f*Time::GetInstance().DeltaTime();
	}


	if (Keyboard::GetInstance().KeyStateUp(KEYCODE::A) &&
		Keyboard::GetInstance().KeyStateUp(KEYCODE::S) &&
		Keyboard::GetInstance().KeyStateUp(KEYCODE::D) &&
		Keyboard::GetInstance().KeyStateUp(KEYCODE::W))
	{
		
		mActionManager.ChangeAction(ActionBehavior::IDLE, true);
	}



	mParameter.mat = Matrix4::Translate(mPosition);

}

void PlayerMove::End()
{
}
