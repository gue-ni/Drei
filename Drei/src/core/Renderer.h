#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Scene.h"
#include "Object3D.h"
#include "../camera/Camera.h"
#include "../core/Mesh.h"

class Renderer
{
public:

	int window_width;
	int window_height;

	GLFWwindow* window;
	bool close = false;

	Renderer();
	Renderer(int width, int height);
	~Renderer();

	int init();
	float time();
	void render(Scene* scene, Camera* camera);
};

