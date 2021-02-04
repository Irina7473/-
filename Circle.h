#pragma once
#include "Shape.h"

class Circle : public Shape
{
	double radius;
public:
	double getradius()const { return radius; }
	void setradius(double radius) {(radius >= 0)? this->radius = radius : radius = 0;}

	Circle() : Circle(Color(rand() % (12 - 7 + 1) + 7), (rand() % (8 - 2 + 1) + 2))
	{cout << "Создан круг радиусом " << radius << endl;}
	Circle(Color color, double radius) : Shape(color) {setradius(radius);}
	~Circle() {}

	double getarea()const { return (radius* radius*3.14); }
	double getperimetr()const { return (radius*2*3.14); }

	void draw()const 
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, getcolor());
		for (int i = 0; i < radius*2; i++)
		{
			for (int j = 0; j < (radius * 4 - 3); j++)
			{
				if (((i == 0 || i == radius * 2 - 1) && j > (radius) && j < (radius * 3 - 4))
					|| (i < radius && j >= (radius - i - 1) && j < (radius * 3 - 2 + i))
					|| (i >= radius && j >= abs((radius - i)) && j < (radius * 4 - i)))
					cout << "*";
				else cout << " ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, Color::defaultColor);
	}

};
