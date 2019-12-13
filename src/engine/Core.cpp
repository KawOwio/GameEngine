#include "Core.h"
#include "Entity.h"
#include "Renderer.h"
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

		rtn->window = SDL_CreateWindow("Lab 4 - Architecture",
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
		
		return rtn;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		entities.push_back(rtn);
		rtn->self = rtn;
		return rtn;
	}

	void Core::run()
	{
		while (running)
		{
			for (auto it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->tick();
			}

			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (auto it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->display();
			}
			
			SDL_GL_SwapWindow(window);
		}
	}

	void Core::stop()
	{
		//smth
	}
}