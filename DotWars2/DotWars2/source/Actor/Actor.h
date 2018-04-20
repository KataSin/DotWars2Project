#pragma once
//Math�֌W
#include "../Math/Math.h"
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include "../Math/Vector4.h"
#include "../Math/Matrix4.h"
//���̑�
#include "../World/IWorld.h"
#include "../World/World/World.h"
struct Parameter {
	//�v���C���[ID
	PLAYER_ID playerID;
	//�}�g���N�X
	Matrix4 mat;
	//����ł��邩
	bool isDead;

	//������(�v���C���[����)
	DotWarsNet state;

};

class Actor {
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="world">���[���h</param>
	Actor(IWorld& world);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Actor();
	/// <summary>
	/// �X�^�[�g
	/// </summary>
	virtual void Start() = 0;
	/// <summary>
	/// �A�b�v�f�[�g
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() const = 0;
	/// <summary>
	///	�����蔻��
	/// </summary>
	/// <param name="other">���������I�u�W�F�N�g</param>
	virtual void Collision(Actor& other, const CollisionParameter& parameter) = 0;
	/// <summary>
	///	����ł��邩�擾
	/// </summary>
	/// <returns>����ł��邩�t���O</returns>
	bool GetIsDead()const;
	/// <summary>
	/// �p�����[�^�[���擾(�Q�Ɣ�)
	/// </summary>
	/// <returns>�p�����[�^�[</returns>
	Parameter& GetParameter();
	/// <summary>
	/// �p�����[�^�[���擾(const��)
	/// </summary>
	/// <returns></returns>
	Parameter GetParameter() const;
protected:
	Parameter mParameter;
	IWorld& mWorld;
};
