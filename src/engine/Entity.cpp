#include "Component.h"
#include "Entity.h"

namespace engine
{
	std::shared_ptr<Core> Entity::getCore()
	{
		return core.lock();
	}

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
}