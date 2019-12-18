#include "Renderer.h"
#include "Entity.h"
#include "Core.h"
#include "Mesh.h"
#include "Material.h"
#include "Transform.h"
#include "Camera.h"

#include <iostream>

//const GLchar *vertexAndFragSrc = 
//"\n#ifdef VERTEX\n" \
//"attribute vec3 in_Position;" \
//"attribute vec4 in_Color;" \
//"" \
//"uniform mat4 in_Model;" \
//"" \
//"varying vec4 ex_Color;" \
//"" \
//"void main()" \
//"{" \
//"  gl_Position = in_Model vec4(in_Position, 1.0);" \
//"  ex_Color = in_Color;" \
//"}" \
//""
//"\n#endif\n" \
//"\n#ifdef FRAGMENT\n" \
//"varying vec4 ex_Color;" \
//"void main()" \
//"{" \
//"  gl_FragColor = ex_Color;" \
//"}" \
//"\n#endif\n" \
//"";

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
}