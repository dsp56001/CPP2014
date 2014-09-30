/* oopLib */

#include "pch.h"
#include "Dog.h"

using namespace std;
using namespace oopLib;

static int DogCount;

Dog::Dog() : Dog("fido")
{
}

Dog::Dog(string name) : age(1), BarkSound("Woof!"), Mammal(name)
{
	DogCount++;
}

int Dog::GetDogCount()
{
	return DogCount;
}

Dog::~Dog()
{
	//Nothing to destroy
	std::cout << this->m_name << " destructor" << std::endl;
}

string Dog::Bark()
{
	return this->BarkSound;
}

string Dog::About()
{
	return Mammal::About() + " My Barksound sounds like " + Bark();
}