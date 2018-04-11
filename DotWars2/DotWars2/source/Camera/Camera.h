#pragma once
//Math関係
#include "../Math/Vector3.h"
#include "../Math/Matrix4.h"

class Camera
{
private:
	Camera() = default;
	~Camera();
public:
	/// <summary>
	/// インスタンスを取得する
	/// </summary>
	/// <returns></returns>
	static Camera &GetInstance() {
		static Camera m;
		return m;
	}

public:
	/// <summary>
	/// カメラの注視点を設定( ターゲット座標 )
	/// </summary>
	/// <param name="target">ターゲット座標</param>
	void SetTarget(const Vector3& target);
	/// <summary>
	/// カメラの座標を設定( カメラ座標 )
	/// </summary>
	/// <param name="position">カメラ座標</param>
	void SetPosition(const Vector3& position);
	/// <summary>
	/// カメラの上方向を設定( カメラの上ベクトル )
	/// </summary>
	/// <param name="vec">カメラ上ベクトル</param>
	void SetCameraVec(const Vector3& vec);
	/// <summary>
	/// カメラ処理アップデート
	/// </summary>
	void Update();

	/// <summary>
	/// カメラの描写距離を設定(手前、奥)
	/// </summary>
	/// <param name="Near">手前</param>
	/// <param name="Far">奥</param>
	void SetRange(float Near, float Far);
	/// <summary>
	/// カメラの視野角を設定(角度 (度数法) )
	/// </summary>
	/// <param name="angle">角度</param>
	void SetView(float angle);
	/// <summary>
	/// 注視点を取得する
	/// </summary>
	/// <returns>注視点</returns>
	Vector3 GetTarget() const;
	/// <summary>
	/// カメラの座標を取得する
	/// </summary>
	/// <returns></returns>
	Vector3 GetPosition()const;
private:
	//注視点
	Vector3 mTarget;
	//座標
	Vector3 mPosition;
	//カメラ上ベクトル
	Vector3 mCameraVec;
};