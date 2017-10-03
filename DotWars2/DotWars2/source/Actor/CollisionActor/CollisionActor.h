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
	CollisionParameter Player_Enemy_Col(Actor & actor1, Actor & actor2);
	/// <summary>
	/// �R���W���������擾
	/// </summary>
	/// <returns>�R���W�������</returns>
	std::unordered_map<COL_ID, std::function<CollisionParameter>> GetCols();
	
private:
	std::unordered_map<COL_ID, std::function<CollisionParameter>> m_Cols;

};