#pragma once
#include "../../Math/Vector3.h"
#include "../../Actor/ActorID.h"
#include "../NetGameState.h"
#include "../../World/World/World.h"
#include <vector>

//�擾�����e�̏��
struct NetBulletState {
	Vector3 bulletPos;	//�e�̍��W
	PLAYER_ID playerID;	//�v���C���[�̍��W
};
//�v���[�g���
struct PlateState {
	Vector3 position;
	int hp;
};
//�T�[�o�[���ŃR���W������������邽�߂̃N���X
class ServerCollision {
public:
	ServerCollision();
	~ServerCollision();

	void CollisionCheck(WorldPtr world, ServerToClientState& state);

private:
	bool Player_Bullet(const Vector3& player, const Vector3& bullet);
	bool Plate_Bullet(const Vector3& plate, const Vector3& bullet);
private:
	std::vector<ServerToClientState> mStates;
	std::vector<Vector3>mEnemyBullets;

	PlateState mPlateStates[15][15];
};