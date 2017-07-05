#include "stdafx.h"
#include "Cage.h"
#include "ZooAnimal.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;



Cage::Cage()
{
	ZooAnimals = new vector<ZooAnimal>();
}

Cage::~Cage()
{
	delete ZooAnimals;
}

string Cage::About()
{
	//Call about on aminals that are in the cage. Say no animals if there are none.
	string about = "Cage Contains:";
	if (ZooAnimals->size() > 0)
	{ 
		for (ZooAnimal a: *ZooAnimals)
		{
			about += "\n" +  a.About();
		}
	}
	else
	{ 
		about += "no animals";
	}
	return about;
	

}
void Cage::AddAnimal(ZooAnimal *animal)
{
	//Add animals if there is room in the cage
	if (ZooAnimals->size() <= this->MaxAnimals)
	{ 
		ZooAnimals->push_back(*animal);
		Cage::TotalCagedAnimals++;
	}
		

	//note if there is no room animal isn't added and we don't nofity the caller
}
void Cage::RemoveAnimal(ZooAnimal *animal)
{
	//User iterator as we will delete the first instance and then get the heck out of the function
	for (vector<ZooAnimal>::iterator it = ZooAnimals->begin(); it != ZooAnimals->end(); it++)
	{
		if (it->AnimalType == animal->AnimalType)
		{
			ZooAnimals->erase(it);
			Cage::TotalCagedAnimals--;
			break;  //iterator is not valid must break!
		}
	}
}

void Cage::FeedAnimals()
{
	//loop though and feed animals
	for (auto & a : *ZooAnimals)
		a.Feed();
}
void Cage::FeedAnimals(int howMuch)
{
	//loop though and feed animals a specific amount
	for (auto & a : *ZooAnimals)
		a.Feed(howMuch);
}
