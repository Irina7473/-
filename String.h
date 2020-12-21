#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class String
{
	int Size;
	char* Str;
public:
	int getsize()const { return Size; }
	const char* getstr()const { return Str; }
	void setsize(int size) { Size = size; }
	void setstr(int ind, char str) { Str[ind] = str; }
	//Конструкторы
	String() : String{ 80 } {}  //по умолчанию
	String(int size);
	String(const char str[]);
	String(const String& other);  //копирования
	String(String&& S);  //перемещения
	~String();
	
	void print()const;
	
	String& operator=(const String& other);  //оператор присваивания с сохранением объекта
	//String& operator= (String&& S  //оператор перемещения без сохранения объекта
	String& operator+=(const String& other);
	
	const char& operator[] (const int ind)const;
	char& operator[] (int ind);

};

ostream& operator<<(ostream& os, const String& str);
String operator+(const String& left, const String& right);
