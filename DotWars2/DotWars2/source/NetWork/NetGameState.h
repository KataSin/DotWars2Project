#pragma once
#include "../Math/Vector3.h"
#include <vector>
//������������̍\���̂����
struct DotWarsNet
{
	int playerNum;    //�ǂ̃v���C���[��
	Vector3 position; //�v���C���[�̍��W(�e�X�g)
};

struct ServerToClientState
{
	std::vector<DotWarsNet> states; //�v���C���[�̏�ԃR���e�i
};