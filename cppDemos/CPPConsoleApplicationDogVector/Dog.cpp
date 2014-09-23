#include "stdafx.h"
#include "Dog.h"
#include <sstream>
#include <iostream>

using namespace std;
Dog::Dog()
{
	Name = "fido";
	age = 0;
	weight = 0;
}

Dog::Dog(string name)
{
	Name = name;
	age = 0;
	weight = 0;
}

Dog::~Dog()
{
	//Nothing to destroy
	std::cout << this->Name << " destructor" << std::endl;
}


string Dog::About()
{
	std::stringstream about;
	about << "Hello my name is " << Name << " I weigh " << weight << ". My Bark sounds like " << BarkSound;
	return about.str();

}

int Dog::getAge()
{
	return this->age;
}

int Dog::getWeight()
{
	return this->weight;
}

void Dog::setWeight(int weight)
{
	this->weight = weight;
}
