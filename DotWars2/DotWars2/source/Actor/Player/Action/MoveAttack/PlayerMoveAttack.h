#pragma once

#include "../Action.h"
class PlayerMoveAttack :public Action
{
public:
	PlayerMoveAttack(Actor* actor, IWorld & world, IActionManager& actionManager, Parameter& parameter);
	
	virtual ~PlayerMoveAttack() override;

	virtual void Start() override;

	virtual void Update() override;

	virtual void End() override;

	virtual void Collision(Actor& other, const CollisionParameter& parameter) override;

private:
	//カメラアクター
	ActorPtr mCameraActor;
	//座標
	Vector3 mPosition;
	//プレイヤーアクター
	ActorPtr mPlayerActor;
	//頂点
	ActorPtr mVertexPos;
	//攻撃間隔タイム
	float mAttackTime;
};