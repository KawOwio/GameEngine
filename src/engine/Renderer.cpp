#include "Renderer.h"
#include "Entity.h"
#include "Core.h"
#include <iostream>

namespace engine
{
	void Renderer::onDisplay()
	{
		getEntity()->getCore()->addEntity();
	}

	void Renderer::onInit()
	{
		 
	}
}