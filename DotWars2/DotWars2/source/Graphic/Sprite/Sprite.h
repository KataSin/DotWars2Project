//--------------------------------//
//-----スプライト描写クラス-------//
//---------作成:片岡辰悟----------//
//--------------------------------//
#pragma once

#include <unordered_map>
#include <string>
//Math系
#include "../../Math/Math.h"
#include "../../Math/Vector2.h"
#include "../../Math/Vector4.h"
//ID
#include "../GraphicID.h"


class Sprite
{
private:
	Sprite() = default;
	~Sprite();
public:
	static Sprite &GetInstance() {
		static Sprite s;
		return s;
	}

	/// <summary>
	/// 画像をロードする(ファイル名、スプライトID)
	/// </summary>
	/// <param name="fileName">ファイル名</param>
	/// <param name="id">スプライトID</param>
	void Load(const std::string& fileName, const SPRITE_ID& id);

	/// <summary>
	/// 指定した画像を削除する(スプライトID)
	/// </summary>
	/// <param name="id">スプライトID</param>
	void Delete(const SPRITE_ID& id);
	/// <summary>
	/// 全ての読み込んだ画像を削除する
	/// </summary>
	void AllDelete();
	/// <summary>
	/// 画像を表示する(スプライトID、座標)
	/// </summary>
	/// <param name="id">スプライトID</param>
	/// <param name="position">座標</param>
	void Draw(const SPRITE_ID& id, const Vector2& position);
	/// <summary>
	/// 画像を表示する(スプライトID、座標、α値)
	/// </summary>
	/// <param name="id">スプライトID</param>
	/// <param name="position">座標</param>
	/// <param name="alpha">α値</param>
	void Draw(const SPRITE_ID& id, const Vector2& position, float alpha);
	/// <summary>
	/// 画像を表示する(スプライトID、座標、α値、拡大量、原点)
	/// </summary>
	/// <param name="id">スプライトID</param>
	/// <param name="position">座標</param>
	/// <param name="alpha">α値</param>
	/// <param name="scale">拡大量</param>
	/// <param name="origin">原点</param>
	void Draw(const SPRITE_ID& id, const Vector2& position, float alpha, const Vector2& scale, const Vector2& origin = Vector2::Zero);
	/// <summary>
	/// 画像を表示する(スプライトID、座標、α値、拡大量、カラー、原点)
	/// </summary>
	/// <param name="id">スプライトID</param>
	/// <param name="position">座標</param>
	/// <param name="alpha">α値</param>
	/// <param name="scale">拡大量</param>
	/// <param name="color">カラー</param>
	/// <param name="origin">原点</param>
	void Draw(const SPRITE_ID& id, const Vector2& position, float alpha, const Vector2& scale, const Vector4& color, const Vector2& origin = Vector2::Zero);

	/// <summary>
	/// 画像を表示する(スプライトID、座標、α値、回転量(度数法)、原点)
	/// </summary>
	/// <param name="id">スプライトID</param>
	/// <param name="position">座標</param>
	/// <param name="alpha">α値</param>
	/// <param name="angle">回転量(度数法)</param>
	/// <param name="origin">原点</param>
	void Draw(const SPRITE_ID& id, const Vector2& position, float alpha, float angle, const Vector2& origin = Vector2::Zero);
	/// <summary>
	/// 画像を表示する(スプライトID、座標、α値、回転量(度数法)、カラー、原点)
	/// </summary>
	/// <param name="id">スプライトID</param>
	/// <param name="position">座標</param>
	/// <param name="alpha">α値</param>
	/// <param name="angle">回転量(度数法)</param>
	/// <param name="color">カラー</param>
	/// <param name="origin">原点</param>
	void Draw(const SPRITE_ID& id, const Vector2& position, float alpha, float angle, const Vector4& color, const Vector2& origin = Vector2::Zero);

	/// <summary>
	/// 画像を表示する(スプライトID、座標、α値、スケール、原点)
	/// </summary>
	/// <param name="id">スプライトID</param>
	/// <param name="position">座標</param>
	/// <param name="alpha">α値</param>
	/// <param name="angle">回転量</param>
	/// <param name="scale">拡大量</param>
	/// <param name="origin">原点</param>
	void Draw(const SPRITE_ID& id, const Vector2& position, float alpha, float angle, const Vector2& scale, const Vector2& origin = Vector2::Zero);


	/// <summary>
	/// 円グラフ的なゲージを表示する(スプライトID、座標、α値、カラー、ゲージカウント(0～100))
	/// </summary>
	/// <param name="id">スプライトID</param>
	/// <param name="position">座標</param>
	/// <param name="alpha">α値</param>
	/// <param name="color">カラー</param>
	/// <param name="gaugeCount">ゲージカウント(0～100)</param>
	void DrawGaugeCircle(const SPRITE_ID & id, const Vector2 & position, float alpha, const Vector4 & color, float gaugeCount);

	/// <summary>
	/// ゲージを表示する(下から上へ)
	/// </summary>
	/// <param name="id">スプライトID</param>
	/// <param name="position">座標</param>
	/// <param name="color">カラー</param>
	/// <param name="scale">拡大量</param>
	/// <param name="alpha">α値</param>
	/// <param name="gaugeCount">ゲージカウント(0～100)</param>
	void DrawGauge(const SPRITE_ID & id, const Vector2 & position, const Vector4& color, Vector2 & scale, float alpha, float gaugeCount);

	/// <summary>
	/// スプライトの中心座標を取得する(スプライトID)
	/// </summary>
	/// <param name="id">スプライトID</param>
	/// <returns>スプライトの中心座標</returns>
	Vector2 GetSpriteCenter(const SPRITE_ID& id);

	/// <summary>
	/// スプライトのサイズを取得
	/// </summary>
	/// <param name="id">スプライトID</param>
	/// <returns>スプライトのサイズ</returns>
	Vector2 GetSpriteSize(const SPRITE_ID& id);

	/// <summary>
	/// スプライトのハンドルを取得
	/// </summary>
	/// <param name="id">スプライトID</param>
	/// <returns>スプライトハンドル</returns>
	int GetSpriteHandle(const SPRITE_ID& id);

	private:
		/// <summary>
		/// αブレンドにする
		/// </summary>
		/// <param name="alpha">α値</param>
		void AlphaBlend(float alpha);
		/// <summary>
		/// 最初の状態に戻す
		/// </summary>
		void DefaultSprite();
		/// <summary>
		/// カラーを設定
		/// </summary>
		/// <param name="color">カラー</param>
		void SetColor(const Vector4& color);

private:
	//画像たち
	std::unordered_map<SPRITE_ID, int> mSprites;
};
