#include "Class_House.h" 

House:: House(int numhouse, int numap) : 
	NumberHouse{ numhouse }, NumApart{ numap }, aparts{ new Apartment[numap] } {}

House:: House(const House& other) : House(other.NumberHouse, other.NumApart)
{
	for (int i=0; i< NumApart; i++)
		aparts[i] = other.aparts[i];
}

House& House:: operator= (const House& other)
{
	if (this != &other)
	{
		NumApart = other.NumApart;
		for (int i = 0; i < NumApart; i++)
			aparts[i] = other.aparts[i];
	}
	return *this;
}

void House:: addapartment(int numap, const Person& person)
{
	cout << "В доме № "<<this->NumberHouse<< " квартира № " << numap;
	--numap;
	if (numap < 0 || numap >= NumApart)
		return;
	aparts[numap].addperson(person);
	cout << " заселена жильцом " <<person.getName() << endl;
}

ostream& operator<< (ostream& os, const House& house)
{
	os << "Для дома № " << house.getNumberHouse() << " :\n";
	for (int i = 0; i < house.getNumApart(); i++)
	{
		const Apartment& apart = house.getaparts(i);
		if (apart.getres() > 0)
		{
			os << "в квартире № " << i + 1 << " площадью " << apart.getArea() << " : ";
			os << apart << endl;;
		}
	}
		return os<<endl;
}