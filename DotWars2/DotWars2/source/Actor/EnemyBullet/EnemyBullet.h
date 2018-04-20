#pragma once
#include "../Actor.h"

#include "../PlayerBullet/PlayerBullet.h"

class EnemyBullet :public Actor {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="state">弾の情報</param>
	EnemyBullet(IWorld& world, const PlayerBullet::BulletState& state);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~EnemyBullet()override;
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

	void SetPosition(const Vector3& pos) {
		mPosition = pos;
	}

private:
	//ベクトル
	Vector3 mVec;
	//ベクトルY
	float mVecY;
	//位置
	Vector3 mPosition;
	//出現する位置
	Vector3 mStartPos;
	//頂点の位置
	Vector3 mVertexPoint;
	//距離
	Vector3 mDistance;
	//時間
	float mTime;
	//ランダム座標
	Vector3 mRandVec;
	//ランダム回転
	Vector3 mRandRotate;
	//回転
	Vector3 mRotate;
	//カラー
	Vector4 mColor;

	float mCoppyPosY;
};