#pragma once

#include "Material.h"
namespace DREI {
	class PhongMaterial : public DREI::Material
	{
	public:
		glm::vec3 color;

		PhongMaterial();
		PhongMaterial(glm::vec3 color);

		virtual void draw(DREI::Camera* camera, DREI::Object3D* object) override;
	};
}
