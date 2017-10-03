#include "World.h"
#include "../WorldManager/WorldManager.h"
#include <algorithm>
World::World(WorldManagerPtr manager)
{
}

World::~World()
{
}

void World::Update()
{
	for (auto& i : mActors) {
		i.second.Update();
	}
	
}

void World::Draw() const
{
	for (const auto& i : mActors) {
		i.second.Draw();
	}
}

void World::Add(const ACTOR_ID & id, ActorPtr actor)
{
	mActors[id].Add(actor);
}

std::list<ActorPtr> World::FindActors(const ACTOR_ID& id)
{
	return mActors[id].GetActors();
}

WorldPtr World::FindWorld(const WORLD_ID & id)
{
	return mWorldManager->GetWorld(id);
}

int World::ActorsCount(const ACTOR_ID & id)
{
	return mActors[id].GetActors().size();
}
