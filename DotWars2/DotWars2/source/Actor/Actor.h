#pragma once
//Math関係
#include "../Math/Math.h"
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include "../Math/Vector4.h"
#include "../Math/Matrix4.h"
//その他
#include "../World/IWorld.h"
#include "../World/World/World.h"
struct Parameter {
	//マトリクス
	Matrix4 mat;
	//死んでいるか
	bool isDead;
};

class Actor {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="world">ワールド</param>
	Actor(IWorld& world);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Actor();
	/// <summary>
	/// アップデート
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描写
	/// </summary>
	virtual void Draw() const = 0;
	/// <summary>
	///	死んでいるか取得
	/// </summary>
	/// <returns>死んでいるかフラグ</returns>
	bool GetIsDead()const;
	/// <summary>
	/// パラメーターを取得
	/// </summary>
	/// <returns>パラメーター</returns>
	Parameter GetParameter() const;
protected:
	Parameter mParameter;
};
