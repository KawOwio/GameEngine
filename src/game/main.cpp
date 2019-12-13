#include <engine/geppy.h>
#include <memory>

using namespace engine;

int main()
{
	//Initialise out engine
	std::shared_ptr<Core> core = Core::initialize();

	//Create a single in-game object
	std::shared_ptr<Entity> entity = core->addEntity();

	std::shared_ptr<Component> component = entity->addComponent<Component>();
	std::shared_ptr<Renderer> renderer = entity->addComponent<Renderer>();

	//Renderer myRenderer;

	renderer->onInit();

	//Start the engine's main loop
	core->run();

  return 0;
}