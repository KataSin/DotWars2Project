#include "SpriteAnim.h"

#include "../../Time/Time.h"
SpriteAnim::~SpriteAnim()
{
}

void SpriteAnim::Load(const std::string & fileName, const SPRITE_ANIM_ID & id, int allNum, const Vector2 & num, const Vector2 & size)
{
	AnimState state;
	state.frame = 0;
	state.isPlayAnim = false;
	state.time = 0.0f;

	int handles[256];
	std::vector<int> handlesVector;
	LoadDivGraph(fileName.c_str(), allNum, (int)num.x, (int)num.y, (int)size.x, (int)size.y, handles);
	for (int i = 0; i <= allNum; i++) {
		handlesVector.push_back(handles[i]);
	}
	state.handles = handlesVector;
	mAnimSprites[id] = state;
}

void SpriteAnim::Delete(const SPRITE_ANIM_ID & id)
{
	mAnimSprites[id].handles.clear();
	mAnimSprites.erase(id);
}

void SpriteAnim::Start(const SPRITE_ANIM_ID & id, float speed, bool loop, bool first)
{
	//再生中なら呼ばれない（スピードだけ変えたい場合はちょっと変える）
	if (mAnimSprites[id].isPlayAnim)return;
	mAnimSprites[id].isPlayAnim = true;
	mAnimSprites[id].isLoopAnim = loop;
	mAnimSprites[id].animSpeed = speed;
	mAnimSprites[id].time = 0.0f;
	if (first) mAnimSprites[id].frame = 0;
}

void SpriteAnim::Stop(const SPRITE_ANIM_ID & id)
{
	mAnimSprites[id].isPlayAnim = false;
}

void SpriteAnim::Draw(const SPRITE_ANIM_ID & id, const Vector2 & position, float alpha, float angle, const Vector2 & scale, const Vector4 & color)
{
	DrawGraph((float)position.x, (float)position.y, mAnimSprites[id].handles[mAnimSprites[id].frame], TRUE);
}

void SpriteAnim::Update()
{
	for (auto& i : mAnimSprites)
	{
		AnimState& state = i.second;
		if (!state.isPlayAnim) {
			state.time = 0.0f;
			continue;
		}
		state.time += state.animSpeed*Time::GetInstance().DeltaTime();
		if (state.time >= 1.0f) {
			if (state.handles.size() - 1 > state.frame) {
				state.frame++;
				state.time = 0.0f;
			}
			else
			{
				state.frame = 0;
			}
		}
	}
}

void SpriteAnim::SetFrame(const SPRITE_ANIM_ID& id, int frame)
{
	mAnimSprites[id].frame = frame;
}
