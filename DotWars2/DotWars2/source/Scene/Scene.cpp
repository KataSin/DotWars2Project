#include "Scene.h"

Scene::~Scene()
{

}

SceneID Scene::GetMySceneId()
{
	return mMyScene;
}

SceneID Scene::GetNextSceneId()
{
	return mNextScene;
}

bool Scene::GetIsEnd()
{
	return mIsEnd;
}
