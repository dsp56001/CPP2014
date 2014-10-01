// ConsoleApplicationDogPound.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Dog.h"

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	Dog *d = new Dog();
	cout << d << endl;
	cin.get();
	return 0;
}

