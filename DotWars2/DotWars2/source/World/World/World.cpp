#include "World.h"
#include "../../Actor/CollisionActor/CollisionActor.h"
#include "../WorldManager/WorldManager.h"
#include <algorithm>
World::World(WorldManagerPtr manager)
{
	//ƒRƒŠƒWƒ‡ƒ“î•ñ‚ð“ü‚ê‚é
	CollisionActor colAc;
	m_Cols = colAc.GetCols();
}

World::~World()
{
}

void World::Start()
{
	for (auto& i : mActors) {
		i.second.Start();
	}

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

void World::Collision(const ACTOR_ID & id, const COL_ID & colId, Actor & actor)
{
	const auto& actors = FindActors(id);
	for (const auto& i : actors) {
		CollisionParameter parameter;
		parameter = m_Cols[colId](*i, actor);
		if (parameter.colFlag) {
			i->Collision(actor, parameter);
			actor.Collision(*i, parameter);
		}
	}
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

void World::Clear()
{
	mActors.clear();
}
