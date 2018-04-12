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
	Player(IWorld& world, const Matrix4& mat, PLAYER_ID id);
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
	/// <summary>
	/// プレイヤーに速度を足す
	/// </summary>
	/// <param name="velocity"></param>
	void SetPlusVelo(const Vector3 velocity);
	/// <summary>
	/// プレイヤーのY軸速度を設定する
	/// </summary>
	/// <param name="velocity"></param>
	void SetVeloY(float velocityY);
	/// <summary>
	/// サーバーに送る情報を取得
	/// </summary>
	/// <returns>情報</returns>
	DotWarsNet GetNetState();
private:
	Vector3 mPosition;

	//速度
	Vector3 mVelo;
	//アクションマネージャー
	ActionManager* mPlayerActionManager;
	//サーバーに送る情報
	DotWarsNet mState;

};