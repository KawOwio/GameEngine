#include <engine/Core.h>
#include <memory>

using namespace engine;

int main()
{
	//Initialise out engine
	std::shared_ptr<Core> core = Core::initialize();

	//Create a single in-game object
	std::shared_ptr<Entity> entity = core->addEntity();

	//Add a simple component to it
	//std::weak_ptr<Sandbox> testScreen = entity->addComponent<Sandbox>();

	//Start the engine's main loop
	core->start();

  return 0;
}