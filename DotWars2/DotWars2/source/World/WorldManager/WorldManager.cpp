#include "WorldManager.h"

WorldManager::WorldManager()
{
}

WorldManager::~WorldManager()
{
}
void WorldManager::Update()
{
	for (auto& i : mWorlds) {
		if (i.first)return;
		i.second.world->Update();
	}
}

void WorldManager::Draw() const
{
	for (const auto& i : mWorlds) {
		i.second.world->Draw();
	}
}
void WorldManager::Clear()
{
	mWorlds.clear();
}

void WorldManager::Add(const WORLD_ID & id, WorldPtr world)
{
	WorldState state;
	state.isStop = false;
	state.world = world;
	mWorlds[id] = state;
}

void WorldManager::WorldStop(const WORLD_ID & id)
{
	mWorlds[id].isStop = true;
}

void WorldManager::WorldStart(const WORLD_ID & id)
{
	mWorlds[id].isStop = false;
}

WorldPtr WorldManager::GetWorld(const WORLD_ID & id)
{
	return mWorlds[id].world;
}
