#pragma once
#include "../Scene.h"
#include "../../IncludePtr.h"
#include "../../World/WorldManager/WorldManager.h"

#include "../../NetWork/ServerCollision/ServerCollision.h"

//先行宣言
class UDPServerSocketManager;

class GamePlayServer :public Scene
{
public:
	GamePlayServer(WorldManagerPtr manager);
	virtual ~GamePlayServer() override;
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
	//UDPマネージャー
	UDPServerSocketManager* mUDPManager;
	
	ServerCollision* mServerCollision;
	
	WorldManagerPtr mWorldManager;

	//テスト
	std::string debug;
	int serverCount;
};