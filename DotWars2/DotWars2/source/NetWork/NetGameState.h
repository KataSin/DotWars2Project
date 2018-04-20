#pragma once
#include "../Math/Vector3.h"
#include "../Math/NetVec3.h"
#include "../Actor/ActorID.h"
#include <vector>

//������������̍\���̂����

//�N���C�A���g���T�[�o�[�ɑ�����
struct DotWarsNet
{
	short int playerNum = -1;		//�ǂ̃v���C���[��
	unsigned int frame = 0;			//�ǂ̃t���[������
	NetVec3 position;				//�v���C���[�̍��W(�e�X�g)
	NetVec3 attackVec;				//������ԃx�N�g��(�U�����łȂ����(999,999,999)������)
};
//�T�[�o�[���N���C�A���g�ɑ�����
struct ServerToClientState
{
	unsigned int frame = 0;						//�t���[����
	short int playerNum = -1;					//�󂯎��v���C���[�ԍ�
	short int playerHp = 0;						//�v���C���[HP
	DotWarsNet states[4];						//�v���C���[�̏�ԃR���e�i
	char stagePlates[16][16];					//�X�e�[�W�̃v���[�gHP
	NetVec3 bulletPos[32];						//�G�e�̍��W
};

//�ŏ��ɃT�[�o�[��������
struct FirstToClientState
{
	NetVec3 position = NetVec3(0, 0, 0);	//�����|�W�V����
	short int playerNum = -1;					//�v���C���[�ԍ�
};

//�e�̂����蔻��p�\����
struct CollisionCheckState {
	PLAYER_ID playerID;
	Vector3 playerPos;
	
};