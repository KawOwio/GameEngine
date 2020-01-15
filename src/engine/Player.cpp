#include "Player.h"
#include "Resources.h"
#include "Gui.h"
#include "Core.h"

namespace engine
{
	void Player::onInit()
	{
		logo = getCore()->getResources()->load<Texture>("../assets/img/dog.png");
	}

	void Player::onGui()
	{
		getCore()->getGui()->texture(rend::vec4(10, 10, 100, 100), logo);
	}
}