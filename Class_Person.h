#pragma once
#include"Header.h"

class Person
{
	char* Name;  //ФИО
	char Gender; //пол
	int Phone;   //телефон

public:
	//конструкторы
	Person(const char* name, char gender, int phone);
	Person() : Person{ nullptr,' ', 0 } {}
	Person(const char* name) : Person{ name,' ', 0 } {}
	Person(const char* name, char gender) : Person{ name, gender, 0 } {}
	Person(const Person& pers);
		
	~Person()  //деструктор
	{
		delete[] Name;
		cout << " - Деструктор человека " << endl;
	}

	//доступ к полям человека для чтения
	const char* getName() const { return Name; }
	char getGender() const { return Gender; }
	int getPhone() const { return Phone; }

	Person& operator= (const Person& other); //оператор присваивания
	
};

ostream& operator<< (ostream& os, const Person& person); 