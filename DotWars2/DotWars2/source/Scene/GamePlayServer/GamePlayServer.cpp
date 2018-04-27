#include "GamePlayServer.h"
#include "../../NetWork/MySocketVar2/UDP/Manager/UDPServerSocketManager.h"



GamePlayServer::GamePlayServer(WorldManagerPtr manager) :
	mWorldManager(manager)
{
}

GamePlayServer::~GamePlayServer()
{
}

void GamePlayServer::Start()
{
	//�V�[���ݒ�
	mIsEnd = false;
	mMyScene = SceneID::GAME_PLAY_SERVER_SCENE;
	//UDP�ʐM�J�n
	mUDPManager = new UDPServerSocketManager();

	//TCP�Ŏ�����N���C�A���g�̏���UDP�ɓn��
	for (const auto& i : mWorldManager->GetServerManager()->GetConnectSockets()) {
		mUDPManager->AddClientAdd(i);
	}
	//��Ԃ�������
	mUDPManager->SetState(mWorldManager->GetServerManager()->GetFirstState());

	//�T�[�o�[�R���W����
	mServerCollision = new ServerCollision();


}

void GamePlayServer::Update()
{
	serverCount++;
	mUDPManager->Read();
	ServerToClientState clientStates = mUDPManager->GetState();
	mServerCollision->CollisionCheck(mWorldManager->GetWorld(WORLD_ID::GAME_WORLD), mUDPManager->GetState());
	bulletPos.clear();
	for (auto i : clientStates.bulletPos) {
		if (i.x == 0 && i.y == 0 && i.z == 0)continue;
		bulletPos.push_back("x:" + std::to_string(i.x) + "y:" + std::to_string(i.y) + "z:" + std::to_string(i.z));
	}
	debug = "Player1 PosX:" + std::to_string(clientStates.states[0].position.x) + "PosY" + std::to_string(clientStates.states[0].position.y) +
		"Player2 PosX:" + std::to_string(clientStates.states[1].position.x) + "PosY" + std::to_string(clientStates.states[1].position.y);
	if (serverCount % 3 == 0)
		mUDPManager->Send();

}

void GamePlayServer::Draw() const
{
	std::string text = "�Q�[���v���C�T�[�o�[";
	DrawString(0, 0, text.c_str(), GetColor(255, 255, 255));
	int count =0;
	for (const auto& i : bulletPos) {
		DrawString(0, 128 + 32 * count, i.c_str(), GetColor(255, 255, 255));
		count++;
	}
	DrawString(0, 64, debug.c_str(), GetColor(255, 255, 255));
}

void GamePlayServer::End()
{
}
