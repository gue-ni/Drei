#pragma once

#include "Material.h"

class PhongMaterial : public Material
{
public:
	glm::vec3 color;
	
	PhongMaterial();
	PhongMaterial(glm::vec3 color);

	virtual void draw(Camera* camera, Object3D* object) override;

};

