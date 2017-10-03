#include "Player.h"
#include "../../Graphic/Model/Model.h"
#include "../../Graphic/Sprite/Sprite.h"
#include "../../Utility/Input/Keyboard/Keyboard.h"
Player::Player(IWorld & world, const Matrix4 & mat) :
	Actor(world)
{
	mParameter.isDead = false;
}

Player::~Player()
{
}

void Player::Update()
{
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::SPACE)) {
		mParameter.isDead = true;
	}
}

void Player::Draw() const
{
	Model::GetInstance().Draw(MODEL_ID::PLAYER_MODEL, Matrix4::Identity);
	Sprite::GetInstance().Draw(SPRITE_ID::TEST_SPRITE, Vector2::Zero);
}
