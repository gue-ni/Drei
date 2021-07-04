#pragma once

#include "../geometry/Geometry.h"
#include "../material/Material.h"
#include "./Object3D.h"
#include "../camera/Camera.h"


namespace DREI {
	class Mesh : public DREI::Object3D
	{
	public:
		DREI::Geometry* geometry;
		DREI::Material* material;

		Mesh(DREI::Geometry* g, DREI::Material* m);

		void draw(DREI::Camera* camera);
	};
}

