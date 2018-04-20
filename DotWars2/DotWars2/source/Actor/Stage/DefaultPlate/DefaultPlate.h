#pragma once
#include "../../Actor.h"


class DefaultPlate :public Actor {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="mat">マトリクス</param>
	DefaultPlate(IWorld& world, const Matrix4& mat);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~DefaultPlate()override;
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



	void SetHp(int hp) {
		mPlateHp = hp;
	}
private:
	//リスポーン時間
	float mRespawnTime;
	//壊れたかどうか
	bool mIsBreak;
	//プレートのHP
	int mPlateHp;
};