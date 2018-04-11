#include "CollisionActor.h"
#include "Collision\Collision.h"

#include <algorithm>
#include <functional>

//床一マスのサイズ
const float PLATE_SIZE = 50.0f;


CollisionActor::CollisionActor()
{
	//コリジョン追加
	m_Cols[COL_ID::PLAYER_ENEMY_COL] = &(CollisionActor::Player_Enemy_Col);
	m_Cols[COL_ID::PLAYER_PLATE_COL] = &(CollisionActor::Player_Plate_Col);
	m_Cols[COL_ID::PLATE_BULLET_COL] = &(CollisionActor::Plate_Bullet_Col);

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
	player.startPos = actor1.GetParameter().mat.GetPosition() + Vector3::Up*20.0f;
	player.endPos = actor1.GetParameter().mat.GetPosition() + Vector3::Down*5.0f;
	//プレート
	Box plate;
	plate.min = actor2.GetParameter().mat.GetPosition() - Vector3(-PLATE_SIZE, -5.0f, -PLATE_SIZE);
	plate.max = actor2.GetParameter().mat.GetPosition() - Vector3(PLATE_SIZE, 0.0f, PLATE_SIZE);

	colpara = Collisin::GetInstace().SegmentBoxAABB(player, plate);

	colpara.colID = COL_ID::PLAYER_PLATE_COL;

	return colpara;

}

CollisionParameter CollisionActor::Plate_Bullet_Col(const Actor & actor1, const Actor & actor2)
{
	CollisionParameter colpara;
	//プレート
	Box plate;
	plate.min = actor2.GetParameter().mat.GetPosition() - Vector3(-PLATE_SIZE, -5.0f, -PLATE_SIZE);
	plate.max = actor2.GetParameter().mat.GetPosition() - Vector3(PLATE_SIZE, 0.0f, PLATE_SIZE);
	//弾(Line3本引く)

	Vector3 bulletPos = actor1.GetParameter().mat.GetPosition();
	Line bullet1;
	bullet1.startPos = bulletPos + Vector3(4, 0, 0);
	bullet1.endPos = bulletPos + Vector3(-4, 0, 0);;

	Line bullet2;
	bullet2.startPos = bulletPos + Vector3(0, 4, 0);;
	bullet2.endPos = bulletPos + Vector3(0, -4, 0);;
	Line bullet3;
	bullet3.startPos = bulletPos + Vector3(0, 0, 4);;
	bullet3.endPos = bulletPos + Vector3(0, 0, -4);;


	colpara = Collisin::GetInstace().SegmentBoxAABB(bullet1, plate);
	if (!colpara.colFlag)
		colpara = Collisin::GetInstace().SegmentBoxAABB(bullet2, plate);
	if (!colpara.colFlag)
		colpara = Collisin::GetInstace().SegmentBoxAABB(bullet3, plate);

	colpara.colID = COL_ID::PLATE_BULLET_COL;



	return colpara;

}

std::unordered_map<COL_ID, std::function<CollisionParameter(const Actor & actor1, const Actor & actor2)>> CollisionActor::GetCols()
{
	return m_Cols;
}

