#pragma once
#include "String.h"

	String:: String(int size): Size{ size}
	{
		Str = new char[Size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String:: String(const char str[])
	{
		Size = strlen(str) + 1;
		Str = new char[Size] {};
		for (int i = 0; i < strlen(str) + 1; i++)
		{
			Str[i] = str[i];
		}
		cout << "SignConstructor:\t" << this << endl;
	}

	String:: String(const String& other)
	{
		if (this != &other)
		{
			Size = other.Size;
			Str = new char[Size] {};
			for (int i = 0; i < Size; i++)
			{
				Str[i] = other.Str[i];
			}
		}
		cout << "CopyConstructor:\t" << this << endl;
	}

	String::String(String&& S) : Size(S.Size), Str(S.Str)
	{ 
		S.Str = nullptr; 
		cout << "MoveConstructor:\t" << this << endl;
	}

	String:: ~String()
	{
		delete[] Str;
		cout << "Destructor:\t" << this << endl;
	}

	void String:: print()const
	{
		cout << "Size: " << Size << "\t";
		cout << "Str: " << Str << endl;
	}

	String& String:: operator=(const String& other)
	{
		if (this != &other)
		{
			delete[] Str;
			Size = other.Size;
			Str = new char[Size] {};
			for (int i = 0; i < Size; i++)
			{
				Str[i] = other.Str[i];
			}
		}
		return *this;
	}

	/* Отказалась от этого оператора, 
	тк с ним неправильно работало сложение, 
	обрезалось все после первого пробела

	String& String::operator= (String&& S)
	{
		delete Str;
		Str = S.Str;
		S.Str = nullptr;
		cout << "MoveAassignment:\t" << this << endl;
		return *this;
	}*/

	String& String:: operator+=(const String& other)
	{
		//String S= Str + *other.getstr();
		//Str= Str + *other.getstr();
		//cout << S << endl;
		return *this = *this + other; 
	}

	const char& String:: operator[] (const int ind)const
	{
		if (ind >= 0 && ind < Size) return Str[ind];
	}

	char& String:: operator[] (int ind)
	{
		if (ind >= 0 && ind < Size) return Str[ind];
	}



ostream& operator<<(ostream& os, const String& str)
{
	os << str.getstr();
	return os;
}

String operator+(const String& left, const String& right)
{
	int ressize = left.getsize() + right.getsize();
	String result(ressize);
	result.setsize(ressize);
	cout << result.getsize() << endl;
	for (int i = 0; i < left.getsize() - 1; i++)
	{
		result[i] = left[i];
	}
	result[left.getsize() - 1] = ' ';
	for (int i = left.getsize(); i < ressize; i++)
	{
		result[i] = right[i - left.getsize()];
	}
	return result;
}

