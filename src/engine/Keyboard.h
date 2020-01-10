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
		bool isKey(int _keyCode);

		void keyUp(int _keyCode);
		bool keyDown(int _keyCode);
	};
}

#endif