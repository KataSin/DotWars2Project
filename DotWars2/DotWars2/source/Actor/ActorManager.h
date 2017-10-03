#pragma once
#include "Actor.h"
#include <list>
#include "../IncludePtr.h"
class ActorManager {
public:


	ActorManager();
	~ActorManager();
	/// <summary>
	/// アクターを追加する
	/// </summary>
	/// <param name="actor">アクター</param>
	void Add(ActorPtr actor);
	/// <summary>
	/// アクターたちを取得
	/// </summary>
	/// <returns>アクターたち</returns>
	std::list<ActorPtr>GetActors();
	void Update();
	void Draw()const;
private:
	std::list<ActorPtr>mActors;
};