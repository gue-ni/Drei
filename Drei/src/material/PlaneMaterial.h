#pragma once

#include "Material.h"

class PlaneMaterial : public Material
{
public:
	PlaneMaterial();
	virtual void draw(Camera* camera, Object3D* object) override;
};

