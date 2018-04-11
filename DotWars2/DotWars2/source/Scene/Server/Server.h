#pragma once
#include <string>

#include "../Scene.h"
#include "../../IncludePtr.h"

#include "../../NetWork/MySocketVar2/TCP/Manager/TCPServerSocketManager.h"
#include "../../NetWork/MySocketVar2/UDP/Manager/UDPServerSocketManager.h"

class Server :public Scene
{
public:
	Server(WorldManagerPtr manager);
	virtual ~Server() override;
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
	TCPServerSocketManager* mTCPManager;
	UDPServerSocketManager* mUDPManager;
	//通信どこまで行ってるか
	int mStageNum;

	//テスト
	int serverCount;
	std::string debug;
};