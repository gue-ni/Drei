#include "PhongMaterial.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace DREI {
	PhongMaterial::PhongMaterial() : PhongMaterial(glm::vec3(1.0f, 0.0f, 0.0f)) {}

	PhongMaterial::PhongMaterial(glm::vec3 color)
	{
		shader = loadShader("shaders/phong/vertex.txt", "shaders/phong/fragment.txt");
	}

	void PhongMaterial::draw(DREI::Camera* camera, DREI::Object3D* object)
	{
		glm::mat4 mvp = camera->projection * camera->worldTransform * object->worldTransform;
		glm::vec3 pointLightPos(0, 0, 0);
		glm::vec3 directionalLightDir(0, -1, -1);

		glm::vec3 coord = camera->position;

		glUseProgram(shader);
		glUniformMatrix4fv(glGetUniformLocation(shader, "mvp"), 1, GL_FALSE, &mvp[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shader, "view"), 1, GL_FALSE, &camera->worldTransform[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, GL_FALSE, &camera->projection[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shader, "model"), 1, GL_FALSE, &object->worldTransform[0][0]);
		glUniform3f(glGetUniformLocation(shader, "objectColor"), color.x, color.y, color.z);

		glUniform1f(glGetUniformLocation(shader, "ka"), 0.1f);
		glUniform1f(glGetUniformLocation(shader, "kd"), 0.9f);
		glUniform1f(glGetUniformLocation(shader, "ks"), 0.3f);
		glUniform1i(glGetUniformLocation(shader, "alpha"), 10);
		glUniform3f(glGetUniformLocation(shader, "pointLightColor"), 1.0f, 1.0f, 1.0f);
		glUniform3f(glGetUniformLocation(shader, "pointLightPos"), pointLightPos.x, pointLightPos.y, pointLightPos.z);
		glUniform3f(glGetUniformLocation(shader, "dirLightDir"), directionalLightDir.x, directionalLightDir.y, directionalLightDir.z);
		glUniform3f(glGetUniformLocation(shader, "dirLightColor"), 0.8f, 0.8f, 0.8f);
		glUniform3f(glGetUniformLocation(shader, "viewPos"), coord.x, coord.y, coord.z);
	}
}
