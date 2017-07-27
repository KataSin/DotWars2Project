#include <stdlib.h> 
#include <crtdbg.h>
#include <DxLib.h>


//�e�X�g
#include "Camera\Camera.h"
#include "Graphic\Model\Model.h"
#include "Graphic\GraphicID.h"
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

	//�e�X�g
	Model::GetInstance().Load("resource/Model/Player/Player.mv1", MODEL_ID::PLAYER_MODEL);

	while (ProcessMessage() == 0)
	{
		// ��ʂ�������
		ClearDrawScreen();

		Camera::GetInstance().SetTarget(Vector3::Zero);
		Camera::GetInstance().SetPosition(Vector3(50, 50,50));
		Camera::GetInstance().SetRange(10.0f, 1500.0f);
		Camera::GetInstance().SetCameraVec(Vector3::Up);
		Camera::GetInstance().Update();

		Model::GetInstance().Draw(MODEL_ID::PLAYER_MODEL, Vector3::Zero);



		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();
	}

	Model::GetInstance().Delete(MODEL_ID::PLAYER_MODEL);

	//dxlib�I��
	DxLib_End();
	return 0;
}