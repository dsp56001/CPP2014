/* oopLib */

#include "pch.h"
#include "Mammal.h"
#include <string>

using namespace std;
using namespace oopLib;

Mammal::Mammal() : m_weight(1), m_name("unnamed mammal") {}

Mammal::Mammal(const std::string& name) : m_weight(1), m_name(name) {}

Mammal::~Mammal() {}

string Mammal::About()
{
	std::stringstream about;
	about << "Hello my name is " << this->m_name << " I weigh " << this->m_weight;
	return about.str();
}

int Mammal::getWeight()
{
	return this->m_weight;
}
void Mammal::setWeight(int weight)
{
	this->m_weight = weight;
}

string Mammal::getName()
{
	return this->m_name;
}

void Mammal::setName(string name)
{
	this->m_name = name;
}