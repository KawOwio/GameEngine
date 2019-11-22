#include "Core.h"
#include "Entity.h"

namespace engine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;
		return rtn;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		entities.push_back(rtn);
		rtn->self = rtn;
		return rtn;
	}

	void Core::run()
	{
		while (running)
		{
			for (auto it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->tick();
			}

			for (auto it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->display();
			}
		}
	}

	void Core::stop()
	{
		//smth
	}
}