#pragma once
#include "ZooAnimal.h"
#include <vector>
#include <string>

class Cage
{
protected:
	int m_MaxAnimals;


public:
	Cage();
	~Cage();

	
	const unsigned int MaxAnimals = 5;

	std::vector<ZooAnimal> *ZooAnimals;

	std::string About();
	void AddAnimal(ZooAnimal *);
	void RemoveAnimal(ZooAnimal *);
	void FeedAnimals();
	void FeedAnimals(int);

	static int TotalCagedAnimals;
};

