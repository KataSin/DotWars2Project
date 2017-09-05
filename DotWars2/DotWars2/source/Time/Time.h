#pragma once

class Time {
public:
	Time();
	/// <summary>
	/// �^�C���̃C���X�^���X���擾
	/// </summary>
	/// <returns>�^�C���C���X�^���X</returns>
	static Time &GetInstance() {
		static Time t;
		return t;
	}
	/// <summary>
	/// �^�C���A�b�v�f�[�g
	/// </summary>
	void Update();
	/// <summary>
	/// �f���^�^�C�����擾����
	/// </summary>
	/// <returns>�f���^�^�C��</returns>
	float DeltaTime();
private:
	float mLastFrame;
	float mLastTime;
	float mRealtimeSinceStartup;
	float mFrameCount;
	float mDeltaTime;
};