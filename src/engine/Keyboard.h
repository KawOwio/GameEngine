#pragma once

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <vector>
#include "rend/rend.h"
#include "Core.h"

namespace engine
{
	class Keyboard
	{
	private:
		std::vector<int> keyCodes;

		rend::vec2 oldMousePos = rend::vec2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		rend::vec2 newMousePos;
		float pitch = 40.0f;
		float yaw;

	public:
		///	A function to check if a key was pressed.
		/// Goes through a vector of currently pressed buttons and checks if the specific button is pressed.
		///	@param _keyCode is SDL2 keycode's values (f.e SDLK_W)
		/// @returns true or false depending if a button is pressed or no
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	if(getKeyboard)->isKey(SDLK_W) == true)
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		bool isKey(int _keyCode);

		///	A function that is called when a user releases a keyboard button.
		/// Goes through a vector of currently pressed buttons and removes the button that user released from the vector.
		///	@param _keyCode is SDL2 keycode's values (f.e SDLK_W)
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	keyboard->keyUp(event.key.keysym.sym);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void keyUp(int _keyCode);

		///	A function that is called when a user presses a keyboard.
		/// Goes through a vector of currently pressed buttons and adds the currently pressed button to the vector.
		/// Unless it is already in the vector.
		///	@param _keyCode is SDL2 keycode's values (f.e SDLK_W)
		/// @returns true or false depending if a button is in the vector already or not.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	keyboard->keyDown(event.key.keysym.sym);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		bool keyDown(int _keyCode);

		///	A function to rotate the camera.
		/// @returns the difference between the old and the new mouse position.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	rend::vec2 rotation = getKeyboard()->rotateCamera();
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		rend::vec2 rotateCamera();

		///	A function to check if the mouse has been moved.
		/// Use it when you are checking for user's input.
		/// @returns true or false depending if mouse has moved or not.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	if (getKeyboard()->isMouse() == true)
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		bool isMouse();

		///	A function to change new mouse position.
		/// @param _motion is the amount the mouse has moved
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	keyboard->motion(rend::vec2((float)event.motion.x, (float)event.motion.y));
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void motion(rend::vec2 _motion);
	};
}

#endif