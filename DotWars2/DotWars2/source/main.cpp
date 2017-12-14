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
	//dxlib������
	if (DxLib_Init() == -1)
	{
		//���s
		return -1;
	}

	// �`����ʂ𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	game.Start();



	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();

		game.Update();
		game.Draw();

		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();
	}
	game.End();
	//dxlib�I��
	DxLib_End();
	return 0;
}