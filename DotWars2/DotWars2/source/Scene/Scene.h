#pragma once
#include "SceneID.h"
class Scene {
public:
	virtual ~Scene() = 0;
	/// <summary>
	/// �V�[���X�^�[�g
	/// </summary>
	virtual void Start() = 0;
	/// <summary>
	/// �V�[���A�b�v�f�[�g
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() const = 0;
	/// <summary>
	/// �I������
	/// </summary>
	virtual void End() = 0;
	/// <summary>
	/// ���g�̃V�[����Ԃ�
	/// </summary>
	/// <returns>�V�[��ID</returns>
	virtual SceneID GetMySceneId();
	/// <summary>
	/// ���Ɉڍs����V�[����Ԃ�
	/// </summary>
	/// <returns></returns>
	virtual SceneID GetNextSceneId();
	/// <summary>
	/// �I��������ǂ����Ԃ�
	/// </summary>
	/// <returns>�I��������ǂ����t���O</returns>
	virtual bool GetIsEnd();
protected:
	//���̃V�[��
	SceneID mNextScene;
	//���g�̃V�[��
	SceneID mMyScene;
	//�I��������ǂ���
	bool mIsEnd;
};