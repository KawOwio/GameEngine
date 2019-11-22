#pragma once

#ifndef _CORE_H_
#define _CORE_H_

#include <memory>
#include <vector>
#include <SDL2/SDL.h>

#define shared std::shared_ptr
#define weak std::weak_ptr

namespace engine
{
	class Environment;
	class Entity;
	class Keyboard;

	class Core
	{
	private:
		std::shared_ptr<Environment> environemnt;
		std::shared_ptr<Keyboard> keyboard;
		std::vector<std::shared_ptr<Entity>> entities;
		std::weak_ptr<Core> self;

		bool running;

		SDL_Window* window;

	public:
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();

		void run();
		void stop();
	};
}

#endif