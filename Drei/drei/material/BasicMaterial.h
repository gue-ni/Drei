#pragma once
#include "Material.h"

namespace DREI {
	class BasicMaterial : public DREI::Material
	{
	public:

		BasicMaterial(MaterialOptions *options);

		virtual void draw(DREI::Camera* camera, DREI::Object3D* object) override;
	};
}
