#include "Camera.h"
#include "Entity.h"
#include "Transform.h"

namespace engine
{
	void Camera::onInit()
	{
		getCore()->camera = getEntity()->getComponent<Camera>();
	}

	glm::mat4 Camera::getView()
	{
		glm::mat4 rtn = glm::perspective(glm::radians(90.f), 1.0f, 0.01f, 100.0f);
		return rtn;
	}

	glm::mat4 Camera::getProjection()
	{
		glm::mat4 rtn = glm::inverse(getTransform()->getModel());
		return rtn;
	}
}