#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Binary.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Двоичные положительные числа" << endl;


//#define constr check
#ifdef constr check

	Binary B1,B2;
	B1.print();
	cout << B1 << endl;
	int A[] = { 1, 0, 0, 1.05 };
	Binary B3 (sizeof(A)/sizeof(int), A);
	cout << B3 << endl;
	B2 = B3;
	cout<< B2.decconversion()<<endl;
	B2.print();
	Binary B4 (B3);
	B4.print();

	Binary B5(175);
	B5.print();

	int D6;
	cout << "Введите десятичное число" << endl;
	cin >> D6;
	Binary B6(D6);
	B6.print();

#endif constr check

//#define constr check2
#ifdef constr check2
	Binary B7;
	cout << "Введите двоичное число" << endl;
	cin >> B7;
	B7.print();
	
#endif constr check2

//#define arifmetic check
#ifdef arifmetic check

	Binary B1(15), B2(48);
	B1.print();
	B2.print();
	cout << TAB;
	Binary B3 = B1 + B2;
	cout << B3.decconversion() << endl;
	cout << TAB;
	Binary B4 =B2-B1;
	cout << B4.decconversion() << endl;
	cout << (B2 - B1) << endl;
	
#endif arifmetic check

#define multarifmetic check
#ifdef multarifmetic check

	Binary B1(12), B2(3);
	B1.print();
	B2.print();
	cout << TAB;
	Binary B3 = B1 * B2;
	cout << B3.decconversion() << endl;
	cout << TAB;
	cout << TAB;
	Binary B4 = B1 / B2;
	cout << "Результат деления B1 на B2 = "<<B4.decconversion() << endl;

#endif multarifmetic check

//#define boolcheck
#ifdef boolcheck
	Binary B1(6), B2(8);
	B1.print();
	B2.print();
	cout << (B1>B2) << endl;

#endif boolcheck


//#define bitwise operations
#ifdef bitwise operations
	Binary B1(5), B2(36);
	B1.print();
	B1.decconversion();
	B2.print();
	B2.decconversion();
	cout << TAB;
	Binary B3 = B1 & B2;
	B3.decconversion();
	cout << B3 << endl;
	cout << TAB;
	Binary B4 = B1 | B2;
	B4.decconversion();
	cout << B4 << endl;
	cout << TAB;
	Binary B5 = B1 ^ B2;
	B5.decconversion();
	cout << B5 << endl;
	cout << TAB;
	Binary B6 = ~B2;
	B6.decconversion();
	cout << B6 << endl;
	cout << TAB;
#endif bitwise operations

	return 0;
}