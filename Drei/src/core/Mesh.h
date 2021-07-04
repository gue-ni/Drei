#pragma once

#include "../geometry/Geometry.h"
#include "../material/Material.h"
#include "./Object3D.h"
#include "../camera/Camera.h"

class Mesh : public Object3D
{
public:
	Geometry* geometry;
	Material* material;

	Mesh(Geometry* g, Material* m);

	void draw(Camera* camera);
};

