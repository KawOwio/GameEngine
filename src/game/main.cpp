#include <engine/geppy.h>
#include <memory>

using namespace engine;

struct Controls : public Component
{
	std::shared_ptr<Camera> camera;

	void onTick()
	{
		if (getKeyboard()->isKey(SDLK_w))
		{
			camera->getTransform()->translate(rend::vec3(0.0f, 0.0f, -0.1f));
		}
		if (getKeyboard()->isKey(SDLK_a))
		{
			camera->getTransform()->translate(rend::vec3(-0.1f, 0.0f, 0.0f));
		}
		if (getKeyboard()->isKey(SDLK_s))
		{
			camera->getTransform()->translate(rend::vec3(0.0f, 0.0f, 0.1f));
		}
		if (getKeyboard()->isKey(SDLK_d))
		{
			camera->getTransform()->translate(rend::vec3(0.1f, 0.0f, 0.0f));
		}

	}
};

int main()
{
	//Initialise the engine
	std::shared_ptr<Core> core = Core::initialize();

	//Create a single in-game object
	std::shared_ptr<Entity> entity = core->addEntity();

	//Add renderer to entities 
	std::shared_ptr<Renderer> renderer = entity->addComponent<Renderer>();

	entity->getComponent<Transform>()->setPosition(rend::vec3(0.0f, 0.0f, -2.0f));

	//Load and set model
	std::shared_ptr<Mesh> mesh = core->getResources()->load<Mesh>("../models/curuthers");
	renderer->setMesh(mesh);

	//Load and set shader
	std::shared_ptr<Material> material = core->getResources()->load<Material>("../shaders/shader");
	renderer->setMaterial(material);

	//Add camera to entities
	std::shared_ptr<Entity> cameraEntity = core->addEntity();
	std::shared_ptr<Camera> camera = cameraEntity->addComponent<Camera>();
	core->SetCam(camera);

	std::shared_ptr<Entity> control = core->addEntity();
	std::shared_ptr<Controls> playerControls = control->addComponent<Controls>();
	playerControls->camera = camera;



	//Start the engine's main loop
	core->run();

  return 0;
}