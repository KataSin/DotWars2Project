#pragma once
#include "../Math/Vector3.h"
#include <vector>

//同期させる情報の構造体を作る

struct DotWarsNet
{
	int playerNum = -1;    //どのプレイヤーか
	Vector3 position; //プレイヤーの座標(テスト)
};

struct ServerToClientState
{
	int playerNum = -1;                  //受け取るプレイヤー番号
	DotWarsNet states[4]; //プレイヤーの状態コンテナ
};

//最初にサーバーが送る情報
struct FirstToClientState
{
	Vector3 position = Vector3::Zero; //初期ポジション
	int playerNum = -1;               //プレイヤー番号
};