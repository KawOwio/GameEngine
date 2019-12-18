#pragma once

#ifndef _CORE_H_
#define _CORE_H_

#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include <rend/rend.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

namespace engine
{
	class Environment;
	class Entity;
	class Keyboard;
	class Renderer;
	class Resources;
	class Camera;

	class Core
	{
	private:
		friend class Camera;
		std::shared_ptr<Environment> environemnt;
		std::shared_ptr<Resources> resources;
		std::shared_ptr<rend::Context> context;
		std::shared_ptr<Renderer> renderer;
		std::shared_ptr<Keyboard> keyboard;
		std::vector<std::shared_ptr<Entity>> entities;

		std::weak_ptr<Camera> camera;
		std::weak_ptr<Core> self;

		bool running;

		SDL_Window* window;

	public:
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();

		void run();
		void stop();

		SDL_Window* getWindow();

		std::shared_ptr<rend::Context> getContext();
		std::shared_ptr<Resources> getResources();
		std::shared_ptr<Camera> getCamera();
	};
}
#endif