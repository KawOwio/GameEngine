#pragma once

#ifndef _COMPONENT_H_ 
#define _COMPONENT_H_

#include <memory>

namespace engine
{
	class Entity;
	class Core;
	class Keyboard;
	class Environemnt;

	class Component
	{
	private:
		std::weak_ptr<Entity> entity;

	public:
		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Environemnt> getEnvironemnt();

		virtual void onInit();
		virtual void onBegin();
		virtual void onTick();
		virtual void onDisplay();
	};
}

#endif