#include "Camera.h"
#include <DxLib.h>
#include "../Math/Math.h"
Camera::~Camera()
{
}
void Camera::SetTarget(const Vector3 & target)
{
	mTarget = target;
}

void Camera::SetPosition(const Vector3 & position)
{
	mPosition = position;
}

void Camera::SetCameraVec(const Vector3 & vec)
{
	mCameraVec = vec;
}

void Camera::Update()
{
	SetCameraPositionAndTargetAndUpVec(mPosition.ToVECTOR(), mTarget.ToVECTOR(), mCameraVec.ToVECTOR());
}

void Camera::SetRange(float Near, float Far)
{
	SetCameraNearFar(Near, Far);
}

void Camera::SetView(float angle)
{
	SetupCamera_Perspective(Math::Radian(angle));
}
