#pragma once
#include "../Scene.h"
#include "../../IncludePtr.h"
#include "../../World/WorldManager/WorldManager.h"
class Title :public Scene
{
public:
	Title(WorldManagerPtr manager);
	virtual ~Title() override;
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
};