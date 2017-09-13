#include <stdlib.h> 
#include <crtdbg.h>
#include <DxLib.h>

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

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
	}
	//dxlib終了
	DxLib_End();
	return 0;
}