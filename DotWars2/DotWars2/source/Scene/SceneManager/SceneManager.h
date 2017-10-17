#pragma once
#include "../Scene.h"
#include <unordered_map>
#include "../../IncludePtr.h"
class SceneManager {
public:
	SceneManager();
	~SceneManager();

	/// <summary>
	/// シーンスタート
	/// </summary>
	void sceneStart();
	/// <summary>
	/// シーンアップデート
	/// </summary>
	void sceneUpdate();
	/// <summary>
	/// シーン描写
	/// </summary>
	void sceneDraw();
	/// <summary>
	/// シーンエンド
	/// </summary>
	void sceneEnd();
	/// <summary>
	/// シーンを追加する
	/// </summary>
	/// <param name="id">追加するシーンID</param>
	/// <param name="scenePtr">追加するシーン</param>
	void AddScene(const SceneID& id, ScenePtr scenePtr);
	/// <summary>
	/// 最初に表示するシーン
	/// </summary>
	/// <param name="id"></param>
	void StartScene(const SceneID& id);
private:
	/// <summary>
	/// シーンを変更させる
	/// </summary>
	/// <param name="id">変更させるSceneID</param>
	void SceneChange(const SceneID& id);
	/// <summary>

private:
	//シーンたち
	std::unordered_map<SceneID, ScenePtr>mScenes;
	//現在のシーン
	SceneID mNowSceneID;
};