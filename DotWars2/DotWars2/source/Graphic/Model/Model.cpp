#include "Model.h"

#define PI 3.14159265358979f
Model::ModelHandle::ModelHandle():
	handle(-1)
{
}

Model::ModelHandle::~ModelHandle()
{
}

int Model::ModelHandle::GetHandle()
{
	return handle;
}

void Model::ModelHandle::Load(const std::string fileName)
{
	//ファイルを削除
	handle = MV1LoadModel(fileName.c_str());
}

void Model::ModelHandle::Delete()
{
	//モデル削除
	MV1DeleteModel(handle);
}

void Model::ModelHandle::CollisionInitialize()
{
	//あたり判定を設定
	MV1SetupCollInfo(handle, 0);
}

void Model::ModelHandle::CollisionUpdate()
{
	//あたり判定アップデート
	MV1RefreshCollInfo(handle, 0);
}














Model::~Model()
{
}

void Model::Load(const std::string & name, const MODEL_ID & id)
{
	HandlePtr handle = std::make_shared<ModelHandle>();
	handle->Load(name);
	mModels[id]=handle;
}

void Model::LoadCollision(const std::string & name, const MODEL_ID & id)
{
	HandlePtr handle = std::make_shared<ModelHandle>();
	handle->Load(name);
	handle->CollisionInitialize();
	mModels[id] = handle;
}

void Model::Delete(const MODEL_ID & id)
{
	mModels[id]->Delete();
	mModels.erase(id);
}


void Model::Draw(const MODEL_ID & id, const Vector3 & position)
{
	int handle = mModels[id]->GetHandle();
	MV1SetPosition(handle, position.ToVECTOR());
	MV1DrawModel(handle);
}

void Model::Draw(const MODEL_ID & id, const Vector3 & position, float alpha)
{
	int handle = mModels[id]->GetHandle();
	MV1SetPosition(handle, position.ToVECTOR());
	MV1SetOpacityRate(handle, alpha);
	MV1DrawModel(handle);
}

void Model::Draw(const MODEL_ID & id, const Vector3 & position, const Vector3 & rotate)
{
	int handle = mModels[id]->GetHandle();
	MV1SetPosition(handle, position.ToVECTOR());
	MV1SetRotationXYZ(handle, rotate.ToVECTOR());
	MV1DrawModel(handle);
}

void Model::Draw(const MODEL_ID & id, const Vector3 & position, float alpha, const Vector3 & rotate)
{
	Vector3 rad = rotate * PI / 180.0f;
	int handle = mModels[id]->GetHandle();
	MV1SetPosition(handle, position.ToVECTOR());
	MV1SetOpacityRate(handle, alpha);
	MV1SetRotationXYZ(handle, rad.ToVECTOR());
	MV1DrawModel(handle);
}

void Model::Draw(const MODEL_ID & id, const Vector3 & position, const Vector3 & rotate, const Vector3 & scale)
{
	Vector3 rad = rotate * PI / 180.0f;
	int handle = mModels[id]->GetHandle();
	MV1SetPosition(handle, position.ToVECTOR());
	MV1SetRotationXYZ(handle, rad.ToVECTOR());
	MV1SetScale(handle, scale.ToVECTOR());
	MV1DrawModel(handle);
}

void Model::Draw(const MODEL_ID & id, const Vector3 & position, float alpha, const Vector3 & rotate, const Vector3 & scale)
{
	Vector3 rad = rotate * PI / 180.0f;
	int handle = mModels[id]->GetHandle();
	MV1SetPosition(handle, position.ToVECTOR());
	MV1SetRotationXYZ(handle, rad.ToVECTOR());
	MV1SetScale(handle, scale.ToVECTOR());
	MV1SetOpacityRate(handle, alpha);
	MV1DrawModel(handle);
}

void Model::Draw(const MODEL_ID & id, const Vector3 & position, float alpha, const Vector3 & rotate, const Vector3 & scale, const Vector4 & diffusecolor)
{
	Vector3 rad = rotate * PI / 180.0f;
	int handle = mModels[id]->GetHandle();
	MV1SetPosition(handle, position.ToVECTOR());
	MV1SetRotationXYZ(handle, rad.ToVECTOR());
	MV1SetScale(handle, scale.ToVECTOR());
	MV1SetOpacityRate(handle, alpha);
	MV1SetDifColorScale(handle, GetColorF(diffusecolor.x, diffusecolor.y, diffusecolor.z, diffusecolor.w));
	MV1DrawModel(handle);
}

void Model::Draw(const MODEL_ID & id, const Matrix4 & mat)
{
	int handle = mModels[id]->GetHandle();
	MV1SetMatrix(handle, mat.ToMATRIX());
	MV1DrawModel(handle);
}

void Model::Draw(const MODEL_ID & id, const Matrix4 & mat, float alpha)
{
	int handle = mModels[id]->GetHandle();
	MV1SetMatrix(handle, mat.ToMATRIX());
	MV1SetOpacityRate(handle, alpha);
	MV1DrawModel(handle);
}

void Model::Draw(const MODEL_ID & id, const Matrix4 & mat, const Vector4 & diffusecolor)
{
	int handle = mModels[id]->GetHandle();
	MV1SetMatrix(handle, mat.ToMATRIX());
	MV1SetDifColorScale(handle, GetColorF(diffusecolor.x, diffusecolor.y, diffusecolor.z, diffusecolor.w));
	MV1DrawModel(handle);
}

void Model::Draw(const MODEL_ID & id, const Matrix4 & mat, float alpha, const Vector4 & diffusecolor)
{
	int handle = mModels[id]->GetHandle();
	MV1SetMatrix(handle, mat.ToMATRIX());
	MV1SetOpacityRate(handle, alpha);
	MV1SetDifColorScale(handle, GetColorF(diffusecolor.x, diffusecolor.y, diffusecolor.z, diffusecolor.w));

	MV1DrawModel(handle);
}

void Model::DrawBillboard(const SPRITE_ID & id, const Vector3 & position)
{
}

Model::HandlePtr Model::GetModelHandle(const MODEL_ID & id)
{
	return mModels[id];
}
