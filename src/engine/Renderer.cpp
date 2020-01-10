#include "Renderer.h"
#include "Entity.h"
#include "Core.h"
#include "Mesh.h"
#include "Material.h"
#include "Transform.h"
#include "Camera.h"

#include <iostream>

namespace engine
{
	void Renderer::onDisplay()
	{
		material->myShader->setMesh(mesh->myMesh);

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

	std::shared_ptr<Mesh> Renderer::GetMesh()
	{
		return mesh;
	}

	std::shared_ptr<Material> Renderer::GetMaterial()
	{
		return material;
	}
}