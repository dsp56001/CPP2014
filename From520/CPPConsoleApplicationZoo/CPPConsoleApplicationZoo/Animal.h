#pragma once
#include<string>
class Animal
{
protected:
	int m_Hunger;
public:
	Animal();
	~Animal();
	std::string AnimalType;
	std::string About();
	void Eat();
	void Eat(int);

};

