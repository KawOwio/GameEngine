#pragma once

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <vector>
#include "rend/rend.h"

namespace engine
{
	class Keyboard
	{
	private:
		std::vector<int> keyCodes;

		rend::vec2 oldMousePos = rend::vec2(0.0f, 0.0f);
		rend::vec2 newMousePos;
		float pitch = 40.0f;
		float yaw;

	public:
		bool isKey(int _keyCode);

		void keyUp(int _keyCode);
		bool keyDown(int _keyCode);

		rend::vec2 rotateCamera();
		bool isMouse();
		void motion(rend::vec2 _motion);

		float getYaw();
		float getPitch();
	};
}

#endif