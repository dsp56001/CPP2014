// CPPConsoleApplicationBesenji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dog.h"
#include "Basenji.h"
#include <iostream>
#include <memory>

int _tmain(int argc, _TCHAR* argv[])
{
	Dog * d = new Dog();
	std::shared_ptr<Dog> milo(new Dog("Milo"));
	std::shared_ptr<Basenji> cheddar(new Basenji("Cheddar"));

	std::cout << d->About() << std::endl;
	std::cout << milo->About() << std::endl;
	std::cout << cheddar->About() << std::endl;

	std::cout << d->Bark() << std::endl;
	std::cout << milo->Bark() << std::endl;
	std::cout << cheddar->Bark() << std::endl;

	std::cin.get();
	delete d;
	return 0;
}

