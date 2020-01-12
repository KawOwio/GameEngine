#include <engine/geppy.h>
#include <memory>

using namespace engine;

struct Controls : public Component
{
	std::shared_ptr<Camera> camera;
	std::shared_ptr<Entity> sword;

	void onTick()
	{
		if (getKeyboard()->isKey(SDLK_w) || getKeyboard()->isKey(SDL_BUTTON_LEFT))
		{
			camera->getTransform()->translate(rend::vec4(0.0f, 0.0f, -0.1f, 0.0f));
			sword->getComponent<Transform>()->translate(rend::vec4(0.0f, 0.0f, -0.1f, 0.0f));
		}
		if (getKeyboard()->isKey(SDLK_a))
		{
			camera->getTransform()->translate(rend::vec4(-0.1f, 0.0f, 0.0f, 0.0f));
			sword->getComponent<Transform>()->translate(rend::vec4(-0.1f, 0.0f, 0.0f, 0.0f));
		}
		if (getKeyboard()->isKey(SDLK_s))
		{
			camera->getTransform()->translate(rend::vec4(0.0f, 0.0f, 0.1f, 0.0f));
			sword->getComponent<Transform>()->translate(rend::vec4(0.0f, 0.0f, 0.1f, 0.0f));
		}
		if (getKeyboard()->isKey(SDLK_d))
		{
			camera->getTransform()->translate(rend::vec4(0.1f, 0.0f, 0.0f, 0.0f));
			sword->getComponent<Transform>()->translate(rend::vec4(0.1f, 0.0f, 0.0f, 0.0f));
		}
		if (getKeyboard()->isMouse())
		{
			rend::vec2 rotation = getKeyboard()->rotateCamera();
			camera->getTransform()->rotate(rend::vec4(0.0f, rotation.x, 0.0f, 1.0f));
		}
	}
};

int main()
{
	//Initialise the engine
	std::shared_ptr<Core> core = Core::initialize();

	//Create objects
	std::shared_ptr<Entity> cat = core->addEntity();
	std::shared_ptr<Entity> map = core->addEntity();
	std::shared_ptr<Entity> sword = core->addEntity();

	//Add renderers to entities 
	std::shared_ptr<Renderer> catRenderer = cat->addComponent<Renderer>();
	std::shared_ptr<Renderer> mapRenderer = map->addComponent<Renderer>();
	std::shared_ptr<Renderer> swordRenderer = sword->addComponent<Renderer>();

	//Add colliders
	cat->addComponent<BoxCollider>();
	sword->addComponent<BoxCollider>();
	
	//map->addComponent<anothercollider>();

	///Loading cat
	//Load and set model
	std::shared_ptr<Mesh> catMesh = core->getResources()->load<Mesh>("../assets/models/curuthers.obj");
	catRenderer->setMesh(catMesh);
	//Load and set shader
	std::shared_ptr<Material> material = core->getResources()->load<Material>("../assets/shaders/shader.txt");
	catRenderer->setMaterial(material);
	//Load and set texture
	std::shared_ptr<Texture> catTexture = core->getResources()->load<Texture>("../assets/textures/cat_diffuse.png");
	catRenderer->setTexture(catTexture);

	///Loading map
	//Load and set model
	std::shared_ptr<Mesh> mapMesh = core->getResources()->load<Mesh>("../assets/models/graveyard.obj");
	mapRenderer->setMesh(mapMesh);
	//Set shader
	mapRenderer->setMaterial(material);
	//Load and set texture
	std::shared_ptr<Texture> mapTexture = core->getResources()->load<Texture>("../assets/textures/graveyard.png");
	mapRenderer->setTexture(mapTexture);

	///Loading sword
	//Load and set model
	std::shared_ptr<Mesh> swordMesh = core->getResources()->load<Mesh>("../assets/models/sword.obj");
	swordRenderer->setMesh(swordMesh);
	//Set shader
	swordRenderer->setMaterial(material);
	//Load and set texture
	std::shared_ptr<Texture> swordTexture = core->getResources()->load<Texture>("../assets/textures/sword.png");
	swordRenderer->setTexture(swordTexture);

	//Add camera to entities
	std::shared_ptr<Entity> cameraEntity = core->addEntity();
	std::shared_ptr<Camera> camera = cameraEntity->addComponent<Camera>();
	core->setCam(camera);

	std::shared_ptr<Entity> control = core->addEntity();
	std::shared_ptr<Controls> playerControls = control->addComponent<Controls>();
	playerControls->camera = camera;
	playerControls->sword = sword;

	camera->getTransform()->setPosition(rend::vec3(0.0f, 2.0f, 0.0f));

	cat->getComponent<Transform>()->setPosition(rend::vec3(0.0f, 1.2f, -5.0f));
	cat->getComponent<Transform>()->setScale(rend::vec3(0.5f, 0.5f, 0.5f));

	sword->getComponent<Transform>()->setScale(rend::vec3(0.02f, 0.02f, 0.02f));
	sword->getComponent<Transform>()->setRotation(rend::vec3(3.1f, 0.0f, 0.0f));
	sword->getComponent<Transform>()->setPosition(rend::vec3(0.0f, 2.0f, -1.0f));

	camera->getEntity()->addComponent<BoxCollider>();
	//camera->getEntity()->getComponent<BoxCollider>()->setSize(rend::vec3(2.0f, 2.0f, 2.0f));

	//Start the engine's main loop
	core->run();

  return 0;
}