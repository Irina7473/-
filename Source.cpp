#include<iostream>
#include "Tree.h"
using namespace std;
#define TAB cout<<"------------------------------------"<<endl

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int n;
	cout << "Введите количество элементов дерева" << endl; cin >> n;
	Tree<double> t;
	for (int i = 0; t.size() < n; i++)
		t.insert(rand()%100);
	t.print();
	cout<<"min  "<<t.minValue()<<endl;
	cout <<"max  "<<t.maxValue() << endl;
	cout <<"количество элементов  "<< t.size() << endl;
	cout <<"сумма  "<<t.sum() << endl;
	cout <<"среднее арифметическое  "<<t.avg() << endl;
	TAB;
	Tree<double> t2=t;
	t2.print();
	TAB;
	Tree<int> t3 = {11,6,33,3,15,8,5,2,9,40,36};
	t3.print();
	cout << "min  " << t3.minValue() << endl;
	cout << "max  " << t3.maxValue() << endl;
	cout << "Элемент 15  " << t3.search(15) << endl;
	cout<< "Элемент 40  " << t3.search(40)<<endl;
	TAB;
	t3.erase(5);
	t3.erase(6);
	t3.erase(11);
	t3.print();
	TAB;
	Tree<char> t4 = { 'f', 'a', 'c', 'v', 'm'};
	t4.print();
	cout << "min  " << t4.minValue() << endl;
	cout << "max  " << t4.maxValue() << endl;
	TAB;
	t4.erase('a');
	t4.print();
	TAB;

	return 0;
}