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
	Attach(motionId);
}

void ModelAnim::ModelAnimHandle::Delete()
{
	//モデル削除
	MV1DeleteModel(handle);
	mAttachNums.clear();
}

void ModelAnim::ModelAnimHandle::Attach(const MODEL_MOTION_ID & motionId)
{
	if (mAttachNums.count(motionId) > 0)return;
	//アタッチされたインデックス番号
	mAttachNums[motionId].index = MV1AttachAnim(handle, motionId);
	//アニメーション総時間
	mAttachNums[motionId].animAllTime = MV1GetAttachAnimTotalTime(handle, mAttachNums[motionId].index);
	//アニメーション時間
	mAttachNums[motionId].animTime = 0.0f;
	//ブレンド率
	mAttachNums[motionId].blendNum = 0.0f;
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
	if (motionId == CurMotionId||isLerpAnim)return;

	//現在の再生アニメーションを変更
	CurMotionId = motionId;
	Attach(motionId);
	lerpAnimTime = 0.0f;
	isLerpAnim = true;

}

void ModelAnim::ModelAnimHandle::Update()
{

	if (PreMotionId != CurMotionId) {

		mAttachNums[CurMotionId].blendNum += 20.0f* Time::GetInstance().DeltaTime();
		mAttachNums[PreMotionId].blendNum -= 20.0f* Time::GetInstance().DeltaTime();
		//ブレンド率設定
		MV1SetAttachAnimBlendRate(handle, mAttachNums[CurMotionId].index, mAttachNums[CurMotionId].blendNum);
		MV1SetAttachAnimBlendRate(handle, mAttachNums[PreMotionId].index, mAttachNums[PreMotionId].blendNum);
		//クランプ
		mAttachNums[CurMotionId].blendNum = Math::Clamp(mAttachNums[CurMotionId].blendNum, 0.0f, 1.0f);
		mAttachNums[PreMotionId].blendNum = Math::Clamp(mAttachNums[PreMotionId].blendNum, 0.0f, 1.0f);

		if (mAttachNums[CurMotionId].blendNum >= 1.0f) {
          	Detach(PreMotionId);
			PreMotionId = CurMotionId;
			isLerpAnim = false;
		}
	}

	mAttachNums[CurMotionId].animTime += 20.0f*Time::GetInstance().DeltaTime();
	if (mAttachNums[CurMotionId].animAllTime <= mAttachNums[CurMotionId].animTime)mAttachNums[CurMotionId].animTime = 0.0f;
	SetAnimTime(CurMotionId, mAttachNums[CurMotionId].animTime);
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
