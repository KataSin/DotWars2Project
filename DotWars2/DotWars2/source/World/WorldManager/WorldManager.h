#pragma once
#include "../WorldID.h"
#include "../../IncludePtr.h"
#include "../World/World.h"
#include <unordered_map>
class WorldManager {
public:
	struct WorldState {
		WorldPtr world; //���[���h
		bool isStop;    //�~�܂��Ă��邩�ǂ���
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
	/// ���[���h�}�l�[�W���[���N���A
	/// </summary>
	void ManagerClear();
	/// <summary>
	/// ���[���h���N���A�[
	/// </summary>
	void WorldAllClear();
	/// <summary>
	/// �w�肵�����[���h���N���A�[
	/// </summary>
	/// <param name="id"></param>
	void WorldClear(const WORLD_ID& id);
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
	/// <summary>
	/// �w�肵�����[���h���擾����
	/// </summary>
	/// <param name="id">���[���hID</param>
	/// <returns>���[���h�|�C���^�[</returns>
	WorldPtr GetWorld(const WORLD_ID& id);

private:
	std::unordered_map<WORLD_ID, WorldState> mWorlds;

};