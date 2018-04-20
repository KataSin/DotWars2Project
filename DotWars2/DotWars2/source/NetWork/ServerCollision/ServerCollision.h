#pragma once
#include "../../Math/Vector3.h"
#include "../../Actor/ActorID.h"
#include "../NetGameState.h"
#include "../../World/World/World.h"
#include <vector>

//取得した弾の情報
struct NetBulletState {
	Vector3 bulletPos;	//弾の座標
	PLAYER_ID playerID;	//プレイヤーの座標
};
//プレート情報
struct PlateState {
	Vector3 position;
	int hp;
};
//サーバー側でコリジョン判定をするためのクラス
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