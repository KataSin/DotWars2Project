#pragma once
#include "../Math/Vector3.h"
#include <vector>
//同期させる情報の構造体を作る
struct DotWarsNet
{
	int playerNum;    //どのプレイヤーか
	Vector3 position; //プレイヤーの座標(テスト)
};

struct ServerToClientState
{
	std::vector<DotWarsNet> states; //プレイヤーの状態コンテナ
};