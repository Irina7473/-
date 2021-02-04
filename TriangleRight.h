#pragma once
#include "Triangle.h"

class TriangleRight: public Triangle
{
public:
	TriangleRight();
	TriangleRight(Color color, double side1, double side2);
	~TriangleRight() {}

	double getarea()const;
	double getperimetr()const;
	void draw()const;
};

