#pragma once
#include <string>
#include "Mammal.h"
class Dog : 
	public Mammal
{
public:
	Dog();
	Dog(std::string name);
	~Dog();
	virtual std::string Bark();
	std::string About() override;
	std::string BarkSound;

	static int DogCount;
protected:
	int age;
};

