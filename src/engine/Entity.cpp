#include "Component.h"
#include "Entity.h"

namespace engine
{
	void Entity::tick()
	{
		for (auto it = components.begin(); it != components.end(); it++)
		{
			(*it)->onTick();
		}
	}

	void Entity::display()
	{
		for (auto it = components.begin(); it != components.end(); it++)
		{
			(*it)->onDisplay();
		}
	}

	std::shared_ptr<Core> Entity::getCore()
	{
		return core.lock();
	}

	template<typename T>
	std::shared_ptr<T> Entity::addComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		components.push_back(rtn);
		rtn->onInit();
		return rtn;
	}

	template<typename T, typename A>
	std::shared_ptr<T> Entity::addComponent(A _a)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(_a);
		components.push_back(rtn);
		rtn->onInit(_a);
		return rtn;
	}

	template<typename T, typename A, typename B>
	std::shared_ptr<T> Entity::addComponent(A _a, B _b)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b);
		components.push_back(rtn);
		rtn->onInit(_a, _b);
		return rtn;
	}

	template<typename T, typename A, typename B, typename C>
	std::shared_ptr<T> Entity::addComponent(A _a, B _b, C _c)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b, _c);
		components.push_back(rtn);
		rtn->onInit(_a, _b, _c);
		return rtn;
	}
}