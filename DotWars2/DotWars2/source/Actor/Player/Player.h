#pragma once
#include "../Actor.h"


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
	/// アップデート
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描写
	/// </summary>
	virtual void Draw() const override;
};