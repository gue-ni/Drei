#pragma once

#include "Geometry.h"
namespace DREI {
	class BoxGeometry : public DREI::Geometry
	{
	public:
		BoxGeometry();
		BoxGeometry(float width, float height, float depth);
		virtual void draw() override;
	};
}
