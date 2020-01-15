#include "Transform.h"

namespace engine
{
	void Transform::onInit()
	{
		position = rend::vec3(0.0f, 0.0f, 0.0f);
		rotation = rend::vec3(0.0f, 0.0f, 0.0f);
		scale = rend::vec3(1.0f, 1.0f, 1.0f);
	}

	void Transform::onTick()
	{
		
	}

	void Transform::translate(rend::vec4 _amount)
	{
		rend::mat4 model = getModel();
		rend::vec3 moveAmount = model * _amount;
		position += moveAmount;
		//position += _amount;
	}

	void Transform::rotate(rend::vec3 _amount)
	{
		rotation += _amount;
	}

	void Transform::scaleFunction(rend::vec3 _amount)
	{
		scale += _amount;
	}

	void Transform::setPosition(rend::vec3 _position)
	{
		position = _position;
	}

	void Transform::setRotation(rend::vec3 _rotation)
	{
		rotation = _rotation;
	}

	void Transform::setScale(rend::vec3 _scale)
	{
		scale = _scale;
	}

	rend::mat4 Transform::getModel()
	{
		rend::mat4 rtn = rend::mat4(1.0f);

		rtn = rend::translate(rtn, position);
		rtn = rend::rotate(rtn, rotation.x, rend::vec3(1.0f, 0.0f, 0.0f));
		rtn = rend::rotate(rtn, rotation.y, rend::vec3(0.0f, 1.0f, 0.0f));
		rtn = rend::rotate(rtn, rotation.z, rend::vec3(0.0f, 0.0f, 1.0f));

		rtn = glm::scale(rtn, scale);

		return rtn;
	}

	rend::vec3 Transform::getPosition()
	{
		return position;
	}

	rend::vec3 Transform::getRotation()
	{
		return rotation;
	}
}