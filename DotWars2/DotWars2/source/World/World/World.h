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
	void Start();
	void Update();
	void Draw() const;

	/// <summary>
	/// ワールドにアクターを追加する
	/// </summary>
	/// <param name="id">アクターID</param>
	/// <param name="actor">アクター</param>
	virtual void Add(const ACTOR_ID& id, ActorPtr actor) override;

	/// <summary>
	/// 当たり判定をする
	/// </summary>
	/// <param name="id">当てたいアクターID</param>
	/// <param name="colId">コリジョンの種類</param>
	/// <param name="actor">自身のアクター</param>
	virtual void Collision(const ACTOR_ID& id, const COL_ID& colId, Actor& actor) override;
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
	/// <summary>
	/// ワールドをクリアー
	/// </summary>
	virtual void Clear()override;

private:

	//アクター情報
	std::unordered_map<ACTOR_ID, ActorManager> mActors;
	//ワールドマネージャー
	WorldManagerPtr mWorldManager;
	//あたり判定情報
	std::unordered_map<COL_ID, std::function<CollisionParameter(const Actor & actor1, const Actor & actor2)>> m_Cols;
};