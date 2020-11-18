#include"Header.h"
#include"Class_House.h"
#include"Class_Apartment.h"
#include"Class_Person.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Многоквартирный дом" << endl;

	
	Person Ivan { "Ivan Ivanov", 'm', 7568138};
	Person Oleg(Ivan);
	cout << Oleg << endl;
	Person Jak{ "Jak", 'm', 4568728 };
	Apartment A2(2, 33);
	A2.addperson(Ivan);
	A2.addperson(Jak);
	cout << A2 << endl;

	
	Apartment A4(4,63);
	A4.addperson(Person{ "Mark", 'm',1234567});
	A4.addperson(Person{ "Olga", 'w' });
	A4.addperson(Person{ "Anna", 'w' });
	cout << A4 << endl;
	A4.showpersonfone(0);
	A4.delperson("Olga");
	A4.addperson(Oleg);
	cout << A4 << endl;

	House H34(34, 4);
	
	H34.addapartment(2, Person (Ivan));
	H34.addapartment(2, Person(Jak));

	H34.addapartment(3, Person{ "Petr", 'm',4567891 });
	H34.addapartment(3, Person{ "Elena", 'w' });

	cout << H34 << endl;

	return 0;
}