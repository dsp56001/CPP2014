#include "stdafx.h"
#include "ZooAnimal.h"


ZooAnimal::ZooAnimal()
{
}


ZooAnimal::~ZooAnimal()
{
}


void ZooAnimal::Feed()
{
	this->Eat();
}

void ZooAnimal::Feed(int howMuch)
{
	for (int i = 0; i < howMuch; i++)
	{
		this->Eat();
	}
}