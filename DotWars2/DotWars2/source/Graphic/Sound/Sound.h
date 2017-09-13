#pragma once
//--------------------------------//
//--------サウンドクラス--------//
//---------作成:片岡辰悟----------//
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
	/// インスタンスを取得する
	/// </summary>
	/// <returns>インスタンス</returns>
	static Sound &GetInstance() {
		static Sound m;
		return m;
	}
	/// <summary>
	/// ロードする(ファイル名)
	/// </summary>
	/// <param name="id">サウンドID</param>
	/// <param name="name">ファイル名</param>
	void Load(const SOUND_ID& id, const std::string& name);
	/// <summary>
	/// BGMを再生する(Loopする)(サウンドID)
	/// </summary>
	/// <param name="id">サウンドID</param>
	void PlayBGM(const SOUND_ID& id);
	/// <summary>
	/// SEを再生する(Loopしない)(サウンドID)
	/// </summary>
	/// <param name="id">サウンドID</param>
	void PlaySE(const SOUND_ID& id);
	/// <summary>
	/// 音が再生されているか？
	/// </summary>
	/// <param name="id">サウンドID</param>
	/// <returns>再生されているか？</returns>
	bool IsPlay(const SOUND_ID& id);
	/// <summary>
	/// 音をストップする
	/// </summary>
	/// <param name="id">サウンドID</param>
	void StopSound(const SOUND_ID& id);
	/// <summary>
	/// 音の周波数を設定する(周波数(-1でデフォルト))
	/// </summary>
	/// <param name="id">サウンドID</param>
	/// <param name="frequency">周波数</param>
	void SetFrequency(const SOUND_ID& id,int frequency);

	//3Dサウンド関係
	/// <summary>
	/// 3Dサウンドで読み込むか(true:3Dサウンドで読み込む、false:2Dサウンドで読み込む)
	/// </summary>
	/// <param name="flag">読み込むかどうかフラグ</param>
	void LoadSound3DFlag(bool flag);
	/// <summary>
	/// 音の再生する座標を変更する(サウンドID、座標)
	/// </summary>
	/// <param name="id">サウンドID</param>
	/// <param name="position">座標</param>
	void SetSound3dPosition(const SOUND_ID& id, const Vector3& position);
	/// <summary>
	/// 次の音を再生する座標を変更する(サウンドID、座標)
	/// </summary>
	/// <param name="id">サウンドID</param>
	/// <param name="position">座標</param>
	void SetNextSound3dPosition(const SOUND_ID& id, const Vector3& position);
	/// <summary>
	/// 音が聞こえる範囲を設定する(サウンドID、聞こえる距離)
	/// </summary>
	/// <param name="id">サウンドID</param>
	/// <param name="distance">聞こえる距離</param>
	void SetSound3dDistance(const SOUND_ID& id, float distance);
	/// <summary>
	/// 3Dサウンドリスナー(耳みたいな)の座標と前ベクトルを設定する(座標、前ベクトル)
	/// </summary>
	/// <param name="position">座標</param>
	/// <param name="frontPos">前ベクトル</param>
	void SetSound3dListenerPosAndFront(const Vector3& position, const Vector3& frontPos);
	/// <summary>
	/// XAudio2を使用するかどうか※3Dサウンド使うならtrue(true:使用する,false:使用しない)
	/// </summary>
	/// <param name="flag">使うかどうか</param>
	void SetSound3dXAudioFlag(bool flag);
	/// <summary>
	/// 全てのサウンドを削除する
	/// </summary>
	void SoundAllDelete();
private:
	//サウンドたち
	std::unordered_map<SOUND_ID, int>mSounds;
};