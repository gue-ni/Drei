#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace DREI {
	Camera::Camera(float width, float height, float fov, float near, float far)
		: width(width), height(height), fov(fov), near(near), far(far)
	{
		projection = glm::perspective(glm::radians(fov), (float)width / (float)height, near, far);
	}
}
