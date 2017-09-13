#include <stdlib.h> 
#include <crtdbg.h>
#include <DxLib.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(640, 480, 16);
	//�E�B���h�E���[�h��
	ChangeWindowMode(TRUE);

	//dxlib������
	if (DxLib_Init() == -1)
	{
		//���s
		return -1;
	}

	// �`����ʂ𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();
	}
	//dxlib�I��
	DxLib_End();
	return 0;
}