#pragma once
#include "Element.h"

template <typename T> class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* temp) : Temp(temp) {};
	~Iterator() {};

	const int& operator*()const { return Temp->Data; };
	int& operator*() { return Temp->Data; };

	bool operator==(const Iterator& other)const
	{return this->Temp == other.Temp;}
	bool operator!=(const Iterator& other)const
	{return !(*this == other);}

};

