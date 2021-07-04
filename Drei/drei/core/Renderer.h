#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Scene.h"
#include "Object3D.h"
#include "../camera/Camera.h"
#include "../core/Mesh.h"

namespace DREI {
	class Renderer
	{
	public:

		int window_width;
		int window_height;
		glm::vec3 clear_color = glm::vec3(0.0f, 0.0f, 0.0f);

		GLFWwindow* window;
		bool close = false;

		Renderer();
		Renderer(int width, int height);
		~Renderer();

		int init();
		float time();
		void render(DREI::Scene* scene, DREI::Camera* camera);
	};
}
