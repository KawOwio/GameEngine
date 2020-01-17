#pragma once

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Component.h"

#include <SDL2/SDL.h>
#include <rend/rend.h>

namespace engine
{
	/// Provides transformation for entities.
	///	###	Example of usage:
	///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
	///	std::shared_ptr<Transform> entityTransform = entityName->addComponent<Transform>();
	///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	/// @see Entity
	class Transform : public Component
	{
	private:
		rend::vec3 position = rend::vec3(0.0f, 0.0f, 0.0f);
		rend::vec3 rotation = rend::vec3(0.0f, 0.0f, 0.0f);
		rend::vec3 scale = rend::vec3(1.0f, 1.0f, 1.0f);
		
	public:
		void onInit();

		/// A function to move an entity.
		/// @param _amount is the amount in x, y and z axis you want to move an entity by.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	entityName->getComponent<Transform>()->translate(amount);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void translate(rend::vec4 _amount);

		/// A function to rotate an entity.
		/// @param _amount is the amount in x, y and z axis you want to rotate an entity by.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	entityName->getComponent<Transform>()->rotate(amount);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void rotate(rend::vec3 _amount);

		/// A function to scale an entity.
		/// @param _amount is the amount in x, y and z axis you want to scale an entity by.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	entityName->getComponent<Transform>()->scaleFunction(amount);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void scaleFunction(rend::vec3 _amount);


		/// A function to set position of an entity.
		/// @param _position is the coordinates where you want to place your entity.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	entityName->getComponent<Transform>()->setPosition(position);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void setPosition(rend::vec3 _position);

		/// A function to set rotation of an entity.
		/// @param _rotation is the x, y and z values of entitie's rotation.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	entityName->getComponent<Transform>()->setRotation(rotation);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void setRotation(rend::vec3 _rotation);

		/// A function to set scale of an entity.
		/// @param _rotation is the x, y and z values of entitie's scale.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	entityName->getComponent<Transform>()->setScale(scale);
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void setScale(rend::vec3 _scale);


		/// A function to get a model matrix of an entity.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	rend::mat4 rtn = rend::inverse(getTransform()->getModel());
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		rend::mat4 getModel();


		/// A function to get a current position of an entity.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	rend::vec3 position = entityName->getTransform()->getPosition();
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		rend::vec3 getPosition();

		/// A function to get a current rotation of an entity.
		///	###	Example of usage:
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
		///	rend::vec3 rotation = entityName->getTransform()->getRotation();
		///	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		rend::vec3 getRotation();
	};
}
#endif // !_TRANSFORM_H_