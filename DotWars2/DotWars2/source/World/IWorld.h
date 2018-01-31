#pragma once
#include "../IncludePtr.h"
#include "WorldID.h"
#include "../Actor/CollisionActor/Collision/Collision.h"
#include "../Actor/ActorID.h"
#include <list>
class IWorld {
public:
	virtual ~IWorld() {}
	/// <summary>
	/// ���[���h�ɃA�N�^�[��ǉ�����
	/// </summary>
	/// <param name="id">���[���hID</param>
	/// <param name="actor">�A�N�^�[</param>
	virtual void Add(const ACTOR_ID& id, ActorPtr actor) = 0;
	/// <summary>
	/// �����蔻�������
	/// </summary>
	/// <param name="id">���Ă����A�N�^�[ID</param>
	/// <param name="colId">�R���W�����̎��</param>
	/// <param name="actor">���g�̃A�N�^�[</param>
	virtual void Collision(const ACTOR_ID& id, const COL_ID& colId, Actor& actor) = 0;
	/// <summary>
	/// �w�肵���A�N�^�[������T��
	/// </summary>
	virtual std::list<ActorPtr> FindActors(const ACTOR_ID& id) = 0;
	/// <summary>
	/// �w�肵�����[���h���擾����
	/// </summary>
	/// <param name="id">���[���hID</param>
	virtual WorldPtr FindWorld(const WORLD_ID& id) = 0;
	/// <summary>
	/// �w�肵���A�N�^�[�̐����擾
	/// </summary>
	/// <param name="id">�A�N�^�[ID</param>
	/// <returns>�J�E���g</returns>
	virtual int ActorsCount(const ACTOR_ID& id) = 0;
	/// <summary>
	/// ���[���h���N���A�[
	/// </summary>
	virtual void Clear() = 0;
};