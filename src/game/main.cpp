#include <engine/geppy.h>
#include <memory>

using namespace engine;

struct Controls : public Component
{
	std::shared_ptr<Camera> camera;
	std::shared_ptr<Entity> sword;

	void onTick()
	{
		if (getKeyboard()->isKey(SDLK_w))
		{
			camera->getTransform()->translate(rend::vec4(0.0f, 0.0f, -0.1f, 0.0f));
			rend::vec3 tempPos = camera->getTransform()->getPosition();
			//tempPos.x += 0.25f;
			tempPos.z += -1.0f;
			sword->getComponent<Transform>()->setPosition(tempPos);
		}
		if (getKeyboard()->isKey(SDLK_a))
		{
			camera->getTransform()->translate(rend::vec4(-0.1f, 0.0f, 0.0f, 0.0f));
			rend::vec3 tempPos = camera->getTransform()->getPosition();
			//tempPos.x += 0.25f;
			tempPos.z += -1.0f;
			sword->getComponent<Transform>()->setPosition(tempPos);
		}
		if (getKeyboard()->isKey(SDLK_s))
		{
			camera->getTransform()->translate(rend::vec4(0.0f, 0.0f, 0.1f, 0.0f));
			rend::vec3 tempPos = camera->getTransform()->getPosition();
			//tempPos.x += 0.25f;
			tempPos.z += -1.0f;
			sword->getComponent<Transform>()->setPosition(tempPos);
		}
		if (getKeyboard()->isKey(SDLK_d))
		{
			camera->getTransform()->translate(rend::vec4(0.1f, 0.0f, 0.0f, 0.0f));
			rend::vec3 tempPos = camera->getTransform()->getPosition();
			//tempPos.x += 0.25f;
			tempPos.z += -1.0f;
			sword->getComponent<Transform>()->setPosition(tempPos);
		}
		if (getKeyboard()->isMouse())
		{
			rend::vec2 rotation = getKeyboard()->rotateCamera();
			camera->getTransform()->rotate(rend::vec4(0.0f, rotation.x, 0.0f, 1.0f));

			std::cout << "Rotation x: " << camera->getTransform()->getRotation().y << "\n";

			rend::vec3 tempRot = camera->getTransform()->getRotation();
			sword->getComponent<Transform>()->setRotation(rend::vec3(0.0f, tempRot.y, 0.0f));
		}
		if (getKeyboard()->isKey(SDL_BUTTON_LEFT))
		{
			
			//mouse click
		}
	}
};

int main()
{
	//Initialise the engine
	std::shared_ptr<Core> core = Core::initialize();
	//Add camera to entities
	std::shared_ptr<Entity> cameraEntity = core->addEntity();
	std::shared_ptr<Camera> camera = cameraEntity->addComponent<Camera>();
	//std::shared_ptr<Camera> camera = sword->addComponent<Camera>();
	core->setCam(camera);

	//Create objects
	std::shared_ptr<Entity> cat = core->addEntity();
	std::shared_ptr<Entity> map = core->addEntity();
	std::shared_ptr<Entity> sword = core->addEntity();
	std::shared_ptr<Entity> enemy = core->addEntity();

	

	//Add renderers to entities 
	std::shared_ptr<Renderer> catRenderer = cat->addComponent<Renderer>();
	std::shared_ptr<Renderer> mapRenderer = map->addComponent<Renderer>();
	std::shared_ptr<Renderer> swordRenderer = sword->addComponent<Renderer>();
	std::shared_ptr<Renderer> enemyRenderer = enemy->addComponent<Renderer>();

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

	///Loading enemy
	//Load and set model
	std::shared_ptr<Mesh> enemyMesh = core->getResources()->load<Mesh>("../assets/models/dwarf.obj");
	enemyRenderer->setMesh(enemyMesh);
	//Set shader
	enemyRenderer->setMaterial(material);
	//Load and set texture
	std::shared_ptr<Texture> enemyTexture = core->getResources()->load<Texture>("../assets/textures/dwarf.png");
	enemyRenderer->setTexture(enemyTexture);

	//Add colliders
	std::shared_ptr<BoxCollider> catCollider = cat->addComponent<BoxCollider>();
	//std::shared_ptr<BoxCollider> swordCollider = sword->addComponent<BoxCollider>();
	std::shared_ptr<BoxCollider> enemyCollider = enemy->addComponent<BoxCollider>();

	//swordCollider->setTrigger(true);
	
	
	std::shared_ptr<Entity> control = core->addEntity();
	std::shared_ptr<Controls> playerControls = control->addComponent<Controls>();
	playerControls->camera = camera;
	playerControls->sword = sword;

	camera->getTransform()->setPosition(rend::vec3(0.0f, 2.0f, 0.0f));

	cat->getComponent<Transform>()->setPosition(rend::vec3(0.0f, 1.2f, -5.0f));
	cat->getComponent<Transform>()->setScale(rend::vec3(0.5f, 0.5f, 0.5f));

	sword->getComponent<Transform>()->setScale(rend::vec3(0.05f, 0.05f, 0.05f));
	sword->getComponent<Transform>()->setRotation(rend::vec3(1.0f, 0.0f, 0.0f));
	sword->getComponent<Transform>()->setPosition(rend::vec3(0.0f, 2.0f, 0.0f));

	enemy->getComponent<Transform>()->setScale(rend::vec3(15.0f, 15.0f, 15.0f));
	enemyCollider->setSize(rend::vec3(1.2f, 1.2f, 1.2f));
	enemy->getComponent<Transform>()->setPosition(rend::vec3(-10.0f, 0.0f, -5.0f));

	camera->getEntity()->addComponent<BoxCollider>();
	camera->getEntity()->getComponent<BoxCollider>()->setSize(rend::vec3(0.5f, 1.0f, 0.5f));

	//Start the engine's main loop
	core->run();

  return 0;
}