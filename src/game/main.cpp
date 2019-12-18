#include <engine/geppy.h>
#include <memory>

using namespace engine;

int main()
{
	//Initialise the engine
	std::shared_ptr<Core> core = Core::initialize();

	//Create a single in-game object
	std::shared_ptr<Entity> entity = core->addEntity();

	//
	std::shared_ptr<Renderer> renderer = entity->addComponent<Renderer>();

	entity->getComponent<Transform>()->setPosition(rend::vec3(0.0f, 0.0f, -10.0f));

	//Load and set model
	std::shared_ptr<Mesh> mesh = core->getResources()->load<Mesh>("../models/curuthers");
	renderer->setMesh(mesh);

	//Load and set shader
	std::shared_ptr<Material> material = core->getResources()->load<Material>("../shaders/shader");
	renderer->setMaterial(material);

	//Add camera to entities
	std::shared_ptr<Entity> cameraEntity = core->addEntity();
	std::shared_ptr<Camera> camera = cameraEntity->addComponent<Camera>();

	//Start the engine's main loop
	core->run();

  return 0;
}