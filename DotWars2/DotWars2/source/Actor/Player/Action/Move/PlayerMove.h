#pragma once

#include "../Action.h"
class PlayerMove :public Action
{
public:
	PlayerMove(Actor* actor, IWorld & world, IActionManager& actionManager, Parameter& parameter);
	virtual ~PlayerMove() override;

	virtual void Start() override;

	virtual void Update() override;

	virtual void End() override;

	virtual void Collision(Actor& other, const CollisionParameter& parameter) override;

private:
	//プレイヤーアクター
	ActorPtr mPlayerActor;

	ActorPtr mCameraActor;
	//座標
	Vector3 mPosition;
	//動いているベクトル
	Vector3 mMovemVec;
};