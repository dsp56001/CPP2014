/* oopLib */

#include "pch.h"
#include "oopLib.h"
#include "Mammal.h"

using namespace std;
using namespace oopLib;
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