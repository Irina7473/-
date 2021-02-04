#include "TriangleEqual.h"

TriangleEqual::TriangleEqual() : 
	TriangleEqual(Color(rand() % (12 - 7 + 1) + 7), (rand() % (14 - 4 + 1) + 4)) {}

TriangleEqual::TriangleEqual(Color color, double side1) : 
	Triangle(color, side1, side1, side1)
{cout << this << " - равносторонний треугольник" << endl;}

double  TriangleEqual::height()const
{return getside1() / 2 * sqrt(3);}

double  TriangleEqual::getarea()const
{return pow(getside1(),2) * sqrt(3)/4;}

double  TriangleEqual::getperimetr()const { return getside1()*3; }

void  TriangleEqual::draw()const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, getcolor());
	for (int i = 0; i < height(); i++)
	{
		for (int j = 0; j < getside1(); j++)
		{
			if (i == 0 || i != 0 && j == getside1()/2
				/*|| (i == height()/2 && (j == getside1()/4 || j == getside1()*3/4))
				|| (i == height() / 4 && (j == getside1() / 8 || j == getside1() * 7 / 8))
				|| (i == height() * 3 / 4 && (j == getside1()*3 / 8 || j == getside1()*5 / 8))*/)
				cout << "* ";
			else cout << " ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, Color::defaultColor);

}