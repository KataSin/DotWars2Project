#include "Player.h"

//�A�N�V��������
#include "Action\Idle\PlayerIdle.h"
#include "Action\Move\PlayerMove.h"
#include "Action\MoveAttack\PlayerMoveAttack.h"
#include "Action\Jump\PlayerJump.h"
//�A�N�^�[����
#include "../CameraActor/CameraActor.h"
#include "../BulletPoint/BulletPoint.h"

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
	//�U���|�C���g��ǉ�
	mWorld.Add(ACTOR_ID::PLAYER_BULLET_POINT_ACTOR, std::make_shared<BulletPoint>(mWorld));

	//�����ݒ�
	mParameter.isDead = false;
	mPosition = Vector3(0, 20, 0);
	mParameter.mat =
		Matrix4::Scale(1)*
		Matrix4::RotateX(0)*
		Matrix4::RotateY(0)*
		Matrix4::RotateZ(0)*
		Matrix4::Translate(mPosition);
	//�A�N�V�����N���X��ݒ�
	mPlayerActionManager = new ActionManager(world, mParameter);
	mPlayerActionManager->AddAction(ActionBehavior::IDLE, new PlayerIdle(this, world, *mPlayerActionManager, mParameter));
	mPlayerActionManager->AddAction(ActionBehavior::MOVE, new PlayerMove(this, world, *mPlayerActionManager, mParameter));
	mPlayerActionManager->AddAction(ActionBehavior::ATTACK_MOVE, new PlayerMoveAttack(this, world, *mPlayerActionManager, mParameter));
	mPlayerActionManager->AddAction(ActionBehavior::JUMP, new PlayerJump(this, world, *mPlayerActionManager, mParameter));
	//�A�N�V������ҋ@�ɐݒ�
	mPlayerActionManager->ChangeAction(ActionBehavior::IDLE);

	mVelo = Vector3::Zero;
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
	

	//�A�N�V�����A�b�v�f�[�g
	mPlayerActionManager->Update();

	//�S�A�N�V�������ʃA�b�v�f�[�g
	mParameter.mat.SetPosition(mVelo + mParameter.mat.GetPosition());
	//�d��
	mVelo.y -= 5.0f*Time::GetInstance().DeltaTime();
	mVelo.y = Math::Clamp(mVelo.y, -10.0f, 1000.0f);

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

void Player::SetPlusVelo(const Vector3 velocity)
{
	mVelo += velocity;
}

void Player::SetVeloY(float velocityY)
{
	mVelo.y = velocityY;
}
