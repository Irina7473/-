#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class Fraction; //класс для дробей
//перегрузка операторов
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);


class Fraction  //создание класса для дробей
{
	int FInt;  //целая часть
	int FNum;  //числитель
	int FDen;  //знаменатель
	bool datavalid(int I, int N, int D);   //проверка данных 
public:
	//конструкторы
	Fraction() : Fraction{ 0, 0, 1 } {} //по умолчанию
	Fraction(int I, int N, int D); //дробь с целой частью
	Fraction(int N, int D) : FInt{ 0 }, FNum{ N } {FDen = D ? D : 1;} //дробь без целой части
	Fraction(int I) : FInt{ I }, FNum{ 0 }, FDen{ 1 } {}  //целое число
	Fraction(const string& str);  // инициализация из строки
	Fraction(const Fraction& other);  //копирование

	//геттеры, сеттеры
	int getFInt()const { return FInt; }
	int getFNum()const { return FNum; }
	int getFDen()const { return FDen; }
	void setFInt(int I) { FInt = I; }
	void setFNum(int N) { FNum = N; }
	void setFDen(int D) { FDen = D ? D : 1; } //с проверкой на нулевой знаменатель

	Fraction reduce(); //сокращение дроби
	Fraction& proper(); //преобразование дроби в правильную
	Fraction& improper(); //преобразование дроби в неправильную

	bool operator>(int X);   // сравнение дроби с целым числом

	//перегрузка операторов присваивания
	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(const Fraction& other) { return *this = *this + other; }
	Fraction& operator-=(const Fraction& other)	{ return *this = *this - other;	}
	Fraction& operator*=(const Fraction& other) { return *this = *this * other; }
	Fraction& operator/=(const Fraction& other) { return *this = *this / other; }

};

int findgcd(int x, int y); //наибольший общий делитель, используется при сокращении дробей
int findlcm(int x, int y); /*наименьшее общее кратное, 
						   используется для приведения к общему знаменателю, 
						   но мб проще общий знаменатель находить перемножением знаменателей, 
						   тк все равно потом сокращаем дробь */
ostream& operator<<(ostream& os, const Fraction& fract);  //вывод в консоль
istream& operator>>(istream& is, const Fraction& fract);  //ввод из консоли не получился пока
//перегрузка операторов сравнения
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
//bool operator>(const Fraction& left, const Fraction& right);  //вариант 1
bool operator>(Fraction& left, Fraction& right);   //вариант 2
bool operator<(Fraction& left, Fraction& right);   //вариант 2
bool operator>=(Fraction& left, Fraction& right);   //вариант 2
bool operator<=(Fraction& left, Fraction& right);   //вариант 2