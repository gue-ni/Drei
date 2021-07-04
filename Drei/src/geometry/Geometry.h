#pragma once
class Geometry
{
public:
	unsigned int VBO = -1;
	unsigned int VAO = -1;
	unsigned int EBO = -1;
	virtual void draw() = 0;

}; 