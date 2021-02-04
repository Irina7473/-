#pragma once
#include "Shape.h"

class Rect : public Shape
{
	double side1;
	double side2;
public:
	double getside1()const { return side1; }
	double getside2()const { return side2; }
	void setside1(double side1) {(side1 >= 0) ? this->side1 = side1 : side1 = 0;}
	void setside2(double side2) {(side2 >= 0) ? this->side2 = side2 : side2 = 0;}

	Rect() : Rect(Color(rand() % (12 - 7 + 1) + 7), (rand() % (10 - 2 + 1) + 2), (rand() % (10 - 2 + 1) + 2))
	{cout << "Создан прямоугольник со сторонами " << side1<<", "<<side2 << endl;}
	Rect(Color color, double side1, double side2) : Shape(color)
	{
		setside1(side1);
		setside2(side2);
	}
	~Rect() {}

	double getarea()const { return side1 * side2; }
	double getperimetr()const { return (side1+side2) *2; }

	void draw()const
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, getcolor());
		for (int i = 0; i < side1; i++)
		{
			for (int j = 0; j < side2; j++)
				cout << "* ";
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, Color::defaultColor);
	}

};
