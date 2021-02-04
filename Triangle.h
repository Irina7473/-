#pragma once
#include "Shape.h"

class Triangle : public Shape
{
	double side1;
	double side2;
	double side3;

public:
	double getside1()const { return side1; }
	double getside2()const { return side2; }
	double getside3()const { return side3; }
	void setside1(double side1);
	void setside2(double side2);
	void setside3(double side3);

	Triangle();
	Triangle(Color color, double side1, double side2, double side3);
	virtual~Triangle() {}
	
	double maxside()const;
	double height(double side)const;
	double getarea()const;
	double getperimetr()const;
	void draw()const;
	
};
