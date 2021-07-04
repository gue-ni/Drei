#pragma once
#include "Material.h"

namespace DREI {
	class PhongMaterial : public Material
	{
	public:

		PhongMaterial(MaterialOptions *options);

		virtual void draw(DREI::Camera* camera, DREI::Object3D* object) override;
	};
}
