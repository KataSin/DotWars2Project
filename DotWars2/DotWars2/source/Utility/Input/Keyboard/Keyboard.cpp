#include "Keyboard.h"

Keyboard::Keyboard()
{
	for (int i = 0; i < 256; i++)
	{
		mOnKey[i] = 0;
		mOffKey[i] = 0;
	}
}

bool Keyboard::KeyTriggerDown(UINT keycode)
{
	if (mOnKey[keycode] == 1)
	{
		return true;
	}
	return false;
}

bool Keyboard::KeyStateDown(UINT keycode)
{
	if (mKeyCode[keycode] == 1)
	{
		return true;
	}
	return false;
}

bool Keyboard::KeyTriggerUp(UINT keycode)
{
	if (mOffKey[keycode] == 1)
	{
		return true;
	}
	return false;
}

bool Keyboard::KeyStateUp(UINT keycode)
{
	if (mKeyCode[keycode] == 0)
	{
		return true;
	}
	return false;
}

bool Keyboard::AnyTriggerDown()
{
	for (int i = 0; i < 256; i++)
	{
		if (mOnKey[i] == 1)
		{
			return true;
		}
	}
	return false;
}

bool Keyboard::AnyStateDown()
{
	for (int i = 0; i < 256; i++)
	{
		if (mKeyCode[i] == 1)
		{
			return true;
		}
	}
	return false;
}

bool Keyboard::AnyStateUp()
{
	for (int i = 0; i < 256; i++)
	{
		if (mKeyCode[i] == 0)
		{
			return true;
		}
	}
	return false;
}

bool Keyboard::AnyTriggerUp()
{
	for (int i = 0; i < 256; i++)
	{
		if (mOffKey[i] == 1)
		{
			return true;
		}
	}
	return false;
}

void Keyboard::Update()
{
	GetHitKeyStateAll(mKeyCode);
	for (int i = 0; i < 256; i++)
	{
		KeyUpdate(mKeyCode[i], i);
	}
}

void Keyboard::KeyUpdate(const char & key, int num)
{
	if (key != 0)
	{
		mOffKey[num] = 0;
		mOnKey[num]++;
	}
	else
	{
		mOnKey[num] = 0;
		mOffKey[num]++;
	}
}
