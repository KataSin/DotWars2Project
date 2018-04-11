#pragma once
#include "Collision\Collision.h"
#include "../Actor.h"
#include "../ActorID.h"
#include <unordered_map>
#include <functional>
class CollisionActor {
public:
	CollisionActor();
	~CollisionActor();
	/// <summary>
	/// �v���C���[�ƃG�l�~�[�̂����蔻��
	/// </summary>
	/// <param name="actor1">�v���C���[</param>
	/// <param name="actor2">�G�l�~�[</param>
	/// <returns>�R���W�����p�����[�^�[</returns>
	static CollisionParameter Player_Enemy_Col(const Actor & actor1, const Actor & actor2);
	/// <summary>
	/// �v���C���[�Ə��v���[�g�̓����蔻��
	/// </summary>
	/// <param name="actor1">�v���C���[</param>
	/// <param name="actor2">�v���[�g</param>
	/// <returns></returns>
	static CollisionParameter Player_Plate_Col(const Actor & actor1, const Actor & actor2);
	/// <summary>
	/// ���Ƌ��̂����蔻��
	/// </summary>
	/// <param name="actor1">�e</param>
	/// <param name="actor2">�v���[�g</param>
	/// <returns></returns>
	static CollisionParameter Plate_Bullet_Col(const Actor & actor1, const Actor & actor2);



	/// <summary>
	/// �R���W���������擾
	/// </summary>
	/// <returns>�R���W�������</returns>
	std::unordered_map<COL_ID, std::function<CollisionParameter(const Actor & actor1, const Actor & actor2)>> GetCols();
	
private:
	std::unordered_map<COL_ID, std::function<CollisionParameter(const Actor & actor1, const Actor & actor2)>> m_Cols;

};