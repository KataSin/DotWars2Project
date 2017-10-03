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

	void Update();
	void Draw() const;

	/// <summary>
	/// ���[���h�ɃA�N�^�[��ǉ�����
	/// </summary>
	/// <param name="id">�A�N�^�[ID</param>
	/// <param name="actor">�A�N�^�[</param>
	virtual void Add(const ACTOR_ID& id, ActorPtr actor) override;
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

private:
	//�A�N�^�[���
	std::unordered_map<ACTOR_ID, ActorManager> mActors;
	//���[���h�}�l�[�W���[
	WorldManagerPtr mWorldManager;
	//�����蔻����
	std::unordered_map<COL_ID, std::function<CollisionParameter>> m_Cols;
};