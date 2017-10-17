#pragma once
#include "SceneID.h"
class Scene {
public:
	virtual ~Scene() = 0;
	/// <summary>
	/// シーンスタート
	/// </summary>
	virtual void Start() = 0;
	/// <summary>
	/// シーンアップデート
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描写
	/// </summary>
	virtual void Draw() const = 0;
	/// <summary>
	/// 終了処理
	/// </summary>
	virtual void End() = 0;
	/// <summary>
	/// 自身のシーンを返す
	/// </summary>
	/// <returns>シーンID</returns>
	virtual SceneID GetMySceneId();
	/// <summary>
	/// 次に移行するシーンを返す
	/// </summary>
	/// <returns></returns>
	virtual SceneID GetNextSceneId();
	/// <summary>
	/// 終わったかどうか返す
	/// </summary>
	/// <returns>終わったかどうかフラグ</returns>
	virtual bool GetIsEnd();
protected:
	//次のシーン
	SceneID mNextScene;
	//自身のシーン
	SceneID mMyScene;
	//終わったかどうか
	bool mIsEnd;
};