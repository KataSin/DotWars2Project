#include <stdlib.h> 
#include <crtdbg.h>
#include <DxLib.h>


//テスト
#include "Camera\Camera.h"
#include "Graphic\Model\Model.h"
#include "Graphic\GraphicID.h"
#include "Graphic\Sprite\Sprite.h"
#include "Graphic\SpriteAnim\SpriteAnim.h"
#include "Graphic\ModelAnim\ModelAnim.h"
#include "Time\Time.h"
#include "Utility\Input\Keyboard\Keyboard.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// 画面モードのセット
	SetGraphMode(640, 480, 16);
	//ウィンドウモードに
	ChangeWindowMode(TRUE);
	//dxlib初期化
	if (DxLib_Init() == -1)
	{
		//失敗
		return -1;
	}

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	//テスト
	//Model::GetInstance().Load("resource/Model/Player/Player.mv1", MODEL_ID::PLAYER_MODEL);
	Sprite::GetInstance().Load("resource/Sprite/Back.png", SPRITE_ID::TEST_SPRITE);
	SpriteAnim::GetInstance().Load("resource/SpriteAnim/Num.png", SPRITE_ANIM_ID::TEST_SPRITE_ANIM, 10, Vector2(10, 1), Vector2(32, 64));

	SpriteAnim::GetInstance().Start(SPRITE_ANIM_ID::TEST_SPRITE_ANIM, 5.0f, true, true);

	ModelAnim::GetInstance().Load("resource/Model/Player/Player.mv1", MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_WALK);
	ModelAnim::GetInstance().AttachAnim(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_WALK);
	ModelAnim::GetInstance().StartAnim(MODEL_ANIM_ID::PLAYER_MODEL_ANIM);

	while (ProcessMessage() == 0)
	{

		Keyboard::GetInstance().Update();


		if (Keyboard::GetInstance().KeyStateDown(KEYCODE::SPACE)) {
			ModelAnim::GetInstance().ChangeAnim(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, MODEL_MOTION_ID::PLAYER_RUN);
		}

		// 画面を初期化
		ClearDrawScreen();

		Camera::GetInstance().SetTarget(Vector3::Zero);
		Camera::GetInstance().SetPosition(Vector3(50, 50,50));
		Camera::GetInstance().SetRange(10.0f, 1500.0f);
		Camera::GetInstance().SetCameraVec(Vector3::Up);
		Camera::GetInstance().Update();

		SpriteAnim::GetInstance().Update();
		


		//SpriteAnim::GetInstance().Draw(SPRITE_ANIM_ID::TEST_SPRITE_ANIM, Vector2::Zero, 1.0f, 0.0f);

		Time::GetInstance().Update();
		ModelAnim::GetInstance().Update();
		//Model::GetInstance().Draw(MODEL_ID::PLAYER_MODEL, Vector3::Zero);

		ModelAnim::GetInstance().Draw(MODEL_ANIM_ID::PLAYER_MODEL_ANIM, Matrix4::Identity, 1.0f);

		//Sprite::GetInstance().Draw(SPRITE_ID::TEST_SPRITE, Vector2::Zero);

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
	}

	ModelAnim::GetInstance().Delete(MODEL_ANIM_ID::PLAYER_MODEL_ANIM);
	Sprite::GetInstance().AllDelete();
	//dxlib終了
	DxLib_End();
	return 0;
}