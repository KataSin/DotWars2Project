#pragma once
#include "Actor.h"
#include <list>
#include "../IncludePtr.h"
class ActorManager {
public:


	ActorManager();
	~ActorManager();
	/// <summary>
	/// �A�N�^�[��ǉ�����
	/// </summary>
	/// <param name="actor">�A�N�^�[</param>
	void Add(ActorPtr actor);
	/// <summary>
	/// �A�N�^�[�������擾
	/// </summary>
	/// <returns>�A�N�^�[����</returns>
	std::list<ActorPtr>GetActors();
	void Update();
	void Draw()const;
private:
	std::list<ActorPtr>mActors;
};