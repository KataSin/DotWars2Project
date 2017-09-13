#pragma once
//--------------------------------//
//--------�T�E���h�N���X--------//
//---------�쐬:�Љ��C��----------//
//--------------------------------//
#include <string>
#include "../GraphicID.h"
#include "../../Math/Vector3.h"
#include <unordered_map>
class Sound {

private:
	Sound() = default;
	~Sound() {};
public:
	/// <summary>
	/// �C���X�^���X���擾����
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static Sound &GetInstance() {
		static Sound m;
		return m;
	}
	/// <summary>
	/// ���[�h����(�t�@�C����)
	/// </summary>
	/// <param name="id">�T�E���hID</param>
	/// <param name="name">�t�@�C����</param>
	void Load(const SOUND_ID& id, const std::string& name);
	/// <summary>
	/// BGM���Đ�����(Loop����)(�T�E���hID)
	/// </summary>
	/// <param name="id">�T�E���hID</param>
	void PlayBGM(const SOUND_ID& id);
	/// <summary>
	/// SE���Đ�����(Loop���Ȃ�)(�T�E���hID)
	/// </summary>
	/// <param name="id">�T�E���hID</param>
	void PlaySE(const SOUND_ID& id);
	/// <summary>
	/// �����Đ�����Ă��邩�H
	/// </summary>
	/// <param name="id">�T�E���hID</param>
	/// <returns>�Đ�����Ă��邩�H</returns>
	bool IsPlay(const SOUND_ID& id);
	/// <summary>
	/// �����X�g�b�v����
	/// </summary>
	/// <param name="id">�T�E���hID</param>
	void StopSound(const SOUND_ID& id);
	/// <summary>
	/// ���̎��g����ݒ肷��(���g��(-1�Ńf�t�H���g))
	/// </summary>
	/// <param name="id">�T�E���hID</param>
	/// <param name="frequency">���g��</param>
	void SetFrequency(const SOUND_ID& id,int frequency);

	//3D�T�E���h�֌W
	/// <summary>
	/// 3D�T�E���h�œǂݍ��ނ�(true:3D�T�E���h�œǂݍ��ށAfalse:2D�T�E���h�œǂݍ���)
	/// </summary>
	/// <param name="flag">�ǂݍ��ނ��ǂ����t���O</param>
	void LoadSound3DFlag(bool flag);
	/// <summary>
	/// ���̍Đ�������W��ύX����(�T�E���hID�A���W)
	/// </summary>
	/// <param name="id">�T�E���hID</param>
	/// <param name="position">���W</param>
	void SetSound3dPosition(const SOUND_ID& id, const Vector3& position);
	/// <summary>
	/// ���̉����Đ�������W��ύX����(�T�E���hID�A���W)
	/// </summary>
	/// <param name="id">�T�E���hID</param>
	/// <param name="position">���W</param>
	void SetNextSound3dPosition(const SOUND_ID& id, const Vector3& position);
	/// <summary>
	/// ������������͈͂�ݒ肷��(�T�E���hID�A�������鋗��)
	/// </summary>
	/// <param name="id">�T�E���hID</param>
	/// <param name="distance">�������鋗��</param>
	void SetSound3dDistance(const SOUND_ID& id, float distance);
	/// <summary>
	/// 3D�T�E���h���X�i�[(���݂�����)�̍��W�ƑO�x�N�g����ݒ肷��(���W�A�O�x�N�g��)
	/// </summary>
	/// <param name="position">���W</param>
	/// <param name="frontPos">�O�x�N�g��</param>
	void SetSound3dListenerPosAndFront(const Vector3& position, const Vector3& frontPos);
	/// <summary>
	/// XAudio2���g�p���邩�ǂ�����3D�T�E���h�g���Ȃ�true(true:�g�p����,false:�g�p���Ȃ�)
	/// </summary>
	/// <param name="flag">�g�����ǂ���</param>
	void SetSound3dXAudioFlag(bool flag);
	/// <summary>
	/// �S�ẴT�E���h���폜����
	/// </summary>
	void SoundAllDelete();
private:
	//�T�E���h����
	std::unordered_map<SOUND_ID, int>mSounds;
};