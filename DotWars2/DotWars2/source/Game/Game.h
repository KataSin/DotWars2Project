#pragma once
#include "../IncludePtr.h"
#include "../World/WorldManager/WorldManager.h"
#include "../World/World/World.h"
#include <memory>

#include "../NetWork/MySocketVar2/TCP/Manager/TCPClientSocketManager.h"
#include "../NetWork/MySocketVar2/TCP/Manager/TCPServerSocketManager.h"
#include "../NetWork/MySocketVar2/UDP/Manager/UDPClientSocketManager.h"
#include "../NetWork/MySocketVar2/UDP/Manager/UDPServerSocketManager.h"


class Game {
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="windowWight">�E�B���h�E�̉�</param>
	/// <param name="windowHeght">�E�B���h�E�̏c</param>
	/// <param name="fullScene">�t���X�N���[�����ǂ���</param>
	Game(int windowWight, int windowHeght, bool fullScene = true);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Game();
	/// <summary>
	/// ��������
	/// </summary>
	void Start();
	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update();
	/// <summary>
	/// �`�ʏ���
	/// </summary>
	void Draw()const;
	/// <summary>
	/// �I�������Ă΂��
	/// </summary>
	void End();
private:
	//�T�[�o�[���ǂ���
	bool serverFlag;
	//���[���h�|�C���^�[
	WorldManagerPtr mWorldManager;
	//�V�[���}�l�[�W���[
	SceneManagerPtr mSceneManager;

	FirstToClientState mFirstState;

	DotWarsNet mClientState;
	std::string debug;
};