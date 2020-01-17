#pragma once

#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include <vector>
#include <iostream>

#include "Resource.h"

namespace engine
{
	class Core;

	class Resources
	{
	private:
		friend class Core;
		std::vector<std::shared_ptr<Resource>> resources;
		std::weak_ptr<Core> core;

	public:

		///	A template function to load a specific file.
		/// Pass a file type name in <> that you wish to retrive.
		/// Possible <> type names are: Texture, Material, Mesh.
		/// @param _path is a path to a model/texture/shader
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	std::shared_ptr<Mesh> entityMesh = core->getResources()->Load<Mesh>(path);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		template <typename T>
		std::shared_ptr<T> load(std::string _path)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			resources.push_back(rtn);
			rtn->core = core;
			rtn->load(_path);
			return rtn;
		}
	};
}

#endif // !_RESOURCES_H_