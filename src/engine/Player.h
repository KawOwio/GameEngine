#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Component.h"

namespace engine
{
	class Texture;

	class Player : public Component
	{
	private:
		std::shared_ptr<Texture> logo;

	public:
		void onInit();
		void onGui();
	};
}

#endif // !_PLAYER_H_