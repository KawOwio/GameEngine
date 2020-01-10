#include "Component.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Environment.h"

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

	std::shared_ptr<Transform> Component::getTransform()
	{
		return getEntity()->getComponent<Transform>();
	}

	std::shared_ptr<Keyboard> Component::getKeyboard()
	{
		return getCore()->getKeyboard();
	}

	std::shared_ptr<Environment> Component::getEnvironment()
	{
		return getCore()->getEnvironment();
	}
}