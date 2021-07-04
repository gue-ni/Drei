#pragma once
#include "./Geometry.h"

namespace DREI {
	class PlaneGeometry : public DREI::Geometry
	{
	public:
		PlaneGeometry();
		void draw();
	};
}
