#include <stdlib.h> 
#include <crtdbg.h>
#include <DxLib.h>


//テスト
#include "Camera\Camera.h"
#include "Graphic\Model\Model.h"
#include "Graphic\GraphicID.h"
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
	Model::GetInstance().Load("resource/Model/Player/Player.mv1", MODEL_ID::PLAYER_MODEL);

	while (ProcessMessage() == 0)
	{
		// 画面を初期化
		ClearDrawScreen();

		Camera::GetInstance().SetTarget(Vector3::Zero);
		Camera::GetInstance().SetPosition(Vector3(50, 50,50));
		Camera::GetInstance().SetRange(10.0f, 1500.0f);
		Camera::GetInstance().SetCameraVec(Vector3::Up);
		Camera::GetInstance().Update();

		Model::GetInstance().Draw(MODEL_ID::PLAYER_MODEL, Vector3::Zero);



		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
	}

	Model::GetInstance().Delete(MODEL_ID::PLAYER_MODEL);

	//dxlib終了
	DxLib_End();
	return 0;
}