#include "CollisionActor.h"
#include "Collision\Collision.h"

#include <algorithm>
#include <functional>
CollisionActor::CollisionActor()
{
	//コリジョン追加
	m_Cols[COL_ID::PLAYER_ENEMY_COL] = &(CollisionActor::Player_Enemy_Col);
	m_Cols[COL_ID::PLAYER_PLATE_COL] = &(CollisionActor::Player_Plate_Col);

}

CollisionActor::~CollisionActor()
{
	m_Cols.clear();
}

CollisionParameter CollisionActor::Player_Enemy_Col(const Actor & actor1, const Actor & actor2)
{
	CollisionParameter colpara;
	//プレイヤー
	Sphere player;
	player.position = actor1.GetParameter().mat.GetPosition();
	player.radius = 20.0f;
	//エネミー
	Sphere enemy;
	enemy.position = actor2.GetParameter().mat.GetPosition();
	enemy.radius = 20.0f;

	colpara.colID = COL_ID::PLAYER_ENEMY_COL;
	colpara = Collisin::GetInstace().SphereSphere(player, enemy);

	return colpara;
}

CollisionParameter CollisionActor::Player_Plate_Col(const Actor & actor1, const Actor & actor2)
{
	CollisionParameter colpara;
	//プレイヤー
	Line player;
	player.startPos = actor1.GetParameter().mat.GetPosition();
	player.endPos = actor1.GetParameter().mat.GetPosition() - Vector3::Down*10.0f;
	//プレート
	Box plate;
	plate.min = actor2.GetParameter().mat.GetPosition() - Vector3(-50, 0, -50);
	plate.max = actor2.GetParameter().mat.GetPosition() - Vector3(50, 5, 50);

	colpara = Collisin::GetInstace().SegmentBoxAABB(player, plate);

	colpara.colID = COL_ID::PLAYER_PLATE_COL;

	return colpara;

}

std::unordered_map<COL_ID, std::function<CollisionParameter(const Actor & actor1, const Actor & actor2)>> CollisionActor::GetCols()
{
	return m_Cols;
}

