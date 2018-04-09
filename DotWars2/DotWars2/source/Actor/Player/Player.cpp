#include "Player.h"

//アクションたち
#include "Action\Idle\PlayerIdle.h"
#include "Action\Move\PlayerMove.h"
#include "Action\MoveAttack\PlayerMoveAttack.h"
#include "Action\Jump\PlayerJump.h"
//アクターたち
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
	//プレイヤーのカメラを追加
	mWorld.Add(ACTOR_ID::CAMERA_ACTOR, std::make_shared<CameraActor>(mWorld));
	//攻撃ポイントを追加
	mWorld.Add(ACTOR_ID::PLAYER_BULLET_POINT_ACTOR, std::make_shared<BulletPoint>(mWorld));

	//初期設定
	mParameter.isDead = false;
	mPosition = Vector3(0, 20, 0);
	mParameter.mat =
		Matrix4::Scale(1)*
		Matrix4::RotateX(0)*
		Matrix4::RotateY(0)*
		Matrix4::RotateZ(0)*
		Matrix4::Translate(mPosition);
	//アクションクラスを設定
	mPlayerActionManager = new ActionManager(world, mParameter);
	mPlayerActionManager->AddAction(ActionBehavior::IDLE, new PlayerIdle(this, world, *mPlayerActionManager, mParameter));
	mPlayerActionManager->AddAction(ActionBehavior::MOVE, new PlayerMove(this, world, *mPlayerActionManager, mParameter));
	mPlayerActionManager->AddAction(ActionBehavior::ATTACK_MOVE, new PlayerMoveAttack(this, world, *mPlayerActionManager, mParameter));
	mPlayerActionManager->AddAction(ActionBehavior::JUMP, new PlayerJump(this, world, *mPlayerActionManager, mParameter));
	//アクションを待機に設定
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
	

	//アクションアップデート
	mPlayerActionManager->Update();

	//全アクション共通アップデート
	mParameter.mat.SetPosition(mVelo + mParameter.mat.GetPosition());
	//重力
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
