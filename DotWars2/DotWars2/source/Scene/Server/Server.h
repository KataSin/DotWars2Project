#pragma once
#include <string>

#include "../Scene.h"
#include "../../IncludePtr.h"

#include "../../NetWork/MySocketVar2/TCP/Manager/TCPServerSocketManager.h"
#include "../../NetWork/MySocketVar2/UDP/Manager/UDPServerSocketManager.h"

class Server :public Scene
{
public:
	Server(WorldManagerPtr manager);
	virtual ~Server() override;
	/// <summary>
	/// �V�[���X�^�[�g
	/// </summary>
	virtual void Start() override;
	/// <summary>
	/// �V�[���A�b�v�f�[�g
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() const override;
	/// <summary>
	/// �I������
	/// </summary>
	virtual void End() override;
private:
	//���[���h�}�l�[�W���[
	WorldManagerPtr mWorldManager;
	//�ʐM�n
	TCPServerSocketManager* mTCPManager;
	UDPServerSocketManager* mUDPManager;
	//�ʐM�ǂ��܂ōs���Ă邩
	int mStageNum;

	//�e�X�g
	int serverCount;
	std::string debug;
};