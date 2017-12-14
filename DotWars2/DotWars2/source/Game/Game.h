#pragma once
#include "../IncludePtr.h"
#include "../World/WorldManager/WorldManager.h"
#include "../World/World/World.h"

#include "../NetWork/MySocket/MySocketClient/MySocketClient.h"
#include "../NetWork/MySocket/MySocketClientManager/MySocketClientManager.h"
#include "../NetWork/MySocket/MySocketServer/MySocketServer.h"
#include "../NetWork/MySocket/MySocketServerManager/MySocketServerManager.h"
#include "../NetWork/MySocket/MySocketPtr.h"



#include <memory>
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

	MySocketClientManager* clientManager;
	MySocketServerManager* serverManager;



	std::vector<DotWarsNet> mServerState;

	
	//�T�[�o�[���ǂ���
	bool serverFlag;
	//���[���h�|�C���^�[
	WorldManagerPtr mWorldManager;
	//�V�[���}�l�[�W���[
	SceneManagerPtr mSceneManager;

	int stageNum;
	

	int playerNum;

	DotWarsNet mClientState;
	std::string debug;
};