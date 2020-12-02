#include "Fraction.h"

bool Fraction::datavalid(int I, int N, int D)  //проверка данных
{
	if (I < 0 && N>0 && D > 0 || I > 0 && N < 0 && D > 0 || I > 0 && N > 0 && D < 0) return true;
	else
	{
		cout << "Данные введены некорректно, в дроби может быть только одно отрицательное значение" << endl;
		exit(1);
	}
}

Fraction::Fraction(int I, int N, int D) //дробь с целой частью
{
	datavalid(I, N, D);
	FInt = I;
	FNum = N;
	FDen = D ? D : 1;}

Fraction::Fraction(const string& str)  // инициализация из строки
{
	int posI = str.find('_');
	int posN = str.find('/');

	if (posN == string::npos)
		// Если символ "/" не найден - то вся строка является числом 
	{
		FInt = stoi(str);
		FNum = 0;
		FDen = 1;
	}
	else
	{
		if (posI == string::npos) FInt = 0;  //Целая часть = 0 при отсутствии символа "_"
		else FInt = stoi(str.substr(0, posI));  //Целая часть - левая часть до символа "_"
		FNum = stoi(str.substr(posI + 1, posN));  // Числитель - левая часть до символа "/"
		FDen = stoi(str.substr(posN + 1));  // Знаменатель - правая часть после символа "/"
		datavalid(FInt, FNum, FDen);
	}
}

Fraction::Fraction(const Fraction& other)  //копирование
{
	FInt = other.FInt;
	FNum = other.FNum;
	FDen = other.FDen;
}

Fraction Fraction::reduce()  //сокращение дроби
{
/*  не работает этот вариант правильно, 
мне кажется лаконичнее и красивее вариант с нахождением gcd через рекурсию
	int more = FNum;
	int less = FDen;
	for (; less == 0;)
	{
		more = less;
		cout << more << " ";
		less = more % less;
		cout << less << endl;
	}
	
	int gcd = more;
	cout << gcd << endl;*/

	int gcd = findgcd(FNum, FDen);
	FNum /= gcd;
	FDen /= gcd;
	return *this;
}

Fraction& Fraction::proper()  //преобразование дроби в правильную
{
	int i;
	(*this > 0) ? i = 1 : i = -1;  //определение знака дроби
	FInt = abs(FInt) + abs(FNum / FDen);
	FNum = abs(FNum % FDen);
	FDen = abs(FDen);
	(FInt != 0)? FInt *= i : FNum *= i; //подстановка знака дроби
	return *this;
}

Fraction& Fraction::improper()  //преобразование дроби в неправильную
{
	int i;
	(*this > 0) ? i = 1 : i = -1;  //определение знака дроби
	FNum = abs(FNum)+abs(FInt * FDen);
	FDen = abs(FDen);
	FNum *= i; //подстановка знака дроби
	return *this;
}

bool Fraction::operator>(int X)  // сравнение дроби с целым числом
{
	if (FInt < 0 || FNum < 0 || FDen < 0) return false;
	if (FInt >= 0)
		if (FNum < 0 && FDen > 0 || FNum > 0 && FDen < 0) return false;
		else return true;
}

Fraction& Fraction::operator=(const Fraction& other)
{
	FInt = other.FInt;
	FNum = other.FNum;
	FDen = other.FDen;
	return *this;
}

int findgcd(int x, int y)  //наибольший общий делитель, используется при сокращении дробей
{
	if (y == 0) return x;
	return findgcd(y, x % y);
}
int findlcm(int x, int y)  //наименьшее общее кратное, ненужная функция
{for (int i = 1; ; i++)	if (x * i % y == 0) return x * i;}

ostream& operator<<(ostream& os, const Fraction& fract)
{
	if (fract.getFInt() != 0) os << fract.getFInt() << "_";
	if (fract.getFNum() != 0) os << fract.getFNum() << "/" << fract.getFDen() << "  ";
	return os;
}

/* ввод из консоли НЕ ПОЛУЧАЕТСЯ пока
istream& operator>>(istream& is, const Fraction& fract) 
{
	
	is >> fract.getFInt() >> fract.getFNum() >> fract.getFDen();
	return is;
}*/

Fraction operator+(Fraction left, Fraction right)
{
	left.improper();
	right.improper();
	cout << left << " " << right << endl;
	Fraction result(left.getFNum() * right.getFDen() +
		right.getFNum() * left.getFDen(),
		left.getFDen() * right.getFDen());
	return result.reduce().proper();
}

Fraction operator-(Fraction left, Fraction right)
{
	left.improper();
	right.improper();
	cout << left << " " << right << endl;
	Fraction result(left.getFNum() * right.getFDen() -
		right.getFNum() * left.getFDen(),
		left.getFDen() * right.getFDen());
	return result.reduce().proper();
}

Fraction operator*(Fraction left, Fraction right)
{
	left.improper();
	right.improper();
	cout << left << " " << right << endl;
	Fraction result(left.getFNum() * right.getFNum(), left.getFDen() * right.getFDen());
	return result.reduce().proper();
}

Fraction operator/(Fraction left, Fraction right)
{
	left.improper();
	right.improper();
	cout << left << " " << right << endl;
	Fraction result(left.getFNum() * right.getFDen(), left.getFDen() * right.getFNum());
	return result.reduce().proper();
}

bool operator==(const Fraction& left, const Fraction& right)
{
	return left.getFInt() == right.getFInt() &&
		left.getFNum() == right.getFNum() &&
		left.getFDen() == right.getFDen();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return left.getFInt() != right.getFInt() ||
		left.getFNum() != right.getFNum() ||
		left.getFDen() != right.getFDen();
}

/*
bool operator>(const Fraction& left, const Fraction& right)  
//вариант 1 - считаю его более правильным и универсальным, но слишком длинный
{
	Fraction templeft(left);
	Fraction tempright(right);
	templeft.improper();
	tempright.improper();
	int lcm = findlcm(templeft.getFDen(), tempright.getFDen());
	return (lcm / templeft.getFDen() * templeft.getFNum()) > 
			(lcm/ tempright.getFDen()* tempright.getFNum());
}*/

bool operator>(Fraction& left, Fraction& right)  /*вариант 2 - 
	на выходе наши дроби становятся неправильными, это неудобно для вывода на консоль(печать), например; 
	вставлять в оператор вывода в консоль обязательное сокращение и превращение в правильную дробь неразумно, 
	т.к. может понадобиться видеть дробь в том виде, как она есть.*/
{
	left.improper();
	right.improper();
	return left.getFNum()* right.getFDen() > right.getFNum() * left.getFDen();
}

bool operator<(Fraction& left, Fraction& right)  //вариант 2
{if (left > right) return false; else return true;}

bool operator>=(Fraction& left, Fraction& right)  //вариант 2
{
	left.improper();
	right.improper();
	return left.getFNum() * right.getFDen() >= right.getFNum() * left.getFDen();
}

bool operator<=(Fraction& left, Fraction& right)  //вариант 2
{
	left.improper();
	right.improper();
	return left.getFNum() * right.getFDen() >= right.getFNum() * left.getFDen();
}