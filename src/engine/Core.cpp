#include "Core.h"

namespace engine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		return rtn;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> newEntity = std::make_shared<Entity>();
		entities.push_back(newEntity);
		return newEntity;
	}

	void Core::start()
	{
		//smth
	}

	void Core::stop()
	{
		//smth
	}
}