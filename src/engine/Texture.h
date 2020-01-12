#pragma once

#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "Resource.h"

#include <rend/rend.h>

namespace engine
{
	class Core;
	class Renderer;

	class Texture : public Resource
	{
	private:
		friend class Renderer;
		std::shared_ptr<rend::Texture> myTexture;

	public:
		void load(std::string _path);
	};
}

#endif // !_TEXTURE_H_#pragma once
