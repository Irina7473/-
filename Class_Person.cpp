#include "Class_Person.h"

Person:: Person(const char* name, char gender, int phone) : 
	Name{ new char[strlen(name) + 1] }, Gender{ gender }, Phone{ phone }
{
	strcpy_s(this->Name, strlen(name) + 1, name);
}

Person:: Person(const Person& pers) : 
	Name{ new char[strlen(pers.Name) + 1] }, Gender{ pers.Gender }, Phone{ pers.Phone }
{
	strcpy_s(Name, strlen(pers.Name) + 1, pers.Name);
}

Person& Person:: operator=(const Person& other)
{
	if (this != &other)  //проверка на присваивание самого себе
	{
		delete[]Name;
		Name = new char[strlen(other.Name) + 1];
		strcpy_s(Name, strlen(other.Name) + 1, other.Name);

		Gender = other.Gender;
		Phone = other.Phone;
	}
	return *this;  //возврат ссылки на объект для многократного присваивания
}

ostream& operator<< (ostream& os, const Person& person)
{
	os << person.getName() << ' ' << person.getPhone();
	return os;
}