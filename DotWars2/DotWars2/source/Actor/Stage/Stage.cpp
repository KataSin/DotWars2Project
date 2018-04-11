#include "Stage.h"

#include "../../Graphic/Model/Model.h"

#include "DefaultPlate\DefaultPlate.h"

const int STAGE_SIZE = 16;

Stage::Stage(IWorld & world) :
	Actor(world)
{
	mParameter.isDead = false;


	for (int i = -STAGE_SIZE / 2; i < STAGE_SIZE/2; i++) {
		for (int j = -STAGE_SIZE / 2; j < STAGE_SIZE/2; j++) {
			Matrix4 mat = Matrix4::Translate(Vector3(i * 100, 0, j * 100));
			world.Add(ACTOR_ID::DEFAULT_PLATE_ACTOR, std::make_shared<DefaultPlate>(world, mat));
		}
	}

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
