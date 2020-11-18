#pragma once
#include"Header.h"
#include"Class_Person.h"
#include"Class_Apartment.h"

class House
{
	int NumberHouse; //номер квартиры
	int NumApart; //количество квартир
	Apartment* aparts=nullptr; //массив квартир
		
public:
	//конструкторы
	House(int numhouse, int numap);
	House(const House& other);
	
	~House()  //деструктор
	{
		delete[] aparts;
		cout << "Деструктор дома" << endl;
	}
	
	//доступ к полям дома для чтения
	int getNumberHouse() const { return NumberHouse; }
	int getNumApart() const { return NumApart; }
	const Apartment& getaparts(int index) const { return aparts[index]; }

	House& operator= (const House& other); //оператор присваивания

	void addapartment(int numap, const Person& person);   //заселение квартир
		
	friend ostream& operator<< (ostream& os, const House& house);
	
};
