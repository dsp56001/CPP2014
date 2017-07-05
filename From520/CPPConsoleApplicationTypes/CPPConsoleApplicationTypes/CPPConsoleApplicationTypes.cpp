// CPPConsoleApplicationTypes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	//declare an int
	int i;
	//assign an int
	i = 7;
	cout << "i= " << i << endl;

	int ii = 7; //declare and assign
	cout << "ii= " << ii << endl;

	int iii{ 3 };
	cout << "iii= " << iii << endl;

	char a;
	a = 'a';
	char b = 'b';
	char c { 'c' }; //c++11
	char d('d'); //c++11
	cout << "a=" << a << " b=" << b << " c=" << c << endl;


	//cast
	int cast = (static_cast<int>(a));
	auto acast = (static_cast<int>(b));
	cout << cast << " " << acast;

	char name[]{ 'j', 'e', 'f', 'f', '\0' };
	char jeff [] = "jeff";

	string strJeff = "jeff";

	cin.get();

	int * foo;
	foo = new int(5);
	delete foo;


	return 0;
}

