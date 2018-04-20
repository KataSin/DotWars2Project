#pragma once
#include "../Math/Vector3.h"
#include "../Math/NetVec3.h"
#include "../Actor/ActorID.h"
#include <vector>

//同期させる情報の構造体を作る

//クライアントがサーバーに送る情報
struct DotWarsNet
{
	short int playerNum = -1;		//どのプレイヤーか
	unsigned int frame = 0;			//どのフレーム数か
	NetVec3 position;				//プレイヤーの座標(テスト)
	NetVec3 attackVec;				//球が飛ぶベクトル(攻撃中でなければ(999,999,999)が入る)
};
//サーバーがクライアントに送る情報
struct ServerToClientState
{
	unsigned int frame = 0;						//フレーム数
	short int playerNum = -1;					//受け取るプレイヤー番号
	short int playerHp = 0;						//プレイヤーHP
	DotWarsNet states[4];						//プレイヤーの状態コンテナ
	char stagePlates[16][16];					//ステージのプレートHP
	NetVec3 bulletPos[32];						//敵弾の座標
};

//最初にサーバーが送る情報
struct FirstToClientState
{
	NetVec3 position = NetVec3(0, 0, 0);	//初期ポジション
	short int playerNum = -1;					//プレイヤー番号
};

//弾のあたり判定用構造体
struct CollisionCheckState {
	PLAYER_ID playerID;
	Vector3 playerPos;
	
};