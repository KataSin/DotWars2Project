#include <stdlib.h> 
#include <crtdbg.h>
#include <DxLib.h>
#include "Game\Game.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	Game game(640, 480, false);
	SetDoubleStartValidFlag(TRUE);
	SetAlwaysRunFlag(TRUE);
	//dxlib初期化
	if (DxLib_Init() == -1)
	{
		//失敗
		return -1;
	}

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	game.Start();



	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();

		game.Update();
		game.Draw();

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
	}
	game.End();
	//dxlib終了
	DxLib_End();
	return 0;
}