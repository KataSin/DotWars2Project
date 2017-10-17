#pragma once
#include "../IncludePtr.h"
#include "../World/WorldManager/WorldManager.h"
#include "../World/World/World.h"

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
	//ワールドポインター
	WorldManagerPtr mWorldManager;
	//シーンマネージャー
	SceneManagerPtr mSceneManager;
};