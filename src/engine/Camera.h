#pragma once

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <rend/rend.h>

#include "Component.h"

namespace engine
{
	///	###	Example of usage:
	///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	///	std::shared_ptr<Camera> entityCamera = entityName->addComponent<Camera>();
	///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// @see Entity
	class Camera : public Component
	{
	public:
		void onInit();

		///	A function that returns a view matrix.
		///	@returns rend::mat4 view;
		rend::mat4 getView();

		///	A function that returns a projection matrix.
		///	@returns rend::mat4 projection;
		rend::mat4 getProjection();
	};
}

#endif // !_CAMERA_H_