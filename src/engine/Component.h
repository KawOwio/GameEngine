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
		virtual void onInit();
		virtual void onBegin();
		virtual void onTick();
		virtual void onDisplay();
		virtual void onGui();

		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Transform> getTransform();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Environment> getEnvironment();
	};
}

#endif