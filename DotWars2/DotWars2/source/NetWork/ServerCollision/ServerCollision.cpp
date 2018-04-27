#include "ServerCollision.h"
#include "../../Actor/EnemyBullet/EnemyBullet.h"
#include "../../Actor/PlayerBullet/PlayerBullet.h"
//����}�X�̃T�C�Y
const float PLATE_SIZE = 50.0f;

const int STAGE_SIZE = 16;
ServerCollision::ServerCollision()
{
	//�X�e�[�W�̏����ݒ�

	int indexY = 0;
	for (int i = -STAGE_SIZE / 2; i < STAGE_SIZE / 2; i++) {
		int indexX = 0;
		for (int j = -STAGE_SIZE / 2; j < STAGE_SIZE / 2; j++) {
			mPlateStates[indexY][indexX].position = Vector3(i * 100, 0, j * 100);
			mPlateStates[indexY][indexX].hp = 3;
			indexX++;
		}
		indexY++;
	}
}

ServerCollision::~ServerCollision()
{
}

void ServerCollision::CollisionCheck(WorldPtr world, ServerToClientState & state)
{
	for (auto& i : state.states) {
		//�I�y���[�^�ǉ����Ă��Ȃ�����
		if (i.attackVec.x != 0 &&
			i.attackVec.y != 0 &&
			i.attackVec.z != 0) {
			PlayerBullet::BulletState bulletState;
			bulletState.spawnPos = NetVec3::ToVector3(i.position);
			bulletState.vec = NetVec3::ToVector3(i.attackVec);
			world->Add(ACTOR_ID::ENEMY_BULLET_ACTOR, std::make_shared<EnemyBullet>(*world, bulletState));
			//0,0,0�ɏ�����
			i.attackVec = NetVec3(0, 0, 0);
		}
	}
	//�e�ƃX�e�[�W�̂����蔻��`�F�b�N
	const auto & bullets = world->FindActors(ACTOR_ID::ENEMY_BULLET_ACTOR);

	for (auto& bullet : bullets) {

		for (int i = 0; i <= 15; i++) {
			for (int j = 0; j <= 15; j++) {
				//HP��0�������ꍇ
				if (mPlateStates[i][j].hp <= 0) {

				}
				else
				{
					//�����v���[�g�ɓ������Ă�����
					if (Plate_Bullet(mPlateStates[i][j].position, bullet->GetParameter().mat.GetPosition()))
					{
						//�e������
						bullet->GetParameter().isDead = true;
						//HP���}�C�i�X
						mPlateStates[i][j].hp--;
					}
				}
			}
		}
	}
	//�c���HP��ݒ�
	for (int i = 0; i <= 15; i++) {
		for (int j = 0; j <= 15; j++) {
			state.stagePlates[i][j] = mPlateStates[i][j].hp;
		}
	}


	//�T�[�o�[�ŊǗ����Ă���e�̏���ݒ�
	int count = 0;
	for (const auto& i : bullets) {
		state.bulletPos[count] = NetVec3::ToNetVec3(i->GetParameter().mat.GetPosition());
		count++;
	}
	//�ݒ肳��Ȃ������z��
	for (int i = count; i <= 31; i++) {
		state.bulletPos[i] = NetVec3(0, 0, 0);
	}

}

bool ServerCollision::Player_Bullet(const Vector3 & player, const Vector3 & bullet)
{
	return false;
}

bool ServerCollision::Plate_Bullet(const Vector3 & plate, const Vector3 & bullet)
{
	CollisionParameter colpara;
	//�v���[�g
	Box boxPlate;
	boxPlate.min = plate - Vector3(-PLATE_SIZE, -5.0f, -PLATE_SIZE);
	boxPlate.max = plate - Vector3(PLATE_SIZE, 0.0f, PLATE_SIZE);
	//�e(Line3�{����)

	Line bullet1;
	bullet1.startPos = bullet + Vector3(4, 0, 0);
	bullet1.endPos = bullet + Vector3(-4, 0, 0);;

	Line bullet2;
	bullet2.startPos = bullet + Vector3(0, 4, 0);;
	bullet2.endPos = bullet + Vector3(0, -4, 0);;
	Line bullet3;
	bullet3.startPos = bullet + Vector3(0, 0, 4);;
	bullet3.endPos = bullet + Vector3(0, 0, -4);;


	colpara = Collisin::GetInstace().SegmentBoxAABB(bullet1, boxPlate);
	if (!colpara.colFlag)
		colpara = Collisin::GetInstace().SegmentBoxAABB(bullet2, boxPlate);
	if (!colpara.colFlag)
		colpara = Collisin::GetInstace().SegmentBoxAABB(bullet3, boxPlate);

	return colpara.colFlag;

}
