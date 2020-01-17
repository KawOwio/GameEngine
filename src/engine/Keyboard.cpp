#include "Keyboard.h"

namespace engine
{
	bool Keyboard::isKey(int _keyCode)
	{
		for (auto it = keyCodes.begin(); it != keyCodes.end(); it++)
		{
			if (*it == _keyCode)
			{
				return true;
			}
		}
		return false;
	}

	void Keyboard::keyUp(int _keyCode)
	{
		for (auto it = keyCodes.begin(); it != keyCodes.end(); it++)
		{
			if (*it == _keyCode)
			{
				keyCodes.erase(it);
				return;
			}
		}
	}

	bool Keyboard::keyDown(int _keyCode)
	{
		for (auto it = keyCodes.begin(); it != keyCodes.end(); it++)
		{
			if (*it == _keyCode)
			{
				return false;
			}
		}
		keyCodes.push_back(_keyCode);
		return true;
	}

	rend::vec2 Keyboard::rotateCamera()
	{
		rend::vec2 deltaMousePos = oldMousePos - newMousePos;

		pitch += deltaMousePos.x;
		yaw += deltaMousePos.y;

		float angle = 90.0f;

		if (pitch > angle)
		{
			pitch = angle;
		}
		else if (pitch < -angle)
		{
			pitch = -angle;
		}

		return deltaMousePos * 0.01f;
	}

	bool Keyboard::isMouse()
	{
		if (newMousePos != oldMousePos)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Keyboard::motion(rend::vec2 _motion)
	{
		newMousePos = _motion;
	}
}