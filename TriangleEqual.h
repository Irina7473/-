#pragma once
#include "Triangle.h"

class TriangleEqual : public Triangle
{
public:
	TriangleEqual();
	TriangleEqual(Color color, double side1);
	~TriangleEqual() {}

	double height()const;
	double getarea()const;
	double getperimetr()const;
	void draw()const;
};

