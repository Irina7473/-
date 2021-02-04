#include "Triangle.h"

void Triangle::setside1(double side1)
{(side1 >= 0) ? this->side1 = side1 : this->side1 = 0;}

void Triangle::setside2(double side2)
{(side2 >= 0) ? this->side2 = side2 : this->side2 = 0;}

void Triangle::setside3(double side3)
{
	if (side3 < (side1 + side2))  this->side3 = side3;
	else
	{
		cout << "Каждая сторона треугольника должна быть меньше суммы двух других, генерируем третью сторону " << endl;
		this->side3 = rand() % (int(side1) + int(side2) - 1 - abs(int(side1) - int(side2))) + abs(int(side1) - int(side2)) + 1;
	}
}

Triangle::Triangle() : Triangle(Color(rand() % (12 - 7 + 1) + 7), (rand() % (14 - 4 + 1) + 4),
	(rand() % (14 - 4 + 1) + 4), (rand() % (14 - 4 + 1) + 4)) {}

Triangle::Triangle(Color color, double side1, double side2, double side3) : Shape(color)
{
	setside1(side1);
	setside2(side2);
	setside3(side3);
	cout << this << " - Создан треугольник со сторонами " << this->side1 << ", " << this->side2 << ", " << this->side3 << endl;
}

double  Triangle::maxside()const
{
	double max = side1;
	if (side2 > max) max = side2;
	if (side3 > max) max = side3;
	cout << "Самая длинная сторона " << max << endl;
	return max;
}

double  Triangle::height(double side)const
{
	double p = getperimetr() / 2;
	double H = 2 * sqrt(p * (p - side1) * (p - side2) * (p - side3)) / side;
	cout << "Высота, проведенная к стороне " << side << "=" << H << endl;
	return H;
}
double  Triangle::getarea()const
{
	//return (side1 * height(side1) / 2); //вариант через высоту
	return side1 / 2 * sqrt(abs(pow(side2, 2) - pow(side1, 2))); //вариант через длины сторон
}
double  Triangle::getperimetr()const { return side1 + side2 + side3; }

void  Triangle::draw()const
{
	//для построения треугольника находим высоту к самой длинной его стороне и отрезки, на которые высота ее делит
	double sidemax1, sidemax2, sidemax3;
	sidemax1 = maxside();  //самая длинная сторона
	double H = height(sidemax1); //высота к  самой длинной стороне
	//переопределение сторон в зависимости от максимальной
	if (side1 == sidemax1)
	{
		sidemax2 = side2;
		sidemax3 = side3;
	}
	else if (side2 == sidemax1)
	{
		sidemax2 = side1;
		sidemax3 = side3;
	}
	else
	{
		sidemax2 = side2;
		sidemax3 = side1;
	}
	// отрезки, на которые высота делит самую длинную сторону
	double sidemax12 = sqrt(pow(sidemax2, 2) - pow(H, 2));
	double sidemax13 = sqrt(pow(sidemax3, 2) - pow(H, 2));
	cout << "Высота делит сторону " << sidemax1 << " на - " << sidemax12 << " и " << sidemax13 << endl;
	//теперь можно рисовать
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, getcolor());

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < int(sidemax1); j++)
		{
			if (i == 0 || j == int(sidemax12)
				|| (i == int(H / 2) && (j == (int(sidemax12 / 2) || j == int(sidemax12 + sidemax13 / 2)))
					|| (i == int(H / 4) && (j == int(sidemax12 / 4) || j == int(sidemax12 + sidemax13 * 3 / 4)))
					|| (i == int(H * 3 / 4) && (j == int(sidemax12 * 3 / 4) || j == int(sidemax12 + sidemax13 / 4)))))
				cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, Color::defaultColor);

}