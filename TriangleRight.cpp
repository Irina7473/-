#include "TriangleRight.h"

TriangleRight:: TriangleRight() : TriangleRight(Color(rand() % (12 - 7 + 1) + 7), 
	(rand() % (14 - 4 + 1) + 4), (rand() % (14 - 4 + 1) + 4)) {}

TriangleRight::TriangleRight(Color color, double side1, double side2): 
	Triangle (color, side1, side2, sqrt(pow(side1, 2) + pow(side2, 2)))
{cout << this << " - прямоугольный треугольник" << endl;}

double  TriangleRight::getarea()const {return getside1() * getside2() / 2 ;}

double  TriangleRight::getperimetr()const { return getside1() + getside2() + getside3(); }

void  TriangleRight::draw()const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, getcolor());

	for (int i = 0; i < getside1(); i++)
	{
		for (int j = 0; j < getside2(); j++)
		{
			if (i == 0 || j == 0 || (i !=0 && i < getside1() - 1 && j < getside2() -i* (getside2() / getside1() +1)))
				cout << "* ";
			else cout << " ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, Color::defaultColor);

}