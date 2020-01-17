#pragma once

#ifndef _COMPONENT_H_ 
#define _COMPONENT_H_

#include <memory>
#include "Core.h"

namespace engine
{
	class Entity;
	class Core;
	class Keyboard;
	class Environment;
	class Transform;
	class Keyboard;

	class Component
	{
	private:
		friend class Entity;
		std::weak_ptr<Entity> entity;

	public:
		///	A function that automatically calls when you add a component to an entity. 
		virtual void onInit();

		/// A function that automatically calls when the program starts.
		virtual void onBegin();

		/// A function that automatically calls every frams.
		virtual void onTick();

		/// A function that automatically calls when an object is displayed.
		virtual void onDisplay();

		/// A shortcut function that returns an entity that this component is attatched to
		/// @returns std::shared_ptr<Entity> entityName;
		std::shared_ptr<Entity> getEntity();

		/// A shortcut function that returns the core
		/// @returns std::shared_ptr<Core> core;
		std::shared_ptr<Core> getCore();

		/// A shortcut function that returns a Transform of the current entity
		/// @returns std::shared_ptr<Transform> entityTransform;
		std::shared_ptr<Transform> getTransform();

		///	A function that returns both mouse and keyboard inputs from the core.
		///	@returns std::shared_ptr<Keyboard> keyboard;
		std::shared_ptr<Keyboard> getKeyboard();

		///	A function that returns environment from core. Used for delta time.
		///	@returns std::shared_ptr<Environment> environment;
		std::shared_ptr<Environment> getEnvironment();
	};
}

#endif