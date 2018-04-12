#pragma once
#include "../Actor.h"

struct EnemyPlayerState {
	Vector3 pos; //ポジション
	int stateID;//状態ID
	PLAYER_ID id;//プレイヤーのID
};
class EnemyPlayer :public Actor {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="mat">マトリクス</param>
	EnemyPlayer(IWorld& world, const EnemyPlayerState& state);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~EnemyPlayer()override;
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
	/// エネミープレイヤー情報を設定する
	/// </summary>
	/// <param name="state"></param>
	void SetEnemyPlayerState(const EnemyPlayerState& state);
private:
	//移動のベクトル
	Vector3 mVec;
	//ベクトルを求めるための座標
	Vector3 mSeveVec;

	EnemyPlayerState mState;
};