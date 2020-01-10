#pragma once

#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <iostream>

namespace engine
{
	class Resources;
	class Core;

	class Resource
	{
	private:
		friend class Resources;
		std::string path;

	protected:
		std::weak_ptr<Core> core;
	};
}

#endif // !_RESOURCE_H_