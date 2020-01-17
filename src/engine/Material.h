#pragma once

#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "Resource.h"

#include <rend/rend.h>

namespace engine
{
	class Core;
	class Renderer;

	class Material : public Resource
	{
	private:
		friend class Renderer;
		std::shared_ptr<rend::Shader> myShader;

	public:
		/// A function to load a shader
		/// @see Resources::load()
		void load(std::string _path);
	};
}

#endif // !_MATERIAL_H_