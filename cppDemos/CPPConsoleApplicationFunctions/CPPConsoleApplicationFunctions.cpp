// CPPConsoleApplicationFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//Function to add One to a number
int AddOne(int number)	//Change to pass by reference AddOne(int &number) how does this change the program?
{
	return number++;  //why does't this return one more than number????
}

//Exponent with for loop
int Power(int base, unsigned int exponent)
{
	int result = 1;
	for (int i = 0; i < exponent; ++i)
		result *= base;
	return result;
}

void stringInfo(char name [], char *  string [])
{
	cout << name << "[]=";
	for (unsigned int i = 0; name[i]; i++)
	{
		cout << name[i];
	}
	cout << endl;
	cout << "sizeof(" << name << "):" << sizeof(name) << endl;
}

//prototype
int PowerRecursive(int base, unsigned int exponent);

int _tmain(int argc, _TCHAR* argv[])
{
	
	int i = 7;
	cout << "i=" << i << endl;
	cout << "AddOne(i)=" << AddOne(i) << endl;
	cin.get();
	cout << "i=" << i << endl;
	cin.get();
	//return 0

	cout << "calling Power(2,3):";
	cout << Power(2, 3) << endl;
	cout << "calling Power(2,4):";
	cout << Power(2, 4) << endl;

	cout << "calling PowerRecursive(2,3):";
	cout << PowerRecursive(2, 3) << endl;
	cout << "calling PowerRecursive(2,4):";
	cout << PowerRecursive(2, 4) << endl;

	char * name[] = { "jeff" };
	stringInfo("name", name);
	cin.get();
	return 0;
}

int PowerRecursive(int base, unsigned int exponent)
{
	//end recursion at power of 1 and don't allow 0 or negative
	if (exponent >= 1)
		return base *= PowerRecursive(base, exponent - 1);
	else
		return base *= 1; 
}




