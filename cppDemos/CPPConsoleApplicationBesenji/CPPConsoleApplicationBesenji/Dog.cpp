#include "stdafx.h"
#include "Dog.h"
#include <sstream>
#include <iostream>

using namespace std;
Dog::Dog() : Dog("fido")
{
}

Dog::Dog(string name)
{
	Name = name;
	age = 0;
	Weight = 0;
	BarkSound = "Woof!";
	//DogCount++;
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
