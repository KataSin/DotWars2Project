#pragma once
#include "../Actor.h"


class BulletPoint :public Actor {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="mat">マトリクス</param>
	BulletPoint(IWorld& world);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~BulletPoint()override;
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

private:
	//カメラアクター
	ActorPtr mCameraActor;
	//座標
	Vector3 mPosition;
	//距離の数字
	float mDisNum;
	//
};