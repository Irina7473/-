#pragma once
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <math.h>
#include "Color.h"
using namespace std;

class Shape
{
	Color color;
public:
	Color getcolor()const { return color; }

	Shape(Color color) :color(color)
	{cout << "ShapeConstructor\t"<<this << endl;}
	virtual ~Shape() {};

	virtual double getarea()const = 0;
	virtual double getperimetr()const = 0;
	virtual void draw()const = 0;

};

