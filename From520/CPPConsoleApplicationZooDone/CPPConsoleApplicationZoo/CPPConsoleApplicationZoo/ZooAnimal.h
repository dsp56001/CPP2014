#pragma once
#include "Animal.h"
class ZooAnimal :
	public Animal
{
public:
	ZooAnimal();
	~ZooAnimal();

	void Feed();
	void Feed(int);
};

