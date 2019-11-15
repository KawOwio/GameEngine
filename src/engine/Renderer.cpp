#include "Renderer.h"
#include <iostream>

namespace engine
{
	void Renderer::onDisplay()
	{
		getEntity()->getCore()->addEntity();
	}
}