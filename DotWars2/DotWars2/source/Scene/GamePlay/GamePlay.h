#pragma once
#include "../Scene.h"
#include "../../IncludePtr.h"
#include "../../World/WorldManager/WorldManager.h"

#include "../../NetWork/MySocketVar2/UDP/Manager/UDPClientSocketManager.h"
class GamePlay :public Scene
{
public:
	GamePlay(WorldManagerPtr manager);
	virtual ~GamePlay() override;
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
	/// <summary>
	/// ネットワークアップデート
	/// </summary>
	void NetWorkUpdate();

private:
	WorldManagerPtr mWorldManager;
	WorldPtr mGameWorld;

	//プレイヤー
	ActorPtr mPlayer;
	//udpマネージャー
	UDPClientSocketManager* mUDPManager;

	//テスト
	int serverCount;
};