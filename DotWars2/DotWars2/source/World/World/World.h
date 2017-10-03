#pragma once
#include "../../IncludePtr.h"
#include "../WorldManager/WorldManager.h"
#include "../IWorld.h"
#include "../../Actor/ActorManager.h"
#include "../../Actor/CollisionActor/CollisionActor.h"
#include <list>
#include <vector>
#include <unordered_map>
#include <functional>
class World :public IWorld {
public:
	World(WorldManagerPtr manager);
	~World();

	void Update();
	void Draw() const;

	/// <summary>
	/// ワールドにアクターを追加する
	/// </summary>
	/// <param name="id">アクターID</param>
	/// <param name="actor">アクター</param>
	virtual void Add(const ACTOR_ID& id, ActorPtr actor) override;
	/// <summary>
	/// 指定したアクターたちを探す
	/// </summary>
	/// <param name="id">アクターID</param>
	/// <returns>アクターたち</returns>
	virtual std::list<ActorPtr> FindActors(const ACTOR_ID& id) override;
	/// <summary>
	/// 指定したワールドを取得する
	/// </summary>
	/// <param name="id">ワールドID</param>
	virtual WorldPtr FindWorld(const WORLD_ID& id) override;
	/// <summary>
	/// 指定したアクターの数を取得
	/// </summary>
	/// <param name="id">アクターID</param>
	virtual int ActorsCount(const ACTOR_ID& id) override;

private:
	//アクター情報
	std::unordered_map<ACTOR_ID, ActorManager> mActors;
	//ワールドマネージャー
	WorldManagerPtr mWorldManager;
	//あたり判定情報
	std::unordered_map<COL_ID, std::function<CollisionParameter>> m_Cols;
};