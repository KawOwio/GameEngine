#pragma once

#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include <SDL2/SDL.h>

namespace engine
{
	class Environment
	{
	private:
		float lastTime = SDL_GetTicks();

	public:
		float getDeltaTime();
	};
}

#endif