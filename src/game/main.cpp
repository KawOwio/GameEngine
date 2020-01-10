#include <engine/geppy.h>
#include <memory>

using namespace engine;

struct Controls : public Component
{
	std::shared_ptr<Camera> camera;

	void onTick()
	{
		////fwd vector
		//rend::mat4 model(1.0f);
		//model = rend::rotate(model, glm::radians(getKeyboard()->getYaw() * 0.1f), glm::vec3(0, 1, 0));
		//glm::vec3 fwd = model * rend::vec4(0.0f, 0.0f, -1.0f, 1.0f);

		////right vector
		////model = rend::mat4(1.0f);
		////model = rend::rotate(model, glm::radians(90.0f * 0.1f), glm::vec3(0, 1, 0));
		//glm::vec3 right = model * glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);

		////model = rend::mat4(1.0f);
		////rend::vec3 cameraPosition = camera->getTransform()->getTranslate();
		////model = rend::translate(model, cameraPosition);
		////model = glm::rotate(model, glm::radians(getKeyboard()->getYaw() * 0.1f), glm::vec3(0, 1, 0));
		////model = glm::rotate(model, glm::radians(getKeyboard()->getPitch() * 0.1f), glm::vec3(1, 0, 0));
		//



		if (getKeyboard()->isKey(SDLK_w) || getKeyboard()->isKey(SDL_BUTTON_LEFT))
		{
			camera->getTransform()->translate(rend::vec4(0.0f, 0.0f, -0.1f, 0.0f));
		}
		if (getKeyboard()->isKey(SDLK_a))
		{
			camera->getTransform()->translate(rend::vec4(-0.1f, 0.0f, 0.0f, 0.0f));
		}
		if (getKeyboard()->isKey(SDLK_s))
		{
			camera->getTransform()->translate(rend::vec4(0.0f, 0.0f, 0.1f, 0.0f));
		}
		if (getKeyboard()->isKey(SDLK_d))
		{
			camera->getTransform()->translate(rend::vec4(0.1f, 0.0f, 0.0f, 0.0f));
		}
		if (getKeyboard()->isMouse())
		{
			rend::vec2 rotation = getKeyboard()->rotateCamera();
			camera->getTransform()->rotate(rend::vec4(0.0f, rotation.x, 0.0f, 1.0f));
		}
		//getKeyboard()->motion();

	}
};

struct MouseInput : public Component
{
	std::shared_ptr<Camera> camera;

	void onTick()
	{
		
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

	std::shared_ptr<Entity> mouse = core->addEntity();
	std::shared_ptr<Controls> mouseControls = mouse->addComponent<Controls>();
	mouseControls->camera = camera;

	//Start the engine's main loop
	core->run();

  return 0;
}