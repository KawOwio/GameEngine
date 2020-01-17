#pragma once

#ifndef _BOXCOLLIDER_H_
#define _BOXCOLLIDER_H_

#include "Component.h"
#include "rend/rend.h"

namespace engine
{
	/// Provides box colliders for entities. Checks for the collision using 3D AABB method.
	///	###	Example of usage:
	///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	///	std::shared_ptr<BoxCollider> entityCollider = entityName->addComponent<BoxCollider>();
	///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// @see Entity
	class BoxCollider : public Component
	{
	public:
		void onInit();

		///	A function to set a size of a box collider.
		/// @param _size A 3D vector the represent size.
		/// Pass (1.0f, 1.0f, 1.0f) if you want box collider be the same size as a model.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	entityName->getComponent<BoxCollider>()->setSize(size);	//Set size of a box collider
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void setSize(rend::vec3 _size);

		///	A function to set an offset of a box collider.
		/// @param _offset A 3D vector the represent offset.
		/// Pass (0.0f, 0.0f, 0.0f) if you want box collider be at the same position as entity.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	entityName->getComponent<BoxCollider>()->setOffset(offset);	//Set offset of a box collider
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void setOffset(rend::vec3 _offset);

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