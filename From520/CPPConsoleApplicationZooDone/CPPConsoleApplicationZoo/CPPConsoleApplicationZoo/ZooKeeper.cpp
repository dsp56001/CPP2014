#include "stdafx.h"
#include "ZooKeeper.h"
#include "Cage.h"
#include <vector>
#include <string>

using namespace std;

ZooKeeper::ZooKeeper()
{
	this->Cages = new vector<Cage>();
}

ZooKeeper::~ZooKeeper()
{
}

void ZooKeeper::Feed(ZooAnimal  & zooAnimal)
{
	zooAnimal.Feed();
}

void ZooKeeper::Feed(ZooAnimal  & zooAnimal, int howMuch)
{
	zooAnimal.Feed(howMuch);
}

void ZooKeeper::FeedAllAminals()
{
	for (auto & c : *Cages)
	{
		c.FeedAnimals();
	}
}

string ZooKeeper::About()
{
	string about = Human::About();
	about += " I have " + to_string(Cages->size()) + " + cages\n";
	for (auto c : *Cages)
	{
		about += c.About();
	}
	return about;
}
