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
}

//TODO: 
//add mouse support
//add gamepad support (https://davidgow.net/handmadepenguin/ch6.html)