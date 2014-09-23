// CPPConsoleApplicationSimpleDog.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

struct CDog
{
	std::string name;
	int age;
};

void aboutCDog(const CDog& dog);

class CPPDog
{
public:
	std::string name;
	int age;
public:
	//constructor
	CPPDog()
	{
		std::cout << "CPPDog::CPPDog\n";
	}

	//destructor
	~CPPDog()
	{
		std::cout << "CPPDog::~CPPDog\n";
	}

	//method
	string CPPDog::about()
	{
		string s  = "Dog About(): Hello my name is " + this->name + " and I'm " +  to_string(this->age) + " years old.";
		return s;
	}


};


int _tmain(int argc, _TCHAR* argv[])
{
	//instance of struct
	CDog fido;
	fido.name = "fido";
	fido.age = 1;
	
	//also instance of struct
	CDog milo = { "milo", 1 };

	//instance of class
	CPPDog roover;
	roover.name = "roover"; //set roover to public
	roover.age = 1;

	//instance of class
	CPPDog spot{ "spot", 1 };

	//use constructror

	return 0;
}

