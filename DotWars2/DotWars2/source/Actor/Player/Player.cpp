#include "Player.h"

//�A�N�V��������
#include "Action\Idle\PlayerIdle.h"
#include "Action\Move\PlayerMove.h"
#include "Action\MoveAttack\PlayerMoveAttack.h"
//�A�N�^�[����
#include "../CameraActor/CameraActor.h"


#include "../../Graphic/ModelAnim/ModelAnim.h"
#include "../../Graphic/Model/Model.h"
#include "../../Graphic/Sprite/Sprite.h"
#include "../../Utility/Input/Keyboard/Keyboard.h"
#include "../../Time/Time.h"

Player::Player(IWorld & world, const Matrix4 & mat) :
	Actor(world)
{
	//�v���C���[�̃J������ǉ�
	mWorld.Add(ACTOR_ID::CAMERA_ACTOR, std::make_shared<CameraActor>(mWorld));


	//�����ݒ�
	mParameter.isDead = false;
	mPosition = Vector3::Zero;
	mParameter.mat =
		Matrix4::Scale(1)*
		Matrix4::RotateX(0)*
		Matrix4::RotateY(0)*
		Matrix4::RotateZ(0)*
		Matrix4::Translate(Vector3::Zero);
	//�A�N�V�����N���X��ݒ�
	mPlayerActionManager = new ActionManager(world, mParameter);
	mPlayerActionManager->AddAction(ActionBehavior::IDLE, new PlayerIdle(world, *mPlayerActionManager, mParameter));
	mPlayerActionManager->AddAction(ActionBehavior::MOVE, new PlayerMove(world, *mPlayerActionManager, mParameter));
	mPlayerActionManager->AddAction(ActionBehavior::ATTACK_MOVE, new PlayerMoveAttack(world, *mPlayerActionManager, mParameter));
	//�A�N�V������ҋ@�ɐݒ�
	mPlayerActionManager->ChangeAction(ActionBehavior::IDLE);
}

Player::~Player()
{
	delete mPlayerActionManager;
}

void Player::Start()
{
}

void Player::Update()
{
	mWorld.Collision(ACTOR_ID::ENEMY_ACTOR, COL_ID::PLAYER_ENEMY_COL, *this);

	mPlayerActionManager->Update();
}

void Player::Draw() const
{
	ModelAnim::GetInstance().Draw(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, mParameter.mat);
}

void Player::Collision(Actor& other, const CollisionParameter& parameter)
{
	mPlayerActionManager->Collision(other, parameter);
}

ActionBehavior Player::GetState()
{
	return mPlayerActionManager->GetState();
}
