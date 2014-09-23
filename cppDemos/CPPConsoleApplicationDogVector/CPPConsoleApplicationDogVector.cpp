// CPPConsoleApplicationDogVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <memory>
#include "Dog.h"

using namespace std;

void addDog(list<Dog> & dogs, const Dog *d);
void aboutDogs(list <Dog> & dogs);

int _tmain(int argc, _TCHAR* argv[])
{
	list<Dog> dogs;

	Dog *d = new Dog();
	d->Name = "fido";
	d->setWeight(4);

	addDog(dogs, d);
	

	addDog(dogs, new Dog{ "milo" });

	//unique ptr
	unique_ptr<Dog> roover(new Dog("roover"));
	addDog(dogs, roover.get());

	aboutDogs(dogs);
	delete d;
	cin.get();
	return 0;
}

void addDog(list<Dog> & dogs, const Dog *d)
{
	dogs.push_back(*d);
}

void aboutDogs(list <Dog> & dogs)
{
	//Write about methods in console
	for (Dog d : dogs)
	{
		cout << d.About() << endl;
	}
}

