#include "Camera.h"
#include "Entity.h"
#include "Transform.h"

namespace engine
{
	void Camera::onInit()
	{
		//getCore()->camera = getEntity()->getComponent<Camera>();
	}

	rend::mat4 Camera::getView()
	{
		rend::mat4 rtn = rend::inverse(getTransform()->getModel());
		return rtn;
	}

	rend::mat4 Camera::getProjection()
	{
		rend::mat4 rtn = rend::perspective(rend::radians(90.0f), 1.0f, 0.01f, 100.0f);
		return rtn;
	}
}