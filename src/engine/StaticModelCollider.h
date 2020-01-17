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

	///WIP, not finished
	class StaticModelCollider : public Component
	{
		std::vector<std::shared_ptr<ColliderColumn>> colColumns;
		Extent extent;

		std::sr1::zero_initialized<float> resolution;
		std::sr1::zero_initialized<float> tryStep;
		std::sr1::zero_initialized<float> maxStep;
		std::sr1::zero_initialized<float> tryInc;
		std::sr1::zero_initialized<float> maxInc;
		//std::vector<Face> collision;

		void generateExtent();
		//void addFace(Face _face);

	public:
		void onInit();
		Extent getExtent();

		//bool isColliding(Face& _face, rend::vec3 _position, rend::vec3 _size);
		bool isColliding(rend::vec3 _position, rend::vec3 _size);

		void getColliding(rend::vec3 _position, rend::vec3 _size);

		rend::vec3 getCollisionResponse(rend::vec3 _position, rend::vec3 _size, bool& _solved);
		
	};
}

#endif // !_STATICMESHCOLLIDER_H_