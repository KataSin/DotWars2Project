#pragma once
#include "../IncludePtr.h"
#include "../Actor/ActorID.h"
#include "WorldID.h"
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
	virtual int ActorsCount(const ACTOR_ID& id)=0;
};