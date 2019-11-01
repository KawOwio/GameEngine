#pragma once

#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

namespace engine
{
	class Environment
	{
	private:
		float deltaTime;

	public:
		float getDeltaTime();
	};
}

#endif