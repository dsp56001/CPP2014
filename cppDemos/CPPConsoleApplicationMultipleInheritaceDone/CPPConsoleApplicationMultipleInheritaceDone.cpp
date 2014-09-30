// CPPConsoleApplicationMultipleInheritaceDone.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "RocketDuck.h"

int _tmain(int argc, _TCHAR* argv[])
{
	RocketDuck * daffy = new RocketDuck();

	daffy->Launch();
	daffy->Rocket::Fly();
	daffy->Swim();

	std::cout << "Daffy->getFlyDistance()=" << daffy->getFlyDistance() << std::endl;
	std::cout << "Daffy->getSwimDistance()=" << daffy->getSwimDistance() << std::endl;
	std::cout << "Daffy->getTotalDistance()=" << daffy->getTotalDistance() << std::endl;

	delete daffy;

	std::cin.get();

	return 0;
	
	return 0;
}

