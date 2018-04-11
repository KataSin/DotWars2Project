#pragma once
#include "../Scene.h"
#include "../../IncludePtr.h"
#include "../../World/WorldManager/WorldManager.h"

#include "../../NetWork/MySocketVar2/TCP/Manager/TCPClientSocketManager.h"
#include "../../NetWork/MySocketVar2/UDP/Manager/UDPClientSocketManager.h"

class Matching :public Scene
{
public:
	Matching(WorldManagerPtr manager);
	virtual ~Matching() override;
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
	TCPClientSocketManager* mTCPManager;
	UDPClientSocketManager* mUDPManager;
	//�ʐM�ǂ��܂ōs���Ă邩
	int mStageNum;

	//�ŏ��̏��
	FirstToClientState mFirstState;
	
	//

	//�e�X�g
	int clientCount;
	std::string debug;

};