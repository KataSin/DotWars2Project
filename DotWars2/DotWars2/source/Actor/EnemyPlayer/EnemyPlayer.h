#pragma once
#include "../Actor.h"

struct EnemyPlayerState {
	Vector3 pos; //�|�W�V����
	int stateID;//���ID
	PLAYER_ID id;//�v���C���[��ID
};
class EnemyPlayer :public Actor {
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="mat">�}�g���N�X</param>
	EnemyPlayer(IWorld& world, const EnemyPlayerState& state);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~EnemyPlayer()override;
	/// <summary>
	/// �X�^�[�g
	/// </summary>
	virtual void Start() override;
	/// <summary>
	/// �A�b�v�f�[�g
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() const override;
	/// <summary>
	///	�����蔻��
	/// </summary>
	/// <param name="other">���������I�u�W�F�N�g</param>
	virtual void Collision(Actor& other, const CollisionParameter& parameter)override;
	/// <summary>
	/// �G�l�~�[�v���C���[����ݒ肷��
	/// </summary>
	/// <param name="state"></param>
	void SetEnemyPlayerState(const EnemyPlayerState& state);
private:
	//�ړ��̃x�N�g��
	Vector3 mVec;
	//�x�N�g�������߂邽�߂̍��W
	Vector3 mSeveVec;

	EnemyPlayerState mState;
};