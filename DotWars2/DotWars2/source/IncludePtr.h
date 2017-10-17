#pragma once
#include <memory>
class Actor;
class ActorManager;
class World;
class WorldManager;
class Scene;
class SceneManager;


using ActorPtr = std::shared_ptr<Actor>;
using ActorManagerPtr = std::shared_ptr<ActorManager>;
using WorldPtr = std::shared_ptr<World>;
using WorldManagerPtr = std::shared_ptr<WorldManager>;
using ScenePtr = std::shared_ptr<Scene>;
using SceneManagerPtr = std::shared_ptr<SceneManager>;