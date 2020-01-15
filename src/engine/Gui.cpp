#include "Gui.h"
#include "Resources.h"

namespace engine
{
	void GUI::texture(rend::vec4 _pos, std::shared_ptr<Texture> _texture)
	{
		shader->setUniform("u_Model", rend::scale(rend::mat4(1.0f), rend::vec3(100.0f, 100.0f, 1.0f)));
		shader->setUniform("u_Projection", rend::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f));
		shader->setMesh(mesh);
		shader->render();
	}
}