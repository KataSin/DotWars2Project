#pragma once
#include "../Actor.h"


class Stage :public Actor {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="mat">マトリクス</param>
	Stage(IWorld& world);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Stage()override;
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
	//廻のステージのマトリクス
	Matrix4 mStageMat;

public:
	ActorPtr mPlates[16][16];
};