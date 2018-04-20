#pragma once
#include "../Scene.h"
#include "../../IncludePtr.h"
#include "../../World/WorldManager/WorldManager.h"

#include "../../NetWork/ServerCollision/ServerCollision.h"

//��s�錾
class UDPServerSocketManager;

class GamePlayServer :public Scene
{
public:
	GamePlayServer(WorldManagerPtr manager);
	virtual ~GamePlayServer() override;
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
	//UDP�}�l�[�W���[
	UDPServerSocketManager* mUDPManager;
	
	ServerCollision* mServerCollision;
	
	WorldManagerPtr mWorldManager;

	//�e�X�g
	std::string debug;
	int serverCount;
};