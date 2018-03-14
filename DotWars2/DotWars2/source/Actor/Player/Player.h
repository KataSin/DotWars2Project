#pragma once
#include "../Actor.h"
#include "ActionManager\ActionManager.h"

class Player :public Actor {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="mat">マトリクス</param>
	Player(IWorld& world, const Matrix4& mat);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Player()override;
	/// <summary>
	/// スタート
	/// </summary>
	virtual void Start() override;
	/// <summary>
	/// アップデート
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描写
	/// </summary>
	virtual void Draw() const override;
	/// <summary>
	///	当たり判定
	/// </summary>
	/// <param name="other">当たったオブジェクト</param>
	virtual void Collision(Actor& other, const CollisionParameter& parameter)override;
	/// <summary>
	/// プレイヤーの状態を取得する
	/// </summary>
	ActionBehavior GetState();

private:
	Vector3 mPosition;

	ActionManager* mPlayerActionManager;
	ActionManager* mCameraActionManager;
};