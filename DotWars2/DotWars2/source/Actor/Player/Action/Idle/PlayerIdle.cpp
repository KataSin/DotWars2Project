#include "PlayerIdle.h"
#include "../../IActionManager/IActionManager.h" 

#include "../../Player.h"

#include "../../../../Time/Time.h"
#include "../../../../Utility/Input/Keyboard/Keyboard.h"
#include "../../../../Graphic/ModelAnim/ModelAnim.h"
#include "../../../../Camera/Camera.h"
PlayerIdle::PlayerIdle(Actor* actor, IWorld & world, IActionManager & actionManager, Parameter & parameter) :
	Action(actor, world, actionManager, parameter)
{
}

PlayerIdle::~PlayerIdle()
{
}

void PlayerIdle::Start()
{

}

void PlayerIdle::Update()
{
	DrawString(0, 32, "止まってます", GetColor(255, 255, 255));
	//ジャンプ
	if (Keyboard::GetInstance().KeyTriggerDown(KEYCODE::SPACE)) {
		mActionManager.ChangeAction(ActionBehavior::JUMP, true);
	}
	//攻撃
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::F)) {
		mActionManager.ChangeAction(ActionBehavior::ATTACK_MOVE, true);
		return;
	}
	//プレイヤーの動き
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::A) ||
		Keyboard::GetInstance().KeyStateDown(KEYCODE::S) ||
		Keyboard::GetInstance().KeyStateDown(KEYCODE::D) ||
		Keyboard::GetInstance().KeyStateDown(KEYCODE::W)) {
		mActionManager.ChangeAction(ActionBehavior::MOVE, true);
		return;
	}


	ModelAnim::GetInstance().ChangeAnim(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_IDLE);
}

void PlayerIdle::End()
{
}

void PlayerIdle::Collision(Actor & other, const CollisionParameter & parameter)
{
	//床との判定
	if (parameter.colFlag == COL_ID::PLAYER_PLATE_COL) {
		dynamic_cast<Player*>(mMyActor)->SetVeloY(0.0f);
	}
}
