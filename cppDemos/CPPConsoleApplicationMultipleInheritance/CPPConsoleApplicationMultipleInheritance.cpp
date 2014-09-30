// CPPConsoleApplicationMultipleInheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Duck.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Duck * daffy = new Duck();

	daffy->Fly();
	daffy->Swim();

	std::cout << "Daffy->getTotalDistance()=" << daffy->getTotalDistance();

	delete daffy;

	std::cin.get();
	
	return 0;
}

