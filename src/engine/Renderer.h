#pragma once

#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Component.h"

namespace engine
{
	class Renderer : public Component
	{
	private:
		void onDisplay();
	};
}

#endif // !_RENDERER_H_