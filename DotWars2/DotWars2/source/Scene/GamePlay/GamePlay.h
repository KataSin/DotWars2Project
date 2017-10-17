#pragma once
#include "../Scene.h"
#include "../../IncludePtr.h"
#include "../../World/WorldManager/WorldManager.h"
class GamePlay :public Scene
{
public:
	GamePlay(WorldManagerPtr manager);
	virtual ~GamePlay() override;
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
	WorldManagerPtr mWorldManager;
};