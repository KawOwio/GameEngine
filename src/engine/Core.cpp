#include "Core.h"
#include "Entity.h"
#include "Resources.h"
#include "Transform.h"

#include <GL/glew.h>

namespace engine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::exception();
		}

		//Create window
		rtn->window = SDL_CreateWindow("Happy Little Accidents",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!SDL_GL_CreateContext(rtn->window))
		{
			throw std::exception();
		}

		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		rtn->context = rend::Context::initialize();
		rtn->resources = std::make_shared<Resources>();
		rtn->resources->core = rtn;

		return rtn;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		entities.push_back(rtn);
		rtn->core = self;
		rtn->self = rtn;

		rtn->addComponent<Transform>();

		return rtn;
	}

	void Core::run()
	{
		running = true;
		while (running)
		{
			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (auto it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->tick();
				(*it)->display();
			}

			SDL_GL_SwapWindow(window);
		}
	}

	void Core::stop()
	{
		//smth
	}

	SDL_Window* Core::getWindow()
	{
		return window;
	}

	std::shared_ptr<rend::Context> Core::getContext()
	{
		return context;
	}

	std::shared_ptr<Resources> Core::getResources()
	{
		return resources;
	}

	std::shared_ptr<Camera> Core::getCamera()
	{
		return camera.lock();
	}
}