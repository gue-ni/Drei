#include "Renderer.h"

#include <iostream>

int Renderer::init() {
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(window_width, window_height, "OpenGL", NULL, NULL);
	//window = glfwCreateWindow(640, 480, "OpenGL", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
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

void Renderer::render(Scene* scene, Camera* camera) {
	close = glfwWindowShouldClose(window);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	scene->update();
	scene->draw(camera);

	glfwSwapBuffers(window);
	glfwPollEvents();
}

