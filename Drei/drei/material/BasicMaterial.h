#pragma once

#include "Material.h"
namespace DREI {
	class BasicMaterial : public DREI::Material
	{
	public:
		glm::vec3 color;

		BasicMaterial();
		BasicMaterial(glm::vec3 color);

		virtual void draw(DREI::Camera* camera, DREI::Object3D* object) override;
	};
}
