#pragma once
#include "../../IncludePtr.h"
#include "../WorldManager/WorldManager.h"
#include "../IWorld.h"
#include "../../Actor/ActorManager.h"
#include "../../Actor/CollisionActor/CollisionActor.h"
#include <list>
#include <vector>
#include <unordered_map>
#include <functional>
class World :public IWorld {
public:
	World(WorldManagerPtr manager);
	~World();
	void Start();
	void Update();
	void Draw() const;

	/// <summary>
	/// ���[���h�ɃA�N�^�[��ǉ�����
	/// </summary>
	/// <param name="id">�A�N�^�[ID</param>
	/// <param name="actor">�A�N�^�[</param>
	virtual void Add(const ACTOR_ID& id, ActorPtr actor) override;

	/// <summary>
	/// �����蔻�������
	/// </summary>
	/// <param name="id">���Ă����A�N�^�[ID</param>
	/// <param name="colId">�R���W�����̎��</param>
	/// <param name="actor">���g�̃A�N�^�[</param>
	virtual void Collision(const ACTOR_ID& id, const COL_ID& colId, Actor& actor) override;
	/// <summary>
	/// �w�肵���A�N�^�[������T��
	/// </summary>
	/// <param name="id">�A�N�^�[ID</param>
	/// <returns>�A�N�^�[����</returns>
	virtual std::list<ActorPtr> FindActors(const ACTOR_ID& id) override;
	/// <summary>
	/// �w�肵�����[���h���擾����
	/// </summary>
	/// <param name="id">���[���hID</param>
	virtual WorldPtr FindWorld(const WORLD_ID& id) override;
	/// <summary>
	/// �w�肵���A�N�^�[�̐����擾
	/// </summary>
	/// <param name="id">�A�N�^�[ID</param>
	virtual int ActorsCount(const ACTOR_ID& id) override;
	/// <summary>
	/// ���[���h���N���A�[
	/// </summary>
	virtual void Clear()override;

private:

	//�A�N�^�[���
	std::unordered_map<ACTOR_ID, ActorManager> mActors;
	//���[���h�}�l�[�W���[
	WorldManagerPtr mWorldManager;
	//�����蔻����
	std::unordered_map<COL_ID, std::function<CollisionParameter(const Actor & actor1, const Actor & actor2)>> m_Cols;
};