#include "Renderer.h"

#include <iostream>

namespace DREI {

	int Renderer::init() {
		if (!glfwInit())
			return -1;

		window = glfwCreateWindow(window_width, window_height, "Example", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK) {
			std::cout << "Error!" << std::endl;
			return -1;
		}

		std::cout << glGetString(GL_VERSION) << std::endl;
		return 0;
	}

	Renderer::~Renderer() {
		glfwTerminate();
		std::cout << "TERMINATE" << std::endl;
	}

	Renderer::Renderer() : Renderer(640, 480) {}

	Renderer::Renderer(int width, int height) : window_width(width), window_height(height)
	{
		if (init() == -1) {
			std::cout << "ERROR" << std::endl;
		}
		std::cout << "INIT" << std::endl;

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	float Renderer::time() {
		return glfwGetTime();
	}

	void Renderer::render(DREI::Scene* scene, DREI::Camera* camera) {
		close = glfwWindowShouldClose(window);

		glClearColor(clear_color.x, clear_color.y, clear_color.z, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		scene->update();
		scene->draw(camera);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
