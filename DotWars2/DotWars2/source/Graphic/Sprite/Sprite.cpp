#include "Sprite.h"

Sprite::~Sprite()
{
}

void Sprite::Load(const std::string & fileName, const SPRITE_ID & id)
{
	mSprites[id] = LoadGraph(fileName.c_str());
}

void Sprite::Delete(const SPRITE_ID & id)
{
	DeleteGraph(mSprites[id]);
	mSprites.erase(id);
}

void Sprite::AllDelete()
{
	InitGraph();
	mSprites.clear();
}

void Sprite::Draw(const SPRITE_ID & id, const Vector2 & position)
{
	DrawGraph(position.x, position.y, mSprites[id], TRUE);
}

void Sprite::Draw(const SPRITE_ID & id, const Vector2 & position, float alpha)
{
	AlphaBlend(alpha);
	DrawGraph(position.x, position.y, mSprites[id], TRUE);
	DefaultSprite();
}

void Sprite::Draw(const SPRITE_ID & id, const Vector2 & position, float alpha, const Vector2 & scale, const Vector2 & origin)
{
	AlphaBlend(alpha);
	DrawRotaGraph3F(position.x, position.y, origin.x, origin.y, (double)scale.x, (double)scale.y, (double)0.0f, mSprites[id], TRUE, FALSE);
	DefaultSprite();
}

void Sprite::Draw(const SPRITE_ID & id, const Vector2 & position, float alpha, const Vector2 & scale, const Vector4 & color, const Vector2 & origin)
{
	AlphaBlend(alpha);
	SetColor(color);
	DrawRotaGraph3F(position.x, position.y, origin.x, origin.y, (double)scale.x, (double)scale.y, (double)0.0f, mSprites[id], TRUE, FALSE);
	DefaultSprite();
}

void Sprite::Draw(const SPRITE_ID & id, const Vector2 & position, float alpha, float angle, const Vector2 & origin)
{
	AlphaBlend(alpha);
	DrawRotaGraph3F(position.x, position.y, origin.x, origin.y, (double)1.0f, (double)1.0f, (double)angle, mSprites[id], TRUE, FALSE);
	DefaultSprite();
}

void Sprite::Draw(const SPRITE_ID & id, const Vector2 & position, float alpha, float angle, const Vector4 & color, const Vector2 & origin)
{
	AlphaBlend(alpha);
	SetColor(color);
	DrawRotaGraph3F(position.x, position.y, origin.x, origin.y, (double)1.0f, (double)1.0f, (double)angle, mSprites[id], TRUE, FALSE);
	DefaultSprite();
}

void Sprite::Draw(const SPRITE_ID & id, const Vector2 & position, float alpha, float angle, const Vector2 & scale, const Vector2 & origin)
{
	AlphaBlend(alpha);
	DrawRotaGraph3F(position.x, position.y, origin.x, origin.y, (double)scale.x, (double)scale.y, (double)angle, mSprites[id], TRUE, FALSE);
	DefaultSprite();
}

void Sprite::DrawGaugeCircle(const SPRITE_ID & id, const Vector2 & position, float alpha, const Vector4 & color, float gaugeCount)
{
	SetColor(color);
	Vector2 texSize = GetSpriteSize(id);
	float overCount = (float)texSize.y / 100.0f*gaugeCount;
	AlphaBlend(alpha);
	DrawRectGraphF(position.x, position.y + overCount, 0, 0, texSize.x, texSize.y - overCount, mSprites[id], true, true);
	DefaultSprite();
}

void Sprite::DrawGauge(const SPRITE_ID & id, const Vector2 & position, const Vector4 & color, Vector2 & scale, float alpha, float gaugeCount)
{
	SetColor(color);
	Vector2 texSize=GetSpriteSize(id);
	DrawCircleGauge(position.x + texSize.x / 2.0f, position.y + texSize.y / 2.0f, gaugeCount, mSprites[id]);
	DefaultSprite();
}

Vector2 Sprite::GetSpriteCenter(const SPRITE_ID & id)
{
	return GetSpriteSize(id) / 2.0f;
}

Vector2 Sprite::GetSpriteSize(const SPRITE_ID & id)
{
	int sizeX, sizeY;
	GetGraphSize(mSprites[id], &sizeX, &sizeY);
	return Vector2(sizeX, sizeY);
}

int Sprite::GetSpriteHandle(const SPRITE_ID & id)
{
	return mSprites[id];
}

void Sprite::AlphaBlend(float alpha)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(255.0f * alpha));
}

void Sprite::DefaultSprite()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	SetDrawBright(255, 255, 255);
}

void Sprite::SetColor(const Vector4 & color)
{
	SetDrawBright(color.x, color.y, color.z);
}
