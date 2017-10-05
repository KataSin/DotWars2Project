#include "Player.h"
#include "../../Graphic/Model/Model.h"
#include "../../Graphic/Sprite/Sprite.h"
#include "../../Utility/Input/Keyboard/Keyboard.h"
#include "../../Time/Time.h"
Player::Player(IWorld & world, const Matrix4 & mat) :
	Actor(world)
{
	mParameter.isDead = false;
	mPosition = Vector3::Zero;
	mParameter.mat =
		Matrix4::Scale(0)*
		Matrix4::RotateX(0)*
		Matrix4::RotateY(0)*
		Matrix4::RotateZ(0)*
		Matrix4::Translate(Vector3::Zero);
}

Player::~Player()
{
}

void Player::Update()
{
	mWorld.Collision(ACTOR_ID::ENEMY_ACTOR, COL_ID::PLAYER_ENEMY_COL, *this);

	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::A)) {
		mPosition.x += 15.0f*Time::GetInstance().DeltaTime();
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::S)) {
		mPosition.z += 15.0f*Time::GetInstance().DeltaTime();
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::D)) {
		mPosition.x -= 15.0f*Time::GetInstance().DeltaTime();
	}
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::W)) {
		mPosition.z -= 15.0f*Time::GetInstance().DeltaTime();
	}

	mParameter.mat =
		Matrix4::Scale(0)*
		Matrix4::RotateX(0)*
		Matrix4::RotateY(0)*
		Matrix4::RotateZ(0)*
		Matrix4::Translate(mPosition);
}

void Player::Draw() const
{
	SetUseLighting(false);
	DrawSphere3D(Vector3::ToVECTOR(mParameter.mat.GetPosition()), 20, 20, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);
	SetUseLighting(true);
	//Model::GetInstance().Draw(MODEL_ID::PLAYER_MODEL, Matrix4::Identity);
}

void Player::Collision(Actor & other)
{
	int a = 0;
}
