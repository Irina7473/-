#pragma once
#include"Header.h"
#include"Class_Person.h"

class Apartment
{
	int NumberAp; //номер квартиры
	int Area;  //площадь
	Person** persons;    //массив указателей на проживающих
	int res = 0;  //количество проживающих в квартире
	int R = 10; //максим кол-во жильцов в квартире

public:
	//конструкторы
	Apartment(int numAp, int area);
	Apartment(int numAp) : Apartment{ numAp, 0 } {}
	Apartment() : Apartment{ 0, 0 } {}
	Apartment(const Apartment& apart);

	~Apartment();  //деструктор

	//доступ к полям квартиры для чтения
	int getNumberAp() const { return NumberAp; }
	int getArea() const { return Area; }
	const Person& getpersons(int index) const { return *persons[index]; }
	int getres() const { return res; }

	Apartment& operator=(const Apartment& other);   	//оператор присваивания

	void addperson(const Person& person); 	//добавление жильца в квартиру

	void delperson(string name); //удаление жильца из квартиры

	int findPerson(string name);  //найти жильца квартиры по ФИО

	void showpersonfone(int r); //показать телефон жильца квартиры
				
};

ostream& operator<< (ostream& os, const Apartment& apartment);