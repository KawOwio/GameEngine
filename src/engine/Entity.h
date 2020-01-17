#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <memory>
#include <vector>

namespace engine
{
	class Component;
	class Core;

	///	###	Example of usage:
	///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	///	std::shared_ptr<Entity> entityName = core->addEntity();
	///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	class Entity
	{
	private:
		friend class Core;

		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		std::weak_ptr<Entity> self;

	public:
		/// A function that runs onTick() function of all components attatched to the entity
		void tick();

		/// A function that runs onDisplay() function of all components attatched to the entity
		void display();

		/// A shortcut function that returns the core
		/// @returns std::shared_ptr<Core> core;
		std::shared_ptr<Core> getCore();

		///	A template function to get a specific component from an entity.
		/// Pass a component name in <> that you wish to retrive.
		///	@returns std::shared_ptr<T> component;
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	entityName->getComponent<BoxCollider>()->...;
		/// std::shared_ptr<Camera> myNewCamera = oldCamera->getComponent<Camera>();
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		template<typename T>
		std::shared_ptr<T> getComponent()
		{
			for (auto it = components.begin(); it != components.end(); it++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);
				if (*it && rtn != NULL)
				{
					return rtn;
				}
			}
		}

		///	A template function to check if an entity has a specific component.
		/// Pass a component name in <> that you wish to retrive.
		///	@returns true or false depending on the components of the entity;
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	if(entityName->checkComponent<BoxCollider>() == true)
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		template<typename T>
		bool checkComponent()
		{
			for (auto it = components.begin(); it != components.end(); it++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);
				if (*it == rtn)
				{
					return true;
				}
			}
			return false;
		}

		///	A template function to add a component to an entity.
		/// Possible to pass up to 3 parametrs
		///	@returns std::shared_ptr<T> componentName;
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	std::shared_ptr<Renderer> entityRenderer = entityName->addComponent();
		/// std::shared_ptr<Camera> entityCamera = entityName->addComponent(rend::vec3 position, rend::vec3 rotation);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		template<typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;
			components.push_back(rtn);
			rtn->onInit();
			return rtn;
		}

		/// A template function to add a component with one parameter to an entity.
		/// @see std::shared_ptr<T> addComponent()
		template<typename T, typename A>
		std::shared_ptr<T> addComponent(A _a)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a);
			rtn->entity = self;
			components.push_back(rtn);
			rtn->onInit(_a);
			return rtn;
		}

		/// A template function to add a component with two parameters to an entity.
		/// @see std::shared_ptr<T> addComponent()
		template<typename T, typename A, typename B>
		std::shared_ptr<T> addComponent(A _a, B _b)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b);
			rtn->entity = self;
			components.push_back(rtn);
			rtn->onInit(_a, _b);
			return rtn;
		}

		/// A template function to add a component with three parameters to an entity.
		/// @see std::shared_ptr<T> addComponent()
		template<typename T, typename A, typename B, typename C>
		std::shared_ptr<T> addComponent(A _a, B b, C _c)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b, _c);
			rtn->entity = self;
			components.push_back(rtn);
			rtn->onInit(_a, _b, _c);
			return rtn;
		}
	};
}

#endif