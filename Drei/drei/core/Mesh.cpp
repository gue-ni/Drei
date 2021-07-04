#include "Mesh.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>

namespace DREI {

	Mesh::Mesh(DREI::Geometry* g, DREI::Material* m) : geometry(g), material(m) {}

	void Mesh::draw(Camera* camera) {

		if (material->wireframe) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}

		material->draw(camera, this);
		geometry->draw();

		for (auto& child : children) {
			child->draw(camera);
		}
	}

}
