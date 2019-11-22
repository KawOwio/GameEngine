#pragma once

#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <GL/glew.h>

#include "Component.h"
#include "rend/Mesh.h"

namespace engine
{
	class Mesh;

	class Renderer : public Component
	{
	public:
		~Renderer();
		void onInit();

	private:
		void onDisplay();

		GLuint programId;
		GLuint vboId;
		GLuint vaoId;

		std::weak_ptr<Mesh> mesh;
		//std::shared_ptr<Material> material;
	};
}

#endif // !_RENDERER_H_