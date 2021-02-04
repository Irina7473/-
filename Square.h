#pragma once
#include "Shape.h"

class Square : public Shape
{
	double side;
public:
	double getside()const { return side; }
	void setside(double side) {(side >= 0)? this->side = side : side = 0;}

	Square() : Square(Color(rand() % (12-7+1)+7), (rand() % (10 - 2 + 1) + 2))
	{cout << "Создан квадрат со стороной " << side<< endl;}
	Square(Color color, double side): Shape (color) { setside(side);}
	~Square() {}

	double getarea()const { return side * side; }
	double getperimetr()const { return side * 4; }

	void draw()const 
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, getcolor());
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
				cout << "* ";
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, Color::defaultColor);
	}

};

