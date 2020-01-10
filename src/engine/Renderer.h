#pragma once

#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <SDL2/SDL.h>
#include <rend/rend.h>

#include "Component.h"

namespace engine
{
	class Mesh;
	class Material;

	class Renderer : public Component
	{
	public:
		//~Renderer();
		void onInit();
		void onDisplay();

		void setMaterial(std::shared_ptr<Material> _material);
		void setMesh(std::shared_ptr<Mesh> _mesh);

		std::shared_ptr<Material> GetMaterial();
		std::shared_ptr<Mesh> GetMesh();

	private:
		SDL_Window *window;

		std::shared_ptr<rend::Context> context;
		std::shared_ptr<Material> material;
		std::shared_ptr<Mesh> mesh;
	};
}

#endif // !_RENDERER_H_