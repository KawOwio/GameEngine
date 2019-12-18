#pragma once

#ifndef _MESH_H_
#define _MESH_H_

#include "Resource.h"

#include <rend/rend.h>

namespace engine
{
	class Core;
	class Renderer;

	class Mesh : public Resource
	{
	private:
		friend class Renderer;
		std::shared_ptr<rend::Mesh> myMesh;

	public:
		void load(std::string _path);
	};
}

#endif // !_MESH_H_