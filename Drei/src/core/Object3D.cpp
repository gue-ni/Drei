#include "Object3D.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

int Object3D::number = 0;

Object3D::Object3D()
	: id(Object3D::number++),
	transform(glm::mat4(1.0f)),
	worldTransform(glm::mat4(1.0f)),
	scale(glm::vec3(1.0f)),
	position(glm::vec3(0.0f)),
	rotation(glm::vec3(0.0f)),
	needsUpdate(true)
{}

void Object3D::add(Object3D* child)
{
	child->parent = this;
	children.push_back(child);
}

void Object3D::draw(Camera* camera)
{
	for (auto& child : children) {
		child->draw(camera);
	}
}

void Object3D::updateMatrix()
{
	glm::mat4 T = glm::translate(glm::mat4(1.0f), position);

	glm::mat4 S = glm::scale(glm::mat4(1.0f), scale);

	glm::mat4 R = glm::mat4(1.0f);
	R = glm::rotate(R, rotation.x, glm::vec3(1.0, 0.0, 0.0));
	R = glm::rotate(R, rotation.y, glm::vec3(0.0, 1.0, 0.0));
	R = glm::rotate(R, rotation.z, glm::vec3(0.0, 0.0, 1.0));

	transform = T * R * S;

	if (parent) {
		worldTransform = parent->worldTransform * transform;
	}
	else {
		worldTransform = transform;
	}
}

void Object3D::update()
{
	if (needsUpdate) {
		updateMatrix();
	}

	for (Object3D* child : children) {
		child->update();
	}
}

