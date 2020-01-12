#pragma once

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Component.h"

#include <SDL2/SDL.h>
#include <rend/rend.h>

namespace engine
{
	class Transform : public Component
	{
	private:
		rend::vec3 position = rend::vec3(0.0f, 0.0f, 0.0f);
		rend::vec3 rotation = rend::vec3(0.0f, 0.0f, 0.0f);
		rend::vec3 scale = rend::vec3(1.0f, 1.0f, 1.0f);
		
	public:
		void onInit();
		void onTick();

		void translate(rend::vec4 _amount);
		void rotate(rend::vec3 _amount);
		void scaleFunction(rend::vec3 _amount);

		void setPosition(rend::vec3 _position);
		void setRotation(rend::vec3 _rotation);
		void setScale(rend::vec3 _scale);

		rend::mat4 getModel();

		rend::vec3 getPosition();
	};
}

#endif // !_TRANSFORM_H_