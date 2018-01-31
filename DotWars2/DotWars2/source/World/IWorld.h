#pragma once
#include "../IncludePtr.h"
#include "WorldID.h"
#include "../Actor/CollisionActor/Collision/Collision.h"
#include "../Actor/ActorID.h"
#include <list>
class IWorld {
public:
	virtual ~IWorld() {}
	/// <summary>
	/// ワールドにアクターを追加する
	/// </summary>
	/// <param name="id">ワールドID</param>
	/// <param name="actor">アクター</param>
	virtual void Add(const ACTOR_ID& id, ActorPtr actor) = 0;
	/// <summary>
	/// 当たり判定をする
	/// </summary>
	/// <param name="id">当てたいアクターID</param>
	/// <param name="colId">コリジョンの種類</param>
	/// <param name="actor">自身のアクター</param>
	virtual void Collision(const ACTOR_ID& id, const COL_ID& colId, Actor& actor) = 0;
	/// <summary>
	/// 指定したアクターたちを探す
	/// </summary>
	virtual std::list<ActorPtr> FindActors(const ACTOR_ID& id) = 0;
	/// <summary>
	/// 指定したワールドを取得する
	/// </summary>
	/// <param name="id">ワールドID</param>
	virtual WorldPtr FindWorld(const WORLD_ID& id) = 0;
	/// <summary>
	/// 指定したアクターの数を取得
	/// </summary>
	/// <param name="id">アクターID</param>
	/// <returns>カウント</returns>
	virtual int ActorsCount(const ACTOR_ID& id) = 0;
	/// <summary>
	/// ワールドをクリアー
	/// </summary>
	virtual void Clear() = 0;
};