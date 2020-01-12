#pragma once
#ifndef _STATICMESHCOLLIDER_H_
#define _STATISMESHCOLLIDER_H_

#include "Component.h"
#include "rend/rend.h"

#include <vector>

namespace engine
{
	struct Extent
	{
		rend::vec3 max;
		rend::vec3 min;
	};

	struct ColliderColumn
	{
		rend::vec3 position;
		rend::vec3 size;
		//std::vector<Face> faces;

		bool isColliding(rend::vec3 _position, rend::vec3 _size);

		//void getColliding(rend::vec3 _position, rend::vec3 _size, std::vector<Face>& collisions);
	};

	class StaticModelCollider : public Component
	{
		std::vector<std::shared_ptr<ColliderColumn>> colColumns;
		Extent extent;
		
	};
}

#endif // !_STATICMESHCOLLIDER_H_