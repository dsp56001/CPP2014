#pragma once
#include "Human.h"
#include "Cage.h"
#include "ZooAnimal.h"
#include <vector>
#include <string>

class ZooKeeper :
	public Human
{
public:
	ZooKeeper();
	~ZooKeeper();

	std::vector<Cage> * Cages;
	void Feed(ZooAnimal&);
	void Feed(ZooAnimal&, int);
	void FeedAllAminals();
	
	std::string About() override;
};

