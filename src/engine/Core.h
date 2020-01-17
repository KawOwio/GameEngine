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
		std::shared_ptr<Environment> environment;
		std::shared_ptr<Resources> resources;
		std::shared_ptr<rend::Context> context;
		std::shared_ptr<Keyboard> keyboard;
		std::shared_ptr<Camera> camera;

		std::vector<std::shared_ptr<Entity>> entities;

		std::weak_ptr<Core> self;

		bool running;

		SDL_Window* window;

	public:
		///	A function to initialise the engine. Call from the main.cpp of your game.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	std::shared_ptr<Core> core = Core::initialize();	//Initialise the core
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		static std::shared_ptr<Core> initialize();

		///	A function to add an entity to the vector of entities.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	std::shared_ptr<Entity> entityName = core->addEntity();	//Add the entity entityName to the vector of entities
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		std::shared_ptr<Entity> addEntity();

		///	A function to start the main loop. Call it after everything has been initialised.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	core->run();	//Start the main loop
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void run();
		void stop(); /*!< A function to stop the main loop*/

		///	A function to set the current camera.
		///	@param _cam Is a shared pointer of a camera
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	core->setCamera(cameraName);	//Set the main camera
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void setCamera(std::shared_ptr<Camera> _cam);

		///	A function that returns a pointer to SDL window.
		///	@returns SDL_Window* window
		SDL_Window* getWindow();

		/// A function that returns context.
		///	@returns std::shared_ptr<rend::Context> context;
		std::shared_ptr<rend::Context> getContext();

		///	A function that returns resources.
		///	@returns std::shared_ptr<Resources> resources;
		std::shared_ptr<Resources> getResources();

		///	A function to set the current camera.
		///	@returns std::shared_ptr<Camera> camera;
		std::shared_ptr<Camera> getCamera();

		///	A function that returns both mouse and keyboard inputs.
		///	@returns std::shared_ptr<Keyboard> keyboard;
		std::shared_ptr<Keyboard> getKeyboard();

		///	A function that returns environment. Used for delta time.
		///	@returns std::shared_ptr<Environment> environment;
		std::shared_ptr<Environment> getEnvironment();

		///	A function that returns a vector of all currently active entities
		///	@returns std::vector<std::shared_ptr<Entity>> entities;
		std::vector<std::shared_ptr<Entity>> getEntities();
	};
}
#endif