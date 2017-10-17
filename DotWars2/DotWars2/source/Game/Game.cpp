#include "Game.h"
#include <DxLib.h>
//���[���h
#include "../World/WorldManager/WorldManager.h"
#include "../World/WorldID.h"
//�V�[��
#include "../Scene/SceneManager/SceneManager.h"
#include "../Scene/Title/Title.h"
#include "../Scene/GamePlay/GamePlay.h"
//���̑�
#include "../Time/Time.h"
#include "../Utility/Input/Keyboard/Keyboard.h"
Game::Game(int windowWight, int windowHeght, bool fullScene)
{
	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(windowWight, windowHeght, 16);
	//�E�B���h�E���[�h��
	ChangeWindowMode(fullScene ? FALSE : TRUE);
	//���[���h�}�l�[�W���[
	mWorldManager = std::make_shared<WorldManager>();
	mWorldManager->Add(WORLD_ID::GAME_WORLD, std::make_shared<World>(mWorldManager));

	//�V�[���}�l�[�W���[
	mSceneManager = std::make_shared<SceneManager>();
}

Game::~Game()
{
}

void Game::Start()
{
	mSceneManager->sceneStart();
	//�V�[���ǉ�
	mSceneManager->AddScene(SceneID::TITLE_SCENE, std::make_shared<Title>(mWorldManager));
	mSceneManager->AddScene(SceneID::GAME_PLAY_SCENE, std::make_shared<GamePlay>(mWorldManager));
	//�ŏ��̃V�[��
	mSceneManager->StartScene(SceneID::TITLE_SCENE);
}

void Game::Update()
{
	//�L�[�{�[�h�A�b�v�f�[�g
	Keyboard::GetInstance().Update();
	//�^�C���A�b�v�f�[�g
	Time::GetInstance().Update();

	//�V�[���}�l�[�W���[�A�b�v�f�[�g
	mSceneManager->sceneUpdate();
}

void Game::Draw() const
{
	//�V�[���}�l�[�W���[�`��
	mSceneManager->sceneDraw();
}

void Game::End()
{
	mSceneManager->sceneEnd();
	mWorldManager->ManagerClear();
}
