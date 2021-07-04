#pragma once

#include "../core/Object3D.h"

#include <glm/glm.hpp>
namespace DREI {
	class Camera : public DREI::Object3D {
	public:
		float fov;
		float width;
		float height;
		float near;
		float far;
		glm::mat4 view;
		glm::mat4 projection;

		Camera(float width, float height, float fov, float near, float far);
	};
}
