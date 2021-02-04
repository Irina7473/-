#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "TriangleEqual.h"
#include "TriangleRight.h"

using namespace std;
#define TAB "------------------------------\n"

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	
	//#define shapecheck
	#ifdef shapecheck
	Square square;
	cout << "Площадь - " << square.getarea() << ", периметр - "<< square.getperimetr () << endl;
	square.draw();
	cout << TAB;
	Rect rect;
	cout << "Площадь - " << rect.getarea() << ", периметр - " << rect.getperimetr () << endl;
	rect.draw();
	cout << TAB;
	Circle circle;
	cout << "Площадь - " << circle.getarea() << ", периметр - " << circle.getperimetr () << endl;
	circle.draw();
	cout << TAB;

	#endif shapecheck

//#define circlecheck
#ifdef circlecheck
	Circle circle7(Color::red, 7);
	circle7.draw();
	Circle circle6(Color::red, 6);
	circle6.draw();
	Circle circle5(Color::red, 5);
	circle5.draw();
	Circle circle4(Color::red, 4);
	circle4.draw();
	Circle circle3(Color::red, 3);
	circle3.draw();
	Circle circle2(Color::red, 2);
	circle2.draw();
#endif circlecheck
	
#define triangleAnycheck
#ifdef triangleAnycheck
	Triangle triangle1(Color::blue, 6, 8, 14);
	cout << "Площадь - " << triangle1.getarea() << ", периметр - " << triangle1.getperimetr() << endl;
	triangle1.draw();
	cout << TAB;
	Triangle triangle;
	cout << "Площадь - " << triangle.getarea() << ", периметр - " << triangle.getperimetr() << endl;
	triangle.draw();
	cout << TAB;
		
#endif triangleAnycheck

#define triangleRightcheck
#ifdef triangleRightcheck
	TriangleRight triangleR1(Color::blue, 9, 6);
	cout << "Площадь - " << triangleR1.getarea() << ", периметр - " << triangleR1.getperimetr() << endl;
	triangleR1.draw();
	cout << TAB;
	TriangleRight triangleR;
	cout << "Площадь - " << triangleR.getarea() << ", периметр - " << triangleR.getperimetr() << endl;
	triangleR.draw();
	cout << TAB;

#endif triangleRightcheck
	
#define triangleEqualcheck
#ifdef triangleEqualcheck
	TriangleEqual triangleE1(Color::red, 7);
	cout << "Площадь - " << triangleE1.getarea() << ", периметр - " << triangleE1.getperimetr() << endl;
	triangleE1.draw();
	cout << TAB;
	TriangleEqual triangleE;
	cout << "Площадь - " << triangleE.getarea() << ", периметр - " << triangleE.getperimetr() << endl;
	triangleE.draw();
	cout << TAB;

#endif triangleEqualcheck



	return 0;
}