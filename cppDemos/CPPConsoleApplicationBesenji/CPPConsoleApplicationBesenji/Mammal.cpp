#include "stdafx.h"
#include "Mammal.h"
#include <sstream>
#include <iostream>

using namespace std;
Mammal::Mammal()
{
}


Mammal::~Mammal()
{
}

string Mammal::About()
{
	std::stringstream about;
	about << "Hello my name is " << Name << " I weigh " << Weight;
	return about.str();

}
