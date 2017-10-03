#pragma once
#include "../WorldID.h"
#include "../../IncludePtr.h"
#include "../World/World.h"
#include <unordered_map>
class WorldManager {
public:
	struct WorldState {
		WorldPtr world;
		bool isStop;
	};


public:
	WorldManager();
	~WorldManager();

	/// <summary>
	/// ���[���h�A�b�v�f�[�g
	/// </summary>
	void Update();
	/// <summary>
	/// ���[���h�`��
	/// </summary>
	void Draw() const;
	/// <summary>
	/// <summary>
	/// ���[���h���N���A
	/// </summary>
	void Clear();
	/// <summary>
	/// ���[���h��ǉ�����
	/// </summary>
	/// <param name="id"></param>
	/// <param name="world"></param>
	void Add(const WORLD_ID& id, WorldPtr world);
	/// <summary>
	/// �w�肵�����[���h�̃A�b�v�f�[�g���~�߂�
	/// </summary>
	/// <param name="id">���[���hID</param>
	void WorldStop(const WORLD_ID& id);
	/// <summary>
	/// �w�肵�����[���h���A�b�v�f�[�g���X�^�[�g������
	/// </summary>
	/// <param name="id">���[���hID</param>
	void WorldStart(const WORLD_ID& id);

	WorldPtr GetWorld(const WORLD_ID& id);

private:
	std::unordered_map<WORLD_ID, WorldState> mWorlds;

};