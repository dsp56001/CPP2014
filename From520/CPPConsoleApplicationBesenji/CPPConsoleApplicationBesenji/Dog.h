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
	static int DogCount;
	std::string BarkSound;
protected:
	int age;

	
	
};

