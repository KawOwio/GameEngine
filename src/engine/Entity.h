#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <memory>
#include <vector>

namespace engine
{
	class Component;
	class Core;

	class Entity
	{
	private:
		friend class Core;

		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		std::weak_ptr<Entity> self;

	public:
		void tick();
		void display();

		std::shared_ptr<Core> getCore();

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

		template<typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;
			components.push_back(rtn);
			rtn->onInit();
			return rtn;
		}

		template<typename T, typename A>
		std::shared_ptr<T> addComponent(A _a)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a);
			rtn->entity = self;
			components.push_back(rtn);
			rtn->onInit(_a);
			return rtn;
		}

		template<typename T, typename A, typename B>
		std::shared_ptr<T> addComponent(A _a, B _b)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b);
			rtn->entity = self;
			components.push_back(rtn);
			rtn->onInit(_a, _b);
			return rtn;
		}

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