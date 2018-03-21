#include "PlayerMoveAttack.h"
#include "../../ActionManager/ActionManager.h"
#include "../../../../Utility/Input/Keyboard/Keyboard.h"

#include "../../../../Graphic/ModelAnim/ModelAnim.h"

#include "../../../../Time/Time.h"

#include "../../Player.h"


//�U�����̈ړ��X�s�[�h
const float ATTACK_MOVE_SPEED = 20.0f;

PlayerMoveAttack::PlayerMoveAttack(Actor* actor, IWorld & world, IActionManager & actionManager, Parameter & parameter) :
	Action(actor,world, actionManager, parameter)
{
}

PlayerMoveAttack::~PlayerMoveAttack()
{
}

void PlayerMoveAttack::Start()
{
	mPosition = mParameter.mat.GetPosition();
	//�J�����A�N�^�[�擾
	mCameraActor = mWorld.FindActors(ACTOR_ID::CAMERA_ACTOR).front();
	mPlayerActor = mWorld.FindActors(ACTOR_ID::PLAYER_ACTOR).front();

}

void PlayerMoveAttack::Update()
{
	mPosition = mParameter.mat.GetPosition();
	//������Ă������ԃ`�F���W
	if (Keyboard::GetInstance().KeyStateUp(KEYCODE::F)) {
		mActionManager.ChangeAction(ActionBehavior::IDLE, true);
		return;
	}
	ModelAnim::GetInstance().ChangeAnim(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_WALK);
	//�J�����̃x�N�g�����擾
	Vector3 cameraLeftVec = mCameraActor->GetParameter().mat.GetLeft().Normalized();
	Vector3 cameraFrontVec= mCameraActor->GetParameter().mat.GetFront().Normalized();
	//�J������y������
	cameraFrontVec.y = 0.0f;

	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::A)) {
		mPosition += cameraLeftVec*ATTACK_MOVE_SPEED*Time::GetInstance().DeltaTime();
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::D)) {
		mPosition -= cameraLeftVec*ATTACK_MOVE_SPEED*Time::GetInstance().DeltaTime();
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::W)) {
		mPosition += cameraFrontVec*ATTACK_MOVE_SPEED*Time::GetInstance().DeltaTime();

	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::S)) {
		mPosition -= cameraFrontVec*ATTACK_MOVE_SPEED*Time::GetInstance().DeltaTime();
	}
	
	mParameter.mat =
		Matrix4::Scale(1.0f)*
		Matrix4::RotateX(0.0f)*
		Matrix4::RotateY(mCameraActor->GetParameter().mat.GetRotateDegree().y+180.0f)*
		Matrix4::RotateZ(0.0f)*
		Matrix4::Translate(mPosition);
}

void PlayerMoveAttack::End()
{
}

void PlayerMoveAttack::Collision(Actor & other, const CollisionParameter & parameter)
{
	if (parameter.colID == COL_ID::PLAYER_PLATE_COL) {
		//���ɓ���������~�܂�
		dynamic_cast<Player*>(mMyActor)->SetVeloY(0.0f);
	}
}