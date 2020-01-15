#pragma once

#ifndef _GUI_H_
#define _GUI_H_

#include "Resource.h"

#include <memory>
#include <rend/rend.h>

namespace engine
{
	class Mesh;
	class Texture;

	class GUI
	{
	private:
		friend class Core;
		std::shared_ptr<rend::Mesh> mesh;
		std::shared_ptr<rend::Shader> shader;
		
		rend::mat4 projection;

	public:
		void texture(rend::vec4 _pos, std::shared_ptr<Texture> _texture);
	};
}

#endif // !_GUI_H_