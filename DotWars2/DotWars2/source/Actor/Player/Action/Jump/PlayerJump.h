#pragma once

#include "../Action.h"



class PlayerJump :public Action
{
public:
	PlayerJump(Actor* actor, IWorld & world, IActionManager& actionManager, Parameter& parameter);
	virtual ~PlayerJump() override;

	virtual void Start() override;

	virtual void Update() override;

	virtual void End() override;

	virtual void Collision(Actor& other, const CollisionParameter& parameter);

private:
	//プレイヤー
	ActorPtr mPlayerActor;
	Vector3 mPosition;
	Vector3 mMoveVec;
	//ジャンプの速度
	Vector3 mJumpVelo;
	//カメラ
	ActorPtr mCameraActor;

	//床との当たり判定用の時間
	float mColTime;
	
};