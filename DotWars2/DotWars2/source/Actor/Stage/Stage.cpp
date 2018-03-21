#include "Stage.h"

#include "../../Graphic/Model/Model.h"

#include "DefaultPlate\DefaultPlate.h"

Stage::Stage(IWorld & world) :
	Actor(world)
{
	mParameter.isDead = false;

	world.Add(ACTOR_ID::DEFAULT_PLATE_ACTOR, std::make_shared<DefaultPlate>(world,Matrix4::Identity));

}

Stage::~Stage()
{
}

void Stage::Start()
{
	mStageMat =
		Matrix4::Scale(50.0f)*
		Matrix4::Translate(Vector3(0, -1500, 0));
}

void Stage::Update()
{
}

void Stage::Draw() const
{
	Model::GetInstance().Draw(MODEL_ID::STAGE_MODEL, mStageMat);


}

void Stage::Collision(Actor & other, const CollisionParameter & parameter)
{
}

void Stage::PlateSpawn()
{
	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {

		}
	}
}
