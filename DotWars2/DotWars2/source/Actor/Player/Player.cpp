#include "Player.h"
#include "../../Graphic/ModelAnim/ModelAnim.h"
#include "../../Graphic/Model/Model.h"
#include "../../Graphic/Sprite/Sprite.h"
#include "../../Utility/Input/Keyboard/Keyboard.h"
#include "../../Time/Time.h"
#include "ActionManager\ActionManager.h"
Player::Player(IWorld & world, const Matrix4 & mat) :
	Actor(world)
{
	mParameter.isDead = false;
	mPosition = Vector3::Zero;
	mParameter.mat =
		Matrix4::Scale(1)*
		Matrix4::RotateX(0)*
		Matrix4::RotateY(0)*
		Matrix4::RotateZ(0)*
		Matrix4::Translate(Vector3::Zero);

	mActionManager = new ActionManager(world,mParameter);

	mActionManager->ChangeAction(ActionBehavior::IDLE);
}

Player::~Player()
{
	delete mActionManager;
}

void Player::Update()
{
	mWorld.Collision(ACTOR_ID::ENEMY_ACTOR, COL_ID::PLAYER_ENEMY_COL, *this);

	mActionManager->Update();
}

void Player::Draw() const
{

	ModelAnim::GetInstance().Draw(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, mParameter.mat);
}

void Player::Collision(Actor & other)
{
	int a = 0;
}
