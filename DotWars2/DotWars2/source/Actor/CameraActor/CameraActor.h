#pragma once
#include "../Actor.h"
class ActionManager;

class CameraActor :public Actor {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="mat">マトリクス</param>
	CameraActor(IWorld& world);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CameraActor()override;
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
	virtual void  Collision(Actor& other, const CollisionParameter& parameter)override;

private:
	//プレイヤー情報
	ActorPtr mPlayer;
	//カメラの座標
	Vector3 mPosition;
	//回転情報
	Vector3 mRotate;
	//注視点
	Vector3 mTargetPos;
};