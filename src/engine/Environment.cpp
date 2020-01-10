#include "Environment.h"

namespace engine
{
	float Environment::getDeltaTime()
	{
		float time = SDL_GetTicks();
		float diff = time - lastTime;
		lastTime = time;
		return diff / 1000.0f;
	}
}