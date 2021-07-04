#pragma once

#include "Material.h"

class BasicMaterial : public Material
{
public:
	glm::vec3 color;
	
	BasicMaterial();
	BasicMaterial(glm::vec3 color);

	virtual void draw(Camera* camera, Object3D* object) override;
};

