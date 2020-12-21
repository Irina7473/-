#include<iostream>
#include<string.h>
#include <stdio.h>
#include "String.h"

using namespace std;

int main()
{
	setlocale(LC_ALL,"");
	
	String str0 = "Hello";
	String str1 = str0;
	String str2{ "world!" };
	String str3 ( "Ura" );
	String str4 = String("life and world!");
	cout << str0 << endl << str1 << endl << str2 << endl << str3 << endl << str4 << endl;
	
	cout << str1+str2 << endl << endl;  // "Hello world!"

	str1 += str2;  // "Hello world!"
	str1.print();
	str3 = str3 + str4;  // "Ura life and world!"
	str3.print();
	cout << endl;

	String str5 = str1 + str3;  // "Hello world! Ura life and world!"
	cout << str5 << endl << endl;
			
	str2.setstr(0, 'r');
	cout << str2.getstr() << endl;  //"rorld!"
	str2[0] = 'w';
	cout << str2[0] << endl;  //"w"
	
	return 0;
}
