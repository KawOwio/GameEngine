#include "Core.h"
#include "Entity.h"
#include "Resources.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Environment.h"

#include <GL/glew.h>
#include <iostream>

namespace engine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;

		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0)
		{
			throw std::exception();
		}

		//Create window
		rtn->window = SDL_CreateWindow("Happy Little Accidents",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_OPENGL);

		SDL_CaptureMouse(SDL_TRUE);

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
		rtn->keyboard = std::make_shared<Keyboard>();
		rtn->environemnt = std::make_shared<Environment>();

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
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					running = false;
				}
				if (event.type == SDL_KEYDOWN)
				{
					keyboard->keyDown(event.key.keysym.sym);
				}
				if (event.type == SDL_KEYUP)
				{
					keyboard->keyUp(event.key.keysym.sym);
				}
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					keyboard->keyDown(event.button.button);
				}
				if (event.type == SDL_MOUSEBUTTONUP)
				{
					keyboard->keyUp(event.button.button);
				}
				if (event.type == SDL_MOUSEMOTION)
				{
					keyboard->motion(rend::vec2((float)event.motion.x, (float)event.motion.y));
				}
			}
			SDL_WarpMouseInWindow(NULL, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
			glClearColor(0.85f, 0.15f, 0.85f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (auto it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->tick();
				(*it)->display();
			}

			//clear the pressedKeys and releasedKeys

			//sleep off the remaining time 
			float idealTime = 1.0f / 60.0f;
			float deltaTime = environemnt->getDeltaTime();
			if (idealTime > deltaTime)
			{
				SDL_Delay((idealTime - deltaTime) * 1000.0f);
			}

			SDL_GL_SwapWindow(window);
		}
	}

	void Core::stop()
	{
		//smth
		SDL_DestroyWindow(window);
	}

	void Core::setCam(std::shared_ptr<Camera> _cam)
	{
		camera = _cam;
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
		return camera; 
	}

	std::shared_ptr<Keyboard> Core::getKeyboard()
	{
		return keyboard;
	}

	std::shared_ptr<Environment> Core::getEnvironment()
	{
		return environemnt;
	}

	std::vector<std::shared_ptr<Entity>> Core::getEntities()
	{
		return entities;
	}

	std::shared_ptr<GUI> Core::getGui()
	{
		return gui;
	}
}