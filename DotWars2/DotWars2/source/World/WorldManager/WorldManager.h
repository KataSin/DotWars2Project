#pragma once
#include "../WorldID.h"
#include "../../IncludePtr.h"
#include "../World/World.h"
#include <unordered_map>
class WorldManager {
public:
	struct WorldState {
		WorldPtr world;
		bool isStop;
	};


public:
	WorldManager();
	~WorldManager();

	/// <summary>
	/// ワールドアップデート
	/// </summary>
	void Update();
	/// <summary>
	/// ワールド描写
	/// </summary>
	void Draw() const;
	/// <summary>
	/// <summary>
	/// ワールドをクリア
	/// </summary>
	void Clear();
	/// <summary>
	/// ワールドを追加する
	/// </summary>
	/// <param name="id"></param>
	/// <param name="world"></param>
	void Add(const WORLD_ID& id, WorldPtr world);
	/// <summary>
	/// 指定したワールドのアップデートを止める
	/// </summary>
	/// <param name="id">ワールドID</param>
	void WorldStop(const WORLD_ID& id);
	/// <summary>
	/// 指定したワールドをアップデートをスタートさせる
	/// </summary>
	/// <param name="id">ワールドID</param>
	void WorldStart(const WORLD_ID& id);

	WorldPtr GetWorld(const WORLD_ID& id);

private:
	std::unordered_map<WORLD_ID, WorldState> mWorlds;

};