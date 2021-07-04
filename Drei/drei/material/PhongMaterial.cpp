#include "PhongMaterial.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>


namespace DREI {
	PhongMaterial::PhongMaterial(MaterialOptions *options) : DREI::Material(options)
	{
		std::string vertex =
			"#version 330 core\n"
			"layout(location = 0) in vec3 aPos;\n"
			"layout(location = 1) in vec3 aNormal;\n"
			"out vec3 FragPos;\n"
			"out vec3 Normal;\n"
			"uniform mat4 model;\n"
			"uniform mat4 view;\n"
			"uniform mat4 projection;\n"
			"void main()\n"
			"{\n"
			"	FragPos = vec3(model * vec4(aPos, 1.0));\n"
			"	Normal = mat3(transpose(inverse(model))) * aNormal;\n"
			"	gl_Position = projection * view * vec4(FragPos, 1.0);\n"
			"}\0";

		std::string fragment =
			"#version 330 core\n"
			"out vec4 FragColor;\n"
			"in vec3 Normal;\n"
			"in vec3 FragPos;\n"
			"uniform vec3 lightPos;\n"
			"uniform vec3 viewPos;\n"
			"uniform vec3 lightColor;\n"
			"uniform vec3 objectColor;\n"
			"void main()\n"
			"{\n"
			"	float ambientStrength = 0.7;\n"
			"	vec3 ambient = ambientStrength * lightColor;\n"
			"	vec3 norm = normalize(Normal);\n"
			"	vec3 lightDir = normalize(lightPos - FragPos);\n"
			"	float diff = max(dot(norm, lightDir), 0.0);\n"
			"	vec3 diffuse = diff * lightColor;\n"
			"	float specularStrength = 0.5;\n"
			"	vec3 viewDir = normalize(viewPos - FragPos);\n"
			"	vec3 reflectDir = reflect(-lightDir, norm);\n"
			"	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);\n"
			"	vec3 specular = specularStrength * spec * lightColor;\n"
			"	vec3 result = (ambient + diffuse + specular) * objectColor;\n"
			"	//vec3 result = (ambient) * objectColor;\n"
			"	FragColor = vec4(result, 1.0);\n"
			"}\0";

		shader = createShader(vertex, fragment);
		std::cout << "shader=" << shader << std::endl;
	}

	void PhongMaterial::draw(DREI::Camera* camera, DREI::Object3D* object)
	{
		glm::vec3 coord = camera->position;

		glUseProgram(shader);
		glUniformMatrix4fv(glGetUniformLocation(shader, "view"), 1, GL_FALSE, &camera->worldTransform[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, GL_FALSE, &camera->projection[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shader, "model"), 1, GL_FALSE, &object->worldTransform[0][0]);
		
		glUniform3f(glGetUniformLocation(shader, "objectColor"), color.x, color.y, color.z);
		glUniform3f(glGetUniformLocation(shader, "viewPos"), coord.x, coord.y, coord.z);
		glUniform3f(glGetUniformLocation(shader, "lightColor"), 1.0f, 1.0f, 1.0f);
		glUniform3f(glGetUniformLocation(shader, "lightPos"), 1.0f, 2.0f, 1.0f);
	}
}
