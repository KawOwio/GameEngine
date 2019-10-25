#pragma once

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <vector>

namespace engine
{
	class Keyboard
	{
	private:
		std::vector<int> keyCodes;

	public:
		bool getKey(int _keyCode);
		bool getKeyUp(int _keyCode);
		bool getKeyDown(int _keyCode);
	};
}

#endif