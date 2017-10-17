#pragma once
#include "../Scene.h"
#include <unordered_map>
#include "../../IncludePtr.h"
class SceneManager {
public:
	SceneManager();
	~SceneManager();

	/// <summary>
	/// �V�[���X�^�[�g
	/// </summary>
	void sceneStart();
	/// <summary>
	/// �V�[���A�b�v�f�[�g
	/// </summary>
	void sceneUpdate();
	/// <summary>
	/// �V�[���`��
	/// </summary>
	void sceneDraw();
	/// <summary>
	/// �V�[���G���h
	/// </summary>
	void sceneEnd();
	/// <summary>
	/// �V�[����ǉ�����
	/// </summary>
	/// <param name="id">�ǉ�����V�[��ID</param>
	/// <param name="scenePtr">�ǉ�����V�[��</param>
	void AddScene(const SceneID& id, ScenePtr scenePtr);
	/// <summary>
	/// �ŏ��ɕ\������V�[��
	/// </summary>
	/// <param name="id"></param>
	void StartScene(const SceneID& id);
private:
	/// <summary>
	/// �V�[����ύX������
	/// </summary>
	/// <param name="id">�ύX������SceneID</param>
	void SceneChange(const SceneID& id);
	/// <summary>

private:
	//�V�[������
	std::unordered_map<SceneID, ScenePtr>mScenes;
	//���݂̃V�[��
	SceneID mNowSceneID;
};