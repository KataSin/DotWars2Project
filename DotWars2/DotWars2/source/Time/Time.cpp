#include "Time.h"

#include <DxLib.h>

Time::Time() :
	mLastFrame(0), mLastTime(0), mRealtimeSinceStartup(0), mFrameCount(0), mDeltaTime(0) {
}

void Time::Update(){
	mFrameCount++;
	mRealtimeSinceStartup = mFrameCount / 60;

	float currentFrame = mFrameCount;
	if (currentFrame != mLastFrame) {
		float currentTime = mRealtimeSinceStartup;
		mDeltaTime = currentTime - mLastTime;
		mLastTime = currentTime;
		mLastFrame = currentFrame;
	}
}

float Time::DeltaTime(){
	return mDeltaTime;
}


