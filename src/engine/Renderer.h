#pragma once

#ifndef _RENDERER_H_
#define _RENDERER_H_


#include <SDL2/SDL.h>

#include "Component.h"
#include "rend/rend.h"

namespace engine
{
	class Mesh;

	class Renderer : public Component
	{
	public:
		//~Renderer();
		void onInit();
		void onDisplay();

	private:
		//SDL_Window *window;

		//GLuint programId;
		//GLuint vboId;
		//GLuint vaoId;

		std::shared_ptr<rend::Buffer> buffer;
		std::shared_ptr<rend::Context> context;
		std::shared_ptr<rend::Shader> shader;

		std::weak_ptr<Mesh> mesh;
		//std::shared_ptr<Material> material;
	};
}

#endif // !_RENDERER_H_