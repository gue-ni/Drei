#pragma once

#include <vector>
#include <glm/glm.hpp>

class Camera;

class Object3D 
{
public:

	int id;

	glm::mat4 transform;
	glm::mat4 worldTransform;

	glm::vec3 scale;
	glm::vec3 position;
	glm::vec3 rotation;

	bool needsUpdate = true;

	Object3D* parent = nullptr;
	std::vector<Object3D*> children;

	Object3D();

	void update();
	void add(Object3D* child);
	void updateMatrix();

	virtual void draw(Camera* camera);

private:
	static int number;
};

