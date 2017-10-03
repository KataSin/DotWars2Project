#include "CollisionActor.h"
#include "../ActorID.h"
#include <algorithm>
#include <functional>
CollisionActor::CollisionActor()
{
	m_Cols[COL_ID::PLAYER_ENEMY_COL] = std::bind(&CollisionActor::Player_Enemy_Col);
}

CollisionActor::~CollisionActor()
{
	m_Cols.clear();
}

CollisionParameter CollisionActor::Player_Enemy_Col(Actor & actor1, Actor & actor2)
{
	CollisionParameter colpara;
	//プレイヤー
	Sphere player;
	player.position = actor1.GetParameter().mat.GetPosition();
	player.radius = 2.0f;
	//エネミー
	Sphere enemy;
	enemy.position = actor2.GetParameter().mat.GetPosition();
	enemy.radius = 2.0f;

	colpara.colID = COL_ID::PLAYER_ENEMY_COL;
	colpara = Collisin::GetInstace().SphereSphere(player, enemy);

	return colpara;
}

std::unordered_map<COL_ID, std::function<CollisionParameter>> CollisionActor::GetCols()
{
	return m_Cols;
}

