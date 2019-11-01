#include "Component.h"
#include "Core.h"

namespace engine
{
	void Component::onInit()
	{

	}

	void Component::onBegin()
	{

	}

	void Component::onTick()
	{

	}

	void Component::onDisplay()
	{

	}

	std::shared_ptr<Entity> Component::getEntity()
	{
		return entity.lock();
	}

	std::shared_ptr<Core> Component::getCore()
	{
		return getEntity()->getCore();
	}

	std::shared_ptr<Keyboard> Component::getKeyboard()
	{

	}

	std::shared_ptr<Environemnt> Component::getEnvironemnt()
	{

	}
}