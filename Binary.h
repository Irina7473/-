#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#define TAB "-----------------------------------------------\n";


class Binary
{
	int Size;  // количество элементов двоичного числа
	int* Binnum;  //массив элементов двоичного числа
	
public:
	//конструкторы
	Binary();  //по умолчанию
	Binary(int size, const int binnum[]);  //по значению
	Binary(const Binary& other);  //копирования
	Binary(Binary&& other);  //перемещения
	Binary(int decnum); //преобразования из десятичного числа
	~ Binary();  //деструктор

	int getSize()const { return Size; }
	const int* getBinnum()const { return Binnum; }
	int* getBinnum() { return Binnum; }
	void setSize(int size) { Size = size; }
	
	void print() const;
	int decconversion() const;  //преобразование двоичного числа в десятичное
	void sizeadding(int size);  // преобразование с увеличением размера
	void sizereduction();  // преобразование с уменьшением размера
	
	Binary& operator=(const Binary& other);  //оператор присваивания с сохранением объекта
	Binary& operator=(Binary&& other);  //оператор присваивания перемещением

	const int& operator[] (const int ind)const;
	int& operator[] (int ind);

};

Binary singlesize(Binary& left, Binary& right);  // приведение к одному размеру

ostream& operator<<(ostream& os, const Binary& binnum);
istream& operator>> (istream& is, Binary& obj);    //не получилось

Binary operator+(const Binary& left, const Binary& right);
Binary operator-(const Binary& left, const Binary& right);
Binary operator*(const Binary& left, const Binary& right);
Binary operator/(const Binary& left, const Binary& right);

bool operator>(const Binary& left, const Binary& right);

Binary operator&(const Binary& left, const Binary& right);
Binary operator|(const Binary& left, const Binary& right);
Binary operator^(const Binary& left, const Binary& right);
Binary operator~(const Binary& obj);