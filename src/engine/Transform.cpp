#include "Transform.h"

namespace engine
{
	void Transform::translate(rend::vec3 _amount)
	{
		position += _amount;
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

	glm::mat4 Transform::getModel()
	{
		glm::mat4 rtn = rend::mat4(1.0f);

		rtn = glm::translate(rtn, position);
		rtn = glm::rotate(rtn, rotation.x, rend::vec3(1.0f, 0.0f, 0.0f));
		rtn = glm::rotate(rtn, rotation.y, rend::vec3(0.0f, 1.0f, 0.0f));
		rtn = glm::rotate(rtn, rotation.z, rend::vec3(0.0f, 0.0f, 1.0f));

		rtn = glm::scale(rtn, scale);

		return rtn;
	}
}