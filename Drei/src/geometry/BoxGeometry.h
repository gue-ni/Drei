#pragma once

#include "Geometry.h"

class BoxGeometry : public Geometry 
{
public: 
	BoxGeometry();
	BoxGeometry(float width, float height, float depth);
	virtual void draw() override;
};

