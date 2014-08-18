/* oopLib */

#include "pch.h"
#include "Dog.h"

using namespace std;
using namespace oopLib;

static int DogCount;

Dog::Dog() : Dog("fido")
{
}

Dog::Dog(string name)
{
	Name = name;
	age = 0;
	Weight = 0;
	BarkSound = "Woof!";
	DogCount++;
}

int Dog::GetDogCount()
{
	return DogCount;
}


Dog::~Dog()
{
	//Nothing to destroy
	std::cout << this->Name << " destructor" << std::endl;
}

string Dog::Bark()
{
	return this->BarkSound;
}

string Dog::About()
{
	return Mammal::About() + " My Barksound sounds like " + Bark();
}