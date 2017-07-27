//--------------------------------//
//--------モデル描写クラス--------//
//---------作成:片岡辰悟----------//
//--------------------------------//
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
class Model
{
private:
	Model() = default;
	~Model();
public:
	/// <summary>
	/// インスタンスを取得する
	/// </summary>
	/// <returns>インスタンス</returns>
	static Model &GetInstance() {
		static Model m;
		return m;
	}

public:
	/// <summary>
	/// 3Dモデルの読み込み(ファイル名、モデルID)
	/// </summary>
	/// <param name="name">ファイル名</param>
	/// <param name="id">モデルID</param>
	void Load(const std::string& name, const MODEL_ID& id);
	/// <summary>
	/// <summary>
	/// 3Dモデルの読み込み(モデルのあたり判定を使いたい場合)
	/// </summary>
	/// <param name="name">ファイル名</param>
	/// <param name="id">モデルID</param>
	void LoadCollision(const std::string& name, const MODEL_ID& id);
	/// <summary>
	/// 3Dモデルの削除
	/// </summary>
	/// <param name="id">モデルID</param>
	void Delete(const MODEL_ID& id);
	/// <summary>
	/// 3Dモデルの描写(モデルID、座標)
	/// </summary>
	/// <param name="id">モデルID</param>
	/// <param name="position">座標</param>
	void Draw(const MODEL_ID& id, const Vector3& position);
	/// <summary>
	/// 3Dモデルの描写(モデルID、座標、α値)
	/// </summary>
	/// <param name="id">モデルID</param>
	/// <param name="position">座標</param>
	/// <param name="alpha">α値</param>
	void Draw(const MODEL_ID& id, const Vector3& position, float alpha);
	/// <summary>
	/// 3Dモデルの描写(モデルID、座標、回転量)
	/// </summary>
	/// <param name="id">モデルID</param>
	/// <param name="position">座標</param>
	/// <param name="rotate">回転量</param>
	void Draw(const MODEL_ID& id, const Vector3& position, const Vector3& rotate);
	/// <summary>
	/// 3Dモデルの描写(モデルID、座標、α値、回転量)
	/// </summary>
	/// <param name="id">モデルID</param>
	/// <param name="position">座標</param>
	/// <param name="alpha">α値</param>
	/// <param name="rotate">回転量</param>
	void Draw(const MODEL_ID& id, const Vector3& position, float alpha, const Vector3& rotate);
	/// <summary>
	/// 3Dモデルの描写(モデルID、座標、回転量、拡大量)
	/// </summary>
	/// <param name="id">モデルID</param>
	/// <param name="position">座標</param>
	/// <param name="rotate">回転量</param>
	/// <param name="scale">拡大量</param>
	void Draw(const MODEL_ID& id, const Vector3& position, const Vector3& rotate, const Vector3& scale);
	/// <summary>
	/// 3Dモデルの描写(モデルID、座標、α値、回転量、拡大量)
	/// </summary>
	/// <param name="id">モデルID</param>
	/// <param name="position">座標</param>
	/// <param name="alpha">α値</param>
	/// <param name="rotate">回転量</param>
	/// <param name="scale">拡大量</param>
	void Draw(const MODEL_ID& id, const Vector3& position, float alpha, const Vector3& rotate, const Vector3& scale);
	/// <summary>
	///  3Dモデルの描写(モデルID、座標、α値、回転量、拡大量、ディフューズカラー)
	/// </summary>
	/// <param name="id">モデルID</param>
	/// <param name="position">座標</param>
	/// <param name="alpha">α値</param>
	/// <param name="rotate">回転量</param>
	/// <param name="scale">拡大率</param>
	/// <param name="diffusecolor">ディフェーズカラー</param>
	void Draw(const MODEL_ID& id, const Vector3& position, float alpha, const Vector3& rotate, const Vector3& scale, const Vector4& diffusecolor);
	/// <summary>
	/// 3Dモデルの描写(モデルID、マトリクス)
	/// </summary>
	/// <param name="id">モデルID</param>
	/// <param name="mat">マトリクス</param>
	void Draw(const MODEL_ID& id, const Matrix4& mat);
	/// <summary>
	/// 3Dモデルの描写(モデルID、マトリクス、α値)
	/// </summary>
	/// <param name="id">モデルID</param>
	/// <param name="mat">マトリクス</param>
	/// <param name="alpha">α値</param>
	void Draw(const MODEL_ID& id, const Matrix4& mat, float alpha);
	/// <summary>
	/// 3Dモデルの描写(モデルID、マトリクス、ディフューズカラー)
	/// </summary>
	/// <param name="id">モデルID</param>
	/// <param name="mat">マトリクス</param>
	/// <param name="diffusecolor">ディフェーズカラー</param>
	void Draw(const MODEL_ID& id, const Matrix4& mat, const Vector4& diffusecolor);
	/// <summary>
	/// 3Dモデルの描写(モデルID、マトリクス、α値、ディフューズカラー)
	/// </summary>
	/// <param name="id">モデルID</param>
	/// <param name="mat">マトリクス</param>
	/// <param name="alpha">α値</param>
	/// <param name="diffusecolor">ディフェーズカラー</param>
	void Draw(const MODEL_ID& id, const Matrix4& mat, float alpha, const Vector4& diffusecolor);

	/// <summary>
	/// ビルボード描写をする
	/// </summary>
	void DrawBillboard(const SPRITE_ID& id, const Vector3& position);


	//モデルのハンドル情報
	class ModelHandle {
	public:
		ModelHandle();
		~ModelHandle();
	public:
		/// <summary>
		/// ハンドルを取得
		/// </summary>
		int GetHandle();
		/// <summary>
		/// モデルを読み込む
		/// </summary>
		/// <param name="fileName">ファイル名</param>
		void Load(const std::string fileName);
		/// <summary>
		/// 削除
		/// </summary>
		void Delete();
		/// <summary>
		/// モデルのあたり判定を使う場合呼ぶ
		/// </summary>
		void CollisionInitialize();
		/// <summary>
		/// モデルのあたり判定を更新
		/// </summary>
		void CollisionUpdate();

	private:
		//モデルハンドル
		int handle;
	};

private:
	//スマートポインター
	using HandlePtr = std::shared_ptr<ModelHandle>;
	//モデルハンドル情報
	std::unordered_map<MODEL_ID, HandlePtr> mModels;



public:
	/// <summary>
	/// IDからモデルハンドルを取得
	/// </summary>
	HandlePtr GetModelHandle(const MODEL_ID& id);

};