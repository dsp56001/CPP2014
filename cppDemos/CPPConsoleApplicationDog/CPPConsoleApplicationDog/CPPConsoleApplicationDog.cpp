// CPPConsoleApplicationDog.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include "Dog.h"

//forward declaration
void testDog();

int _tmain(int argc, _TCHAR* argv[])
{
	
	Dog *d = new Dog();
	std::cout << d->About() << std::endl;
	d->Name = "fido";
	d->Weight = 7;
	d->BarkSound = "Woof!";

	std::cout << d->About() << std::endl;
	delete d; //destroy d

	testDog();
	std::cin.get();
	return 0;
}

void testDog()
{
	//C pointer
	Dog *fido = new Dog("fido");
	std::cout << fido->About() << std::endl;
	fido->Weight = 3;
	fido->BarkSound = "Arf!";

	std::cout << fido->About() << std::endl;

	//unique pointer
	std::unique_ptr<Dog> milo(new Dog("milo"));
	std::cout << milo->About() << std::endl;

	//shared pointer
	std::shared_ptr<Dog> roover(new Dog("roover"));
	std::cout << roover.get()->About() << std::endl;

	return;
}

