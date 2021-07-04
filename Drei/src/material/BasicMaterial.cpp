#include "BasicMaterial.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

void BasicMaterial::draw(Camera* camera, Object3D* object)
{
	glm::mat4 mvp = camera->projection * camera->worldTransform * object->worldTransform;

	glUseProgram(shader);
	glUniformMatrix4fv(glGetUniformLocation(shader, "mvp"), 1, GL_FALSE, &mvp[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(shader, "view"), 1, GL_FALSE, &camera->worldTransform[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, GL_FALSE, &camera->projection[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(shader, "model"), 1, GL_FALSE, &object->worldTransform[0][0]);
	glUniform3f(glGetUniformLocation(shader, "objectColor"), color.x, color.y, color.z);
}



BasicMaterial::BasicMaterial(glm::vec3 color) : color(color)
{

	std::string vertex =
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aNormal;\n"
		"out vec3 FragPos;\n"
		"out vec3 Normal;\n"
		"uniform mat4 mvp;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
		"{\n"
		"  	gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
		"}\0";

	std::string fragment =
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec3 Normal;  \n"
		"in vec3 FragPos;\n"
		"uniform vec3 objectColor;\n"
		"void main()\n"
		"{\n"
		"    FragColor = vec4(objectColor, 1.0);"
		"}\0";

	shader = createShader(vertex, fragment);
}

BasicMaterial::BasicMaterial() : BasicMaterial(glm::vec3(0.0f, 1.0f, 0.f)) {}
