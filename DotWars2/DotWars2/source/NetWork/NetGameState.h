#pragma once
#include "../Math/Vector3.h"
#include <vector>

//������������̍\���̂����

//�N���C�A���g���T�[�o�[�ɑ�����
struct DotWarsNet
{
	int playerNum = -1;    //�ǂ̃v���C���[��
	int frame = 0;		//�ǂ̃t���[������
	Vector3 position; //�v���C���[�̍��W(�e�X�g)
};
//�T�[�o�[���N���C�A���g�ɑ�����
struct ServerToClientState
{
	int playerNum = -1;                 //�󂯎��v���C���[�ԍ�
	int frame = 0;						//�t���[����
	DotWarsNet states[4];				//�v���C���[�̏�ԃR���e�i
};

//�ŏ��ɃT�[�o�[��������
struct FirstToClientState
{
	Vector3 position = Vector3::Zero; //�����|�W�V����
	int playerNum = -1;               //�v���C���[�ԍ�
};