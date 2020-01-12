#include "Renderer.h"
#include "Entity.h"
#include "Core.h"
#include "Mesh.h"
#include "Material.h"
#include "Transform.h"
#include "Camera.h"
#include "Texture.h"

#include <iostream>

namespace engine
{
	void Renderer::onDisplay()
	{
		material->myShader->setMesh(mesh->myMesh);
		if (texture != NULL)
		{
			mesh->myMesh->setTexture("u_Texture", texture->myTexture);
		}
		

		material->myShader->setUniform("u_Projection", getCore()->getCamera()->getProjection());
		material->myShader->setUniform("u_Model", getEntity()->getComponent<Transform>()->getModel());
		material->myShader->setUniform("u_View", getCore()->getCamera()->getView());

		material->myShader->render();
	}

	void Renderer::onInit()
	{
		window = getCore()->getWindow();
		context = getCore()->getContext();
	}

	void Renderer::setMaterial(std::shared_ptr<Material> _material)
	{
		material = _material;
	}

	void Renderer::setMesh(std::shared_ptr<Mesh> _mesh)
	{
		mesh = _mesh;
	}

	void Renderer::setTexture(std::shared_ptr<Texture> _texture)
	{
		texture = _texture;
	}

	std::shared_ptr<Mesh> Renderer::getMesh()
	{
		return mesh;
	}

	std::shared_ptr<Material> Renderer::getMaterial()
	{
		return material;
	}

	std::shared_ptr<Texture> Renderer::getTexture()
	{
		return texture;
	}
}