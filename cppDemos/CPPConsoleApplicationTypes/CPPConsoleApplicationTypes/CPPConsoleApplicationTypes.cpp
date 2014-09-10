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

	int iii{ 3 };	//new spec
	cout << "iii= " << iii << endl;

	char a;
	a = 'a';
	char b = 'b';
	char c { 'c' }; //c++11
	char d('d'); //c++11
	cout << "a=" << a << " b=" << b << " c=" << c << endl;

	//sizeof
	long int lo = 10L;
	long long int llo = 10LL;

	cout << "sizeof(int): " << sizeof(i) << endl;
	cout << "sizeof(long int): " << sizeof(lo) << endl;
	cout << "sizeof(long long int): " << sizeof(llo) << endl;
	cout << "sizeof(char): " << sizeof(a) << endl;


	//cast
	int cast = (static_cast<int>(a));
	auto acast = (static_cast<int>(b));
	cout << "cast=" << cast << endl;
	cout << "acast=" << acast << endl;

	char name[]{ 'j', 'e', 'f', 'f', '\0' };
	char jeff [] = "jeff";
	string strJeff = "jeff";

	cout << "name[]=";
	for (unsigned int i = 0; name[i]; i++)
	{
		cout << name[i];
	}
	cout << endl;
	cout << "sizeof(name):" << sizeof(name) << endl;

	cout << "jeff[]=";
	for (unsigned int i = 0; jeff[i]; i++)
	{
		cout << jeff[i];
	}
	cout << endl;
	cout << "sizeof(jeff):" << sizeof(jeff) << endl;

	cout << "strJeff[]=";
	for (unsigned int i = 0; strJeff[i]; i++)
	{
		cout << strJeff[i];
	}
	cout << endl;
	cout << "strJeff.size():" << strJeff.size() << endl;
	cout << "sizeof(strJeff.c_str()):" << sizeof(strJeff.c_str()) << endl;

	int * foo;			//int pointer 
	foo = new int(5);	//new int at foo address
	cout << "foo= " << *foo << endl;
	cout << "foo adress is " << foo << endl;
	delete foo;			//free memory

	cin.get();

	return 0;
}

