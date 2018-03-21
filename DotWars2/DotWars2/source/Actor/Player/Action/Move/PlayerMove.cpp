#include "PlayerMove.h"

#include "../../Player.h"

#include "../../IActionManager/IActionManager.h"
#include "../../../../Graphic/ModelAnim/ModelAnim.h"
#include "../../../../Utility/Input/Keyboard/Keyboard.h"
#include "../../../../Time/Time.h"

const float MOVE_SPEED = 50.0f;

PlayerMove::PlayerMove(Actor* actor, IWorld & world, IActionManager& actionManager, Parameter& parameter) :
	Action(actor, world, actionManager, parameter)
{
}

PlayerMove::~PlayerMove()
{
}

void PlayerMove::Start()
{
	//�v���C���[�A�N�^�[�擾
	mPlayerActor = mWorld.FindActors(ACTOR_ID::PLAYER_ACTOR).front();
	//�J�����A�N�^�[�擾
	mCameraActor = mWorld.FindActors(ACTOR_ID::CAMERA_ACTOR).front();
	mPosition = mParameter.mat.GetPosition();

}

void PlayerMove::Update()
{
	DrawString(0, 32, "�����Ă܂�", GetColor(255, 255, 255));
	mPosition = mParameter.mat.GetPosition();


	//F�L�[��������Ă�����
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::SPACE)) {
		mActionManager.ChangeAction(ActionBehavior::JUMP, true);
		return;

	}

	//F�L�[��������Ă�����
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::F)) {
		mActionManager.ChangeAction(ActionBehavior::ATTACK_MOVE, true);
		return;

	}
	//�������͂��ĂȂ�������~�܂�
	if (Keyboard::GetInstance().KeyStateUp(KEYCODE::A) &&
		Keyboard::GetInstance().KeyStateUp(KEYCODE::S) &&
		Keyboard::GetInstance().KeyStateUp(KEYCODE::D) &&
		Keyboard::GetInstance().KeyStateUp(KEYCODE::W))
	{
		mActionManager.ChangeAction(ActionBehavior::IDLE, true);
		return;
	}
	//�A�j���[�V�����`�F���W
	ModelAnim::GetInstance().ChangeAnim(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_WALK);

	//�J�����̃x�N�g�����擾
	Vector3 cameraLeftVec = mCameraActor->GetParameter().mat.GetLeft().Normalized()*MOVE_SPEED;
	Vector3 cameraFrontVec = mCameraActor->GetParameter().mat.GetFront().Normalized()*MOVE_SPEED;
	//�J������y������
	cameraFrontVec.y = 0.0f;

	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::A)) {
		mPosition += cameraLeftVec*Time::GetInstance().DeltaTime();
		mMovemVec = cameraLeftVec;
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::D)) {
		mPosition -= cameraLeftVec*Time::GetInstance().DeltaTime();
		mMovemVec = -cameraLeftVec;
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::W)) {
		mPosition += cameraFrontVec*Time::GetInstance().DeltaTime();
		mMovemVec = cameraFrontVec;
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::S)) {
		mPosition -= cameraFrontVec*Time::GetInstance().DeltaTime();
		mMovemVec = -cameraFrontVec;
	}
	float playerAngle = Vector3::GetAngle2D(Vector3::Zero, mMovemVec);

	DrawString(0, 64, std::to_string(mParameter.mat.GetRotateDegree().y).c_str(), GetColor(255, 255, 255));

	mParameter.mat =
		Matrix4::Scale(1.0f)*
		Matrix4::RotateX(0.0f)*
		Matrix4::RotateY(-playerAngle+90.0f)*
		Matrix4::RotateZ(0.0f)*
		Matrix4::Translate(mPosition);

}

void PlayerMove::End()
{
}

void PlayerMove::Collision(Actor & other, const CollisionParameter & parameter)
{
	if (parameter.colFlag == COL_ID::PLAYER_PLATE_COL) {
		dynamic_cast<Player*>(mMyActor)->SetVeloY(0.0f);
	}
}
