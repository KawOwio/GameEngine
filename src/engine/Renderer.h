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
	class Texture;

	///	###	Example of usage:
	///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	///	std::shared_ptr<Renderer> entityRenderer = entityName->addComponent<Renderer>();
	///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	class Renderer : public Component
	{
	public:
		void onInit();
		void onDisplay();

		///	A function to set a material of a model;
		/// @param _material is a shared pointer to material, created when we load a material.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	entityRenderer->setMaterial(materialName);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		/// @see Resources::load()
		void setMaterial(std::shared_ptr<Material> _material);

		///	A function to set a mesh of a model;
		/// @param _mesh is a shared pointer to mesh, created when we load a mesh.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	entityRenderer->setMesh(meshName);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		/// @see Resources::load()
		void setMesh(std::shared_ptr<Mesh> _mesh);

		///	A function to set a texture of a model;
		/// @param _texture is a shared pointer to a texture, created when we load a texture.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	entityRenderer->setTexture(textureName);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		/// @see Resources::load()
		void setTexture(std::shared_ptr<Texture> _texture);

	private:
		SDL_Window *window;

		std::shared_ptr<rend::Context> context;
		std::shared_ptr<Material> material;
		std::shared_ptr<Mesh> mesh;
		std::shared_ptr<Texture> texture;
	};
}

#endif // !_RENDERER_H_