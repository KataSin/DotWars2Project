#pragma once
#include "../Math/Vector3.h"
#include <vector>

//������������̍\���̂����

struct DotWarsNet
{
	int playerNum = -1;    //�ǂ̃v���C���[��
	Vector3 position; //�v���C���[�̍��W(�e�X�g)
};

struct ServerToClientState
{
	int playerNum = -1;                  //�󂯎��v���C���[�ԍ�
	DotWarsNet states[4]; //�v���C���[�̏�ԃR���e�i
};

//�ŏ��ɃT�[�o�[��������
struct FirstToClientState
{
	Vector3 position = Vector3::Zero; //�����|�W�V����
	int playerNum = -1;               //�v���C���[�ԍ�
};