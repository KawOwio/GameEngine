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
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		std::weak_ptr<Entity> self;

	public:
		void tick();
		void display();

		std::shared_ptr<Core> getCore();

		template<typename T>
		std::shared_ptr<T> addComponent();

		template<typename T, typename A>
		std::shared_ptr<T> addComponent(A _a);

		template<typename T, typename A, typename B>
		std::shared_ptr<T> addComponent(A _a, B _b);

		template<typename T, typename A, typename B, typename C>
		std::shared_ptr<T> addComponent(A _a, B b, C _c);
	};
}

#endif