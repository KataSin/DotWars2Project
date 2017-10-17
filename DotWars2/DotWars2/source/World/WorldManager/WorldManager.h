#pragma once
#include "../WorldID.h"
#include "../../IncludePtr.h"
#include "../World/World.h"
#include <unordered_map>
class WorldManager {
public:
	struct WorldState {
		WorldPtr world; //ワールド
		bool isStop;    //止まっているかどうか
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
	/// ワールドマネージャーをクリア
	/// </summary>
	void ManagerClear();
	/// <summary>
	/// ワールドをクリアー
	/// </summary>
	void WorldAllClear();
	/// <summary>
	/// 指定したワールドをクリアー
	/// </summary>
	/// <param name="id"></param>
	void WorldClear(const WORLD_ID& id);
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
	/// <summary>
	/// 指定したワールドを取得する
	/// </summary>
	/// <param name="id">ワールドID</param>
	/// <returns>ワールドポインター</returns>
	WorldPtr GetWorld(const WORLD_ID& id);

private:
	std::unordered_map<WORLD_ID, WorldState> mWorlds;

};