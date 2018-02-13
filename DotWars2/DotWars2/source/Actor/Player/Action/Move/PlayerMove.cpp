#include "PlayerMove.h"

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
}

void PlayerMove::Update()
{
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
	mParameter.mat = Matrix4::Translate(mPosition);

}

void PlayerMove::End()
{
}
