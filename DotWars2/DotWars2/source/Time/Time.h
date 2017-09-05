#pragma once

class Time {
public:
	Time();
	/// <summary>
	/// タイムのインスタンスを取得
	/// </summary>
	/// <returns>タイムインスタンス</returns>
	static Time &GetInstance() {
		static Time t;
		return t;
	}
	/// <summary>
	/// タイムアップデート
	/// </summary>
	void Update();
	/// <summary>
	/// デルタタイムを取得する
	/// </summary>
	/// <returns>デルタタイム</returns>
	float DeltaTime();
private:
	float mLastFrame;
	float mLastTime;
	float mRealtimeSinceStartup;
	float mFrameCount;
	float mDeltaTime;
};