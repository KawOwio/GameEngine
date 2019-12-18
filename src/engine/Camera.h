#pragma once

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <rend/rend.h>

#include "Component.h"

namespace engine
{
	class Camera : public Component
	{
	public:
		void onInit();
		glm::mat4 getView();
		glm::mat4 getProjection();
	};
}

#endif // !_CAMERA_H_