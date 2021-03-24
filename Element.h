#pragma once
#include<iostream>
using namespace std;

#define tab "\t"
//#define DEBUG

template <typename T> class Element
{
	T Data;
	Element* pLeft, * pRight;
public:
	Element(T Data, Element* pLeft = nullptr, Element* pRight = nullptr) :
		Data(Data), pLeft(pLeft), pRight(pRight) {
#ifdef DEBUG
		cout << "EConstrucktor  " << this << endl;
#endif DEBUG
	};

	~Element() {
#ifdef DEBUG
		cout << "EDestrucktor  " << this << endl;
#endif DEBUG
	};

	bool is_leaf() { return pLeft == pRight; }
	template <typename T> friend class Tree;
	template <typename T> friend class Iterator;
};