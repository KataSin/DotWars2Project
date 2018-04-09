#pragma once
enum ACTOR_ID {
	//ゲームプレイ関係
	PLAYER_ACTOR,
	PLAYER_BULLET_ACTOR,
	PLAYER_BULLET_POINT_ACTOR,
	ENEMY_ACTOR,
	DEFAULT_PLATE_ACTOR,
	//その他
	CAMERA_ACTOR,
	//モデル系
	STAGE_ACTOR
};

enum COL_ID {
	PLAYER_ENEMY_COL,
	PLAYER_PLATE_COL
};

enum PLAYER_ID {
	MY_PLAYER_ID,
	PLAYER_2_ID,
	PLAYER_3_ID,
	PLAYER_4_ID
};