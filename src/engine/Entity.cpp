#include "Entity.h"

namespace engine
{
	std::shared_ptr<Core> Entity::getCore()
	{
		//return std::shared_ptr<Core>;
	}

	template<typename T>
	std::shared_ptr<T> Entity::addComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>;
		components.push_back(rtn);
		return rtn;
	}

	template<typename T, typename A>
	std::shared_ptr<T> Entity::addComponent(A _a)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(_a);
		components.push_back(rtn);
		return rtn;
	}

	template<typename T, typename A, typename B>
	std::shared_ptr<T> Entity::addComponent(A _a, B _b)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b);
		components.push_back(rtn);
		return rtn;
	}

	template<typename T, typename A, typename B, typename C>
	std::shared_ptr<T> Entity::addComponent(A _a, B _b, C _c)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(_a, _b, _c);
		components.push_back(rtn);
		return rtn;
	}
}