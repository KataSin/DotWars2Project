#pragma once
#include "../Scene.h"
#include "../../IncludePtr.h"
#include "../../World/WorldManager/WorldManager.h"

#include "../../NetWork/MySocketVar2/TCP/Manager/TCPClientSocketManager.h"
#include "../../NetWork/MySocketVar2/UDP/Manager/UDPClientSocketManager.h"

class Matching :public Scene
{
public:
	Matching(WorldManagerPtr manager);
	virtual ~Matching() override;
	/// <summary>
	/// シーンスタート
	/// </summary>
	virtual void Start() override;
	/// <summary>
	/// シーンアップデート
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描写
	/// </summary>
	virtual void Draw() const override;
	/// <summary>
	/// 終了処理
	/// </summary>
	virtual void End() override;
private:
	//ワールドマネージャー
	WorldManagerPtr mWorldManager;
	//通信系
	TCPClientSocketManager* mTCPManager;
	UDPClientSocketManager* mUDPManager;
	//通信どこまで行ってるか
	int mStageNum;

	//最初の情報
	FirstToClientState mFirstState;
	
	//

	//テスト
	int clientCount;
	std::string debug;

};