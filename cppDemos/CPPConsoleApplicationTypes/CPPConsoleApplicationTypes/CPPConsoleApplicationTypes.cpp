// CPPConsoleApplicationTypes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>	//brings in headers for cin and cout

int global = 7; //global scoped int not a good idea try to avoid globals

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;	//brings std namespace into local scope

	short s = 1;
	
	//declare an int
	int i;				//local (to main function) scopes integer
	//assign an int
	i = 7;
	cout << "i= " << i << endl;

	int ii = 7; //declare and assign
	cout << "ii= " << ii << endl;

	if (true)
	{
		int iii = ii;	//block scoped variable
	}

	int iii{ 3 };	//new spec
	cout << "iii= " << iii << endl;

	char a;			//character type in c is really and int
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
	//double d = 3.1;
	//int i;
	i = int(d); //c++ function cast
	i = (int) d; //c implicit cast

	int cast = (static_cast<int>(a));  //c++
	auto acast = (static_cast<int>(b));
	cout << "cast=" << cast << endl;
	cout << "acast=" << acast << endl;

	//char[] and string

	char name[]{ 'j', 'e', 'f', 'f', '\0' };
	char jeff [] = "jeff";
	string strJeff = "jeff";

	//string is an STL object that can replace c char[]
	std::string cppName = "jeff";
	//strings can be used like char[]'s

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

	cout << "strJeff=";
	for (unsigned int i = 0; strJeff[i]; i++)
	{
		cout << strJeff[i];
	}
	cout << endl;
	cout << "strJeff.size():" << strJeff.size() << endl;
	cout << "sizeof(strJeff.c_str()):" << sizeof(strJeff.c_str()) << endl;

	//floatint point numbers
	float pi = 3.14f;						//note the postfix f
	double d = 3.141592653589793238463;



	//intro to pointers
	int * foo;			//int pointer 
	foo = new int(5);	//new int at foo address
	cout << "foo= " << *foo << endl;
	cout << "foo adress is " << foo << endl;
	delete foo;			//free memory

	cin.get();

	return 0;
}

