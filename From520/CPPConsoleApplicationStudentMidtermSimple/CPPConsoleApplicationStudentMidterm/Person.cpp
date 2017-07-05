#include "stdafx.h"
#include "Person.h"


Person::Person() : Name("Jeff Meyers"), Age(1)
{
}


Person::~Person() 
{
}

std::string Person::About()
{
	return "Person->About():Hello my name is " + this->Name + " and I'm " + std::to_string(this->Age) + " years old";
}
