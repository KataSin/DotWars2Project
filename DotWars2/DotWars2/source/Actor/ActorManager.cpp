#include "ActorManager.h"
#include <algorithm>
ActorManager::ActorManager()
{
}

ActorManager::~ActorManager()
{
}

void ActorManager::Add(ActorPtr actor)
{
	mActors.push_back(actor);
}

std::list<ActorPtr> ActorManager::GetActors()
{
	return mActors;
}
void ActorManager::Start()
{
	std::for_each(mActors.begin(), mActors.end(),
		[](ActorPtr actor) {actor->Start(); });
}
void ActorManager::Update()
{
	std::for_each(mActors.begin(), mActors.end(),
		[](ActorPtr actor) {actor->Update(); });

	mActors.remove_if([](ActorPtr actor) {return actor->GetIsDead(); });
}

void ActorManager::Draw() const
{
	std::for_each(mActors.begin(), mActors.end(),
		[](ActorPtr actor) {actor->Draw(); });
}

