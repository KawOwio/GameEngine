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
		rend::mat4 getView();
		rend::mat4 getProjection();
	};
}

#endif // !_CAMERA_H_