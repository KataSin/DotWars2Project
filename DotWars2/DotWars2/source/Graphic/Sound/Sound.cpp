#include "Sound.h"


void Sound::Load(const SOUND_ID & id, const std::string & name)
{
	mSounds[id] = LoadSoundMem(name.c_str());
}

void Sound::PlayBGM(const SOUND_ID & id)
{
	PlaySoundMem(mSounds[id], DX_PLAYTYPE_LOOP);
}

void Sound::PlaySE(const SOUND_ID & id)
{
	PlaySoundMem(mSounds[id], DX_PLAYTYPE_BACK);
}

bool Sound::IsPlay(const SOUND_ID & id)
{
	return CheckSoundMem(mSounds[id]) == TRUE ? true : false;
}

void Sound::StopSound(const SOUND_ID & id)
{
	StopSoundMem(mSounds[id]);
}

void Sound::SetFrequency(const SOUND_ID& id, int frequency)
{
	SetFrequencySoundMem(frequency, mSounds[id]);
}

void Sound::LoadSound3DFlag(bool flag)
{
	SetCreate3DSoundFlag(flag ? TRUE : FALSE);

}

void Sound::SetSound3dPosition(const SOUND_ID & id, const Vector3 & position)
{
	Set3DPositionSoundMem(Vector3::ToVECTOR(position), mSounds[id]);
}

void Sound::SetNextSound3dPosition(const SOUND_ID & id, const Vector3 & position)
{
	SetNextPlay3DPositionSoundMem(Vector3::ToVECTOR(position), mSounds[id]);
}

void Sound::SetSound3dDistance(const SOUND_ID & id, float distance)
{
	Set3DRadiusSoundMem(distance, mSounds[id]);
}

void Sound::SetSound3dListenerPosAndFront(const Vector3 & position, const Vector3 & frontPos)
{
	Set3DSoundListenerPosAndFrontPos_UpVecY(Vector3::ToVECTOR(position), Vector3::ToVECTOR(frontPos));
}

void Sound::SetSound3dXAudioFlag(bool flag)
{
	SetEnableXAudioFlag(flag ? TRUE : FALSE);
}

void Sound::SoundAllDelete()
{
	InitSoundMem();
	mSounds.clear();
}
