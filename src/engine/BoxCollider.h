#pragma once

#ifndef _BOXCOLLIDER_H_
#define _BOXCOLLIDER_H_

#include "Component.h"
#include "rend/rend.h"

namespace engine
{
	class BoxCollider : public Component
	{
	public:
		void onInit();

		void setSize(rend::vec3 _size);
		void setOffset(rend::vec3 _size);

	private:
		rend::vec3 size;
		rend::vec3 offset;
		rend::vec3 lastPosition;

		void onTick();
		void collideBox();
		void collideStaticMesh();

		bool isColliding(rend::vec3 _position, rend::vec3 _size);
		rend::vec3 getCollisionResponse(rend::vec3 _position, rend::vec3 _size);
	};
}

#endif // !_BOXCOLLIDER_H_