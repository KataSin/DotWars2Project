#include "ModelAnim.h"
#include "../../Time/Time.h"
#include "../../Math/Math.h"
ModelAnim::ModelAnimHandle::ModelAnimHandle() :
	handle(-1),
	animAllTime(0.0f),
	isPlay(false),
	isLerpAnim(false),
	CurMotionId(MODEL_MOTION_ID::NULL_MOTION),
	PreMotionId(MODEL_MOTION_ID::NULL_MOTION)
{
}

ModelAnim::ModelAnimHandle::~ModelAnimHandle()
{
}

int ModelAnim::ModelAnimHandle::GetHandle()
{
	return handle;
}

void ModelAnim::ModelAnimHandle::Load(const std::string fileName, const MODEL_MOTION_ID& motionId)
{
	handle = MV1LoadModel(fileName.c_str());
	CurMotionId = motionId;
	PreMotionId = motionId;
}

void ModelAnim::ModelAnimHandle::Delete()
{
	//ƒ‚ƒfƒ‹íœ
	MV1DeleteModel(handle);
	mAttachNums.clear();
}

void ModelAnim::ModelAnimHandle::Attach(const MODEL_MOTION_ID & motionId)
{
	mAttachNums[motionId].index = MV1AttachAnim(handle, motionId);
	mAttachNums[motionId].animAllTime = MV1GetAttachAnimTotalTime(handle, motionId);
	mAttachNums[motionId].animTime = 0.0f;
}

void ModelAnim::ModelAnimHandle::Detach(const MODEL_MOTION_ID & motionId)
{
	MV1DetachAnim(handle, mAttachNums[motionId].index);
	mAttachNums.erase(motionId);
}

int ModelAnim::ModelAnimHandle::GetAttachIndex(const MODEL_MOTION_ID & motionId)
{
	return mAttachNums[motionId].index;
}

float ModelAnim::ModelAnimHandle::GetAllAnimTime(const MODEL_MOTION_ID& motionId)
{
	return animAllTime;
}

void ModelAnim::ModelAnimHandle::SetAnimTime(const MODEL_MOTION_ID& motionId, float time)
{
	MV1SetAttachAnimTime(handle, mAttachNums[motionId].index, time);
}

void ModelAnim::ModelAnimHandle::StartAnim()
{
	isPlay = true;
}

void ModelAnim::ModelAnimHandle::StopAnim()
{
	isPlay = false;
}

void ModelAnim::ModelAnimHandle::ChangeAnim(const MODEL_MOTION_ID & motionId)
{
	if (isLerpAnim)return;
	isLerpAnim = true;
	Attach(motionId);
	CurMotionId = motionId;
}

void ModelAnim::ModelAnimHandle::Update()
{
	if (!isPlay)return;
	for (auto & i = mAttachNums.begin(); i != mAttachNums.end(); ++i) {
		i->second.animTime += 20.0f*Time::GetInstance().DeltaTime();
		if (i->second.animTime > i->second.animAllTime) i->second.animTime = 0.0f;
		SetAnimTime(i->first, i->second.animTime);
	}

	if (CurMotionId != PreMotionId) {
		lerpAnimTime += Time::GetInstance().DeltaTime();
		lerpAnimTime = Math::Clamp(lerpAnimTime, 0.0f, 1.0f);
		MV1SetAttachAnimBlendRate(handle, PreMotionId, 1.0f - lerpAnimTime);
		MV1SetAttachAnimBlendRate(handle, CurMotionId, lerpAnimTime);

		if (lerpAnimTime >= 1.0f) {
			Detach(PreMotionId);
			PreMotionId = CurMotionId;
			lerpAnimTime = 0.0f;
			isLerpAnim = false;
		}
	}
}






void ModelAnim::Load(const std::string & name, const MODEL_ANIM_ID & id, const MODEL_MOTION_ID& motionId)
{
	HandlePtr handle = std::make_shared<ModelAnimHandle>();
	handle->Load(name, motionId);
	mModels[id] = handle;
}

void ModelAnim::Delete(const MODEL_ANIM_ID & id)
{
	mModels[id]->Delete();
	mModels.erase(id);
}

void ModelAnim::AttachAnim(const MODEL_ANIM_ID & id, const MODEL_MOTION_ID & motionID)
{
	mModels[id]->Attach(motionID);
}

void ModelAnim::DetachAnim(const MODEL_ANIM_ID & id, const MODEL_MOTION_ID & motionID)
{
	mModels[id]->Detach(motionID);
}

void ModelAnim::ChangeAnim(const MODEL_ANIM_ID & id, const MODEL_MOTION_ID & motionId)
{
	mModels[id]->ChangeAnim(motionId);
}

void ModelAnim::StartAnim(const MODEL_ANIM_ID & id)
{
	mModels[id]->StartAnim();
}

void ModelAnim::StopAnim(const MODEL_ANIM_ID & id)
{
	mModels[id]->StopAnim();
}

void ModelAnim::Update()
{
	for (auto & i = mModels.begin(); i != mModels.end(); ++i) {
		i->second->Update();
	}
}

void ModelAnim::Draw(const MODEL_ANIM_ID & id, const Matrix4 & mat, float alpha, const Vector4 & diffuse)
{
	int handle = mModels[id]->GetHandle();
	MV1SetMatrix(handle, mat.ToMATRIX());
	MV1SetOpacityRate(handle, alpha);
	MV1SetDifColorScale(handle, GetColorF(diffuse.x, diffuse.y, diffuse.z, diffuse.w));
	MV1DrawModel(handle);
}
