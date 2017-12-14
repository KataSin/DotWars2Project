#pragma once
#include "../IncludePtr.h"
#include "../World/WorldManager/WorldManager.h"
#include "../World/World/World.h"

#include "../NetWork/MySocket/MySocketClient/MySocketClient.h"
#include "../NetWork/MySocket/MySocketClientManager/MySocketClientManager.h"
#include "../NetWork/MySocket/MySocketServer/MySocketServer.h"
#include "../NetWork/MySocket/MySocketServerManager/MySocketServerManager.h"
#include "../NetWork/MySocket/MySocketPtr.h"



#include <memory>
class Game {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="windowWight">ウィンドウの横</param>
	/// <param name="windowHeght">ウィンドウの縦</param>
	/// <param name="fullScene">フルスクリーンかどうか</param>
	Game(int windowWight, int windowHeght, bool fullScene = true);
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Game();
	/// <summary>
	/// 初期処理
	/// </summary>
	void Start();
	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();
	/// <summary>
	/// 描写処理
	/// </summary>
	void Draw()const;
	/// <summary>
	/// 終わったら呼ばれる
	/// </summary>
	void End();
private:

	MySocketClientManager* clientManager;
	MySocketServerManager* serverManager;



	std::vector<DotWarsNet> mServerState;

	
	//サーバーかどうか
	bool serverFlag;
	//ワールドポインター
	WorldManagerPtr mWorldManager;
	//シーンマネージャー
	SceneManagerPtr mSceneManager;

	int stageNum;
	

	int playerNum;

	DotWarsNet mClientState;
	std::string debug;
};