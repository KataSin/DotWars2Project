#pragma once
#include <DxLib.h>
#include <string>
#include <vector>
#include <unordered_map>
//グラフィックID
#include "../GraphicID.h"
//Math関係
#include "../../Math/Vector2.h"
#include "../../Math/Vector4.h"

class SpriteAnim {

private:
	//アニメーション情報
	struct AnimState
	{
		//画像ハンドル
		std::vector<int>handles;
		//アニメーションフレーム番号
		int frame = 0;
		//アニメーションタイム
		float time = 0.0f;
		//アニメーションスピード
		float animSpeed = 1.0f;
		//アニメーション再生されているか？
		bool isPlayAnim = false;
		//アニメーションをループするか？
		bool isLoopAnim = false;
	};
private:
	SpriteAnim() = default;
	~SpriteAnim();
public:
	/// <summary>
	/// インスタンスを取得する
	/// </summary>
	/// <returns>スプライトアニメーションインスタンス</returns>
	static SpriteAnim &GetInstance() {
		static SpriteAnim sa;
		return sa;
	}
public:
	/// <summary>
	/// 2Dアニメーションスプライトを読み込む(ファイル名、スプライトアニメーションID、すべての画像の分割数、縦と横の分割数、一つの画像の大きさ)
	/// </summary>
	/// <param name="fileName">ファイル名</param>
	/// <param name="id">スプライトアニメーションID</param>
	/// <param name="allNum">全ての画像の分割数</param>
	/// <param name="num">縦と横の分割数</param>
	/// <param name="size">一つの画像の大きさ</param>
	void Load(const std::string& fileName, const SPRITE_ANIM_ID& id, int allNum, const Vector2& num, const Vector2& size);
	/// <summary>
	/// 指定したアニメーションスプライトを削除する
	/// </summary>
	/// <param name="id">スプライトアニメーションID</param>
	void Delete(const SPRITE_ANIM_ID& id);
	/// <summary>
	/// 指定したアニメーションの再生(アニメーションスプライトID、アニメーションスピード、ループさせるか、最初から再生させるか)
	/// </summary>
	/// <param name="id">アニメーションスプライトID</param>
	/// <param name="speed">アニメーション再生スピード</param>
	/// <param name="first">最初から再生させるか(true:アニメーションの最初から false:前回ストップしたところから)</param>
	void Start(const SPRITE_ANIM_ID& id, float speed, bool loop, bool first);
	/// <summary>
	/// 指定したアニメーションをストップ(アニメーションスプライトID)
	/// </summary>
	/// <param name="id">スプライトアニメーションID</param>
	void Stop(const SPRITE_ANIM_ID& id);
	/// <summary>
	/// アニメーションを表示させる
	/// </summary>
	/// <param name="id">アニメーションスプライトID</param>
	/// <param name="position">表示座標</param>
	/// <param name="alpha">α値</param>
	/// <param name="angle">回転量</param>
	/// <param name="scale">拡大量</param>
	/// <param name="color">カラー</param>
	void Draw(const SPRITE_ANIM_ID& id, const Vector2& position, float alpha, float angle, const Vector2& scale = Vector2::One, const Vector4& color = Vector4(255, 255, 255, 255));
	/// <summary>
	/// アニメーションアップデート
	/// </summary>
	void Update();
	/// <summary>
	/// 再生するフレームを設定
	/// </summary>
	/// <param name="id">アニメーションスプライトID</param>
	/// <param name="frame">フレーム数</param>
	void SetFrame(const SPRITE_ANIM_ID& id,int frame);

private:
	//アニメーション情報
	std::unordered_map<SPRITE_ANIM_ID, AnimState> mAnimSprites;
};