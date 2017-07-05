#include "stdafx.h"
#include "Animal.h"
#include <string>

Animal::Animal() : m_Hunger(10)
{
}


Animal::~Animal()
{
}

std::string Animal::About()
{
	return this->AnimalType + ":\t" + std::to_string(this->m_Hunger);
}

void Animal::Eat()
{
	this->m_Hunger--;
}

void Animal::Eat(int howMuch)
{
	for (int i  = 0;  i < howMuch; i++)
	{
		this->Eat();
	}
}