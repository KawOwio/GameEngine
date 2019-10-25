#pragma once

#ifndef _CORE_H_
#define _CORE_H_

#include <memory>
#include <vector>

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
		std::vector<std::shared_ptr<Entity>> entities;
		std::shared_ptr<Keyboard> keyboard;

		bool running;

	public:
		std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();

		void start();
		void stop();
	};
}

#endif