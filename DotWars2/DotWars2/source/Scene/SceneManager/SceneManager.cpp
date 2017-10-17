#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::sceneStart()
{
	mScenes.clear();
}

void SceneManager::sceneUpdate()
{
	mScenes[mNowSceneID]->Update();
	//シーンが終わってたら次のシーンに変える
	if (mScenes[mNowSceneID]->GetIsEnd()) {
		SceneChange(mNowSceneID);

	}
}

void SceneManager::sceneDraw()
{
	mScenes[mNowSceneID]->Draw();
}

void SceneManager::sceneEnd()
{
	mScenes.clear();
}

void SceneManager::AddScene(const SceneID & id, ScenePtr scenePtr)
{
	mScenes[id] = scenePtr;
}

void SceneManager::StartScene(const SceneID & id)
{
	mNowSceneID = id;
	mScenes[mNowSceneID]->Start();
}

void SceneManager::SceneChange(const SceneID & id)
{
	mScenes[mNowSceneID]->End();
	mNowSceneID = mScenes[mNowSceneID]->GetNextSceneId();
	mScenes[mNowSceneID]->Start();
}
