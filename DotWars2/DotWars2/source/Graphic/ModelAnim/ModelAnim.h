//----------------------------------------------//
//--------モデルアニメーション描写クラス--------//
//---------------作成:片岡辰悟------------------//
//----------------------------------------------//
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
//グラフィックID
#include "../GraphicID.h"
//Math関係
#include "../../Math/Vector3.h"
#include "../../Math/Matrix4.h"
#include "../../Math/Vector4.h"
class ModelAnim {

private:
	ModelAnim() = default;
	~ModelAnim() {};
public:
	/// <summary>
	/// インスタンスを取得する
	/// </summary>
	/// <returns>インスタンス</returns>
	static ModelAnim &GetInstance() {
		static ModelAnim m;
		return m;
	}
public:
	/// <summary>
	/// 3Dモデルの読み込み(ファイル名、アニメモデルID、最初のモーションID)
	/// </summary>
	/// <param name="name">ファイル名</param>
	/// <param name="id">アニメモデルID</param>
	void Load(const std::string& name, const MODEL_ANIM_ID& id,const MODEL_MOTION_ID& motionId);
	/// <summary>
	/// 3Dモデルの削除
	/// </summary>
	/// <param name="id">モデルID</param>
	void Delete(const MODEL_ANIM_ID& id);
	/// <summary>
	/// アニメーションをアタッチする(アニメーションモデルID、モーションID)
	/// </summary>
	/// <param name="id">アニメーションモデルID</param>
	/// <param name="motionID">モーションID</param>
	void AttachAnim(const MODEL_ANIM_ID&id, const MODEL_MOTION_ID& motionID);
	/// <summary>
	/// アニメーションをデタッチする(アニメーションモデルID、モーションID)
	/// </summary>
	/// <param name="id">アニメーションモデルID</param>
	/// <param name="motionID">モーションID</param>
	void DetachAnim(const MODEL_ANIM_ID& id, const MODEL_MOTION_ID& motionID);
	/// <summary>
	/// モーションをチェンジする
	/// </summary>
	/// <param name="id">モデルID</param>
	/// <param name="motionId">モーションID</param>
	void ChangeAnim(const MODEL_ANIM_ID& id, const MODEL_MOTION_ID& motionId);
	/// <summary>
	/// アニメーションを再生する(モデルアニメーションID)
	/// </summary>
	/// <param name="id">モデルアニメーションID</param>
	void StartAnim(const MODEL_ANIM_ID& id);
	/// <summary>
	/// アニメーションを停止させる(モデルアニメーションID)
	/// </summary>
	/// <param name="id">モデルアニメーションID</param>
	void StopAnim(const MODEL_ANIM_ID& id);

	/// <summary>
	/// アップデート
	/// </summary>
	void Update();
	/// <summary>
	/// アニメーションモデルを描写(アニメーションモデルID、マトリックス、α値、ディフェーズカラー)
	/// </summary>
	/// <param name="id">アニメーションモデルID</param>
	/// <param name="mat">マトリックス</param>
	/// <param name="alpha">α値</param>
	/// <param name="color">ディフェーズカラー</param>
	void Draw(const MODEL_ANIM_ID& id, const Matrix4& mat, float alpha = 1.0f, const Vector4& diffuse = Vector4(255, 255, 255, 1));
	/// <summary>

private:




	/// モデルハンドル情報
	/// </summary>
	class ModelAnimHandle {
	public:
		struct AttachState
		{
			int index;
			float animTime;
			float animAllTime;
		};
	public:
		ModelAnimHandle();
		~ModelAnimHandle();
	public:
		/// <summary>
		/// ハンドルを取得
		/// </summary>
		int GetHandle();
		/// <summary>
		/// モデルを読み込む
		/// </summary>
		/// <param name="fileName">ファイル名</param>
		/// <param name="motionId">最初に再生させるモーションID</param>
		void Load(const std::string fileName, const MODEL_MOTION_ID& motionId);
		/// <summary>
		/// 削除
		/// </summary>
		void Delete();
		/// <summary>
		/// <summary>
		/// アニメーションをアタッチする(モーションID)
		/// </summary>
		/// <param name="motionId">モーションID</param>
		void Attach(const MODEL_MOTION_ID& motionId);
		/// <summary>
		/// アニメーションをデタッチする(モーションID)
		/// </summary>
		/// <param name="motionId">モーションID</param>
		void Detach(const MODEL_MOTION_ID& motionId);
		/// <summary>
		/// アタッチインデックスを取得する(モーションID)
		/// </summary>
		/// <param name="motionId">モーションID</param>
		/// <returns></returns>
		int GetAttachIndex(const MODEL_MOTION_ID& motionId);
		/// <summary>
		/// アニメーションの総時間を返す
		/// </summary>
		/// <param name="motionId">モーションID</param>
		/// <returns>アニメーション総時間</returns>
		float GetAllAnimTime(const MODEL_MOTION_ID& motionId);
		/// <summary>
		/// アニメーションタイムを設定する
		/// </summary>
		/// <param name="motionId">モーションID</param>
		/// <param name="time">アニメタイム</param>
		void SetAnimTime(const MODEL_MOTION_ID& motionId, float time);
		/// <summary>
		/// アニメーションをスタートさせる
		/// </summary>
		void StartAnim();
		/// <summary>
		/// アニメーションをストップさせる
		/// </summary>
		void StopAnim();
		/// <summary>
		/// アニメーションをチェンジ
		/// </summary>
		/// <param name="motionId"></param>
		void ChangeAnim(const MODEL_MOTION_ID& motionId);
		/// <summary>
		/// アップデート
		/// </summary>
		void Update();
	private:
		//再生しているか
		bool isPlay;
		//現在再生されているモーション
		MODEL_MOTION_ID CurMotionId;
		//前に再生されていたモーション
		MODEL_MOTION_ID PreMotionId;
		//移行補間中か
		bool isLerpAnim;
	private:
		int handle;
		float animAllTime;
		//補間用タイム
		float lerpAnimTime;
		//アタッチされているモーションたち
		std::unordered_map<MODEL_MOTION_ID, AttachState >mAttachNums;
	};

private:

	//スマートポインター
	using HandlePtr = std::shared_ptr<ModelAnimHandle>;
	//モデルハンドル情報
	std::unordered_map<MODEL_ANIM_ID, HandlePtr> mModels;
};