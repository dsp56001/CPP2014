#include "stdafx.h"
#include "Dog.h"
#include <sstream>
#include <iostream>

using namespace std;
Dog::Dog()
{
	Name = "fido";
	age = 0;
	Weight = 0;
}

Dog::Dog(string name)
{
	Name = name;
	age = 0;
	Weight = 0;
}

Dog::~Dog()
{
	//Nothing to destroy
	std::cout << this->Name << " destructor" << std::endl;
}


string Dog::About()
{
	std::stringstream about;
	about << "Hello my name is " << Name << " I weigh " << Weight << ". My Bark sounds like " << BarkSound;
	return about.str();

}
