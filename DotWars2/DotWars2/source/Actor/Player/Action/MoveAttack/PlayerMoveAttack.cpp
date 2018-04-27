#include "PlayerMoveAttack.h"
#include "../../ActionManager/ActionManager.h"
#include "../../../../Utility/Input/Keyboard/Keyboard.h"
#include "../../../../Random/Random.h"

#include "../../../../Graphic/ModelAnim/ModelAnim.h"

#include "../../../../Time/Time.h"

#include "../../Player.h"
#include "../../../PlayerBullet/PlayerBullet.h"

//�U�����̈ړ��X�s�[�h
const float ATTACK_MOVE_SPEED = 60.0f;
//�U������Ԋu
const float ATTACK_BULLET_TIME = 0.1f;
//�e�̂΂炯�
const Vector3 ATTCK_BULLET_RAND = Vector3(5.0f, 5.0f, 5.0f);
PlayerMoveAttack::PlayerMoveAttack(Actor* actor, IWorld & world, IActionManager & actionManager, Parameter & parameter) :
	Action(actor, world, actionManager, parameter)
{
	mAttackTime = 0.0f;
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

	mVertexPos = mWorld.FindActors(ACTOR_ID::PLAYER_BULLET_POINT_ACTOR).front();



}

void PlayerMoveAttack::Update()
{
	mPosition = mParameter.mat.GetPosition();
	//������Ă������ԃ`�F���W
	if (Keyboard::GetInstance().KeyStateUp(KEYCODE::F)) {
		mActionManager.ChangeAction(ActionBehavior::IDLE, true);
		return;
	}

	//if (Keyboard::GetInstance().KeyStateDown(KEYCODE::SPACE)) {
	//	mActionManager.ChangeAction(ActionBehavior::JUMP_ATTACK, true);
	//	return;
	//}
	ModelAnim::GetInstance().ChangeAnim(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_WALK);
	//�J�����̃x�N�g�����擾
	Vector3 cameraLeftVec = mCameraActor->GetParameter().mat.GetLeft().Normalized();
	Vector3 cameraFrontVec = mCameraActor->GetParameter().mat.GetFront().Normalized();
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
		Matrix4::RotateY(mCameraActor->GetParameter().mat.GetRotateDegree().y)*
		Matrix4::RotateZ(0.0f)*
		Matrix4::Translate(mPosition);

	//�U��
	mAttackTime += Time::GetInstance().DeltaTime();
	//�T�[�o�[�ɑ�����Z�b�g
	mPlayerActor->GetParameter().state.attackVec = NetVec3(0,0,0);
	if (mAttackTime >= ATTACK_BULLET_TIME) {
		//�e�̏������߂�
		PlayerBullet::BulletState state;
		Vector3 vertexPos = mVertexPos->GetParameter().mat.GetPosition();
		state.playerID = mParameter.playerID;
		state.spawnPos = mParameter.mat.GetPosition();
		Vector3 randVec = Vector3(
			Random::GetInstance().Range(-ATTCK_BULLET_RAND.x, ATTCK_BULLET_RAND.x),
			Random::GetInstance().Range(-ATTCK_BULLET_RAND.y + 0.5f, ATTCK_BULLET_RAND.y - 0.5f),
			Random::GetInstance().Range(-ATTCK_BULLET_RAND.z, ATTCK_BULLET_RAND.z));
		Vector3 vec = ((vertexPos - state.spawnPos).Normalized()*1000.0f) + randVec;
		//�e���ݒ�
		state.vec = vec;
		//�T�[�o�[�ɑ�������㏑������
		mPlayerActor->GetParameter().state.attackVec = NetVec3::ToNetVec3(vec);
		////���������̒e��ǉ�
		//mWorld.Add(ACTOR_ID::PLAYER_BULLET_ACTOR, std::make_shared<PlayerBullet>(mWorld, state));

		mAttackTime = 0.0f;
	}

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
