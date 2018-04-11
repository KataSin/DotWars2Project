#include "Title.h"

#include "../../Actor/Player/Player.h"
#include "../../Actor/CameraActor/CameraActor.h"
#include "../../Actor/Stage/Stage.h"

#include "../../Utility/Input/Keyboard/Keyboard.h"

#include "../../Graphic/ModelAnim/ModelAnim.h"
#include "../../Camera/Camera.h"

#include "../../Graphic/Model/Model.h"
Title::Title(WorldManagerPtr manager)
{
	mIsEnd = false;
}

Title::~Title()
{
}

void Title::Start()
{
	mMyScene = SceneID::TITLE_SCENE;
	mIsEnd = false;
}

void Title::Update()
{
	if (Keyboard::GetInstance().KeyTriggerDown(KEYCODE::M)) {
		mNextScene = SceneID::MATCHING_SCENE;
		mIsEnd = true;
	}
	if (Keyboard::GetInstance().KeyTriggerDown(KEYCODE::S)) {
		mNextScene = SceneID::SERVER_SCENE;
		mIsEnd = true;
	}
}

void Title::Draw() const
{
	DrawString(0, 0, "S:サーバー  M:マッチング", GetColor(255, 255, 255));

}

void Title::End()
{
}
