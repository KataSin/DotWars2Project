#pragma once
#include "Collision\Collision.h"
#include "../Actor.h"
#include "../ActorID.h"
#include <unordered_map>
#include <functional>
class CollisionActor {
public:
	CollisionActor();
	~CollisionActor();
	/// <summary>
	/// プレイヤーとエネミーのあたり判定
	/// </summary>
	/// <param name="actor1">プレイヤー</param>
	/// <param name="actor2">エネミー</param>
	/// <returns>コリジョンパラメーター</returns>
	CollisionParameter Player_Enemy_Col(Actor & actor1, Actor & actor2);
	/// <summary>
	/// コリジョン情報を取得
	/// </summary>
	/// <returns>コリジョン情報</returns>
	std::unordered_map<COL_ID, std::function<CollisionParameter>> GetCols();
	
private:
	std::unordered_map<COL_ID, std::function<CollisionParameter>> m_Cols;

};