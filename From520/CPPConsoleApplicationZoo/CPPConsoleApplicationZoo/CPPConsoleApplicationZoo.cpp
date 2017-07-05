// CPPConsoleApplicationZoo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ZooAnimal.h"
#include "Cage.h"
#include "ZooKeeper.h"
#include <iostream>

using namespace std;

//Set Static variables
int Cage::TotalCagedAnimals= 0;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Zoo animals:9000" << endl;
	/*
	ZooAnimal * monkey = new ZooAnimal();
	monkey->AnimalType = "monkey";
	
	
	cout << "monkey->About:" << monkey->About() << endl;
	Cage * monkeyCage = new Cage();
	cout << "monkeyCage->About:" << monkeyCage->About() << endl;
	

	cout << "Add three monkey to a cage." << endl;
	monkeyCage->AddAnimal(monkey);
	//Eat so the monkey has different hunger
	monkey->Eat();
	monkeyCage->AddAnimal(monkey);
	//Eat so the monkey has different hunger
	monkey->Eat();
	monkeyCage->AddAnimal(monkey);

	cout << "monkeyCage->About():";
	cout << monkeyCage->About() << endl;
	
	cout << "Remove first monkey" << endl;
	monkeyCage->RemoveAnimal(monkey);

	cout << "monkeyCage->About():";
	cout << monkeyCage->About() << endl;

	cout << "monkeyCage->FeedAnimals():";
	monkeyCage->FeedAnimals();

	cout << monkeyCage->About() << endl;

	cout << "monkeyCage->FeedAnimals(5):";
	monkeyCage->FeedAnimals(5);

	cout << monkeyCage->About() << endl;

	//Zookeeper
	ZooKeeper *jeff = new ZooKeeper();
	cout << "Give zookeeper a the cage of monkeys" << endl;
	jeff->Cages->push_back(*monkeyCage);

	cout << "Have zookeeper feed animnals in cage" << endl;
	jeff->FeedAllAminals();

	cout << monkeyCage->About() << endl;
	*/

	cin.get();

	return 0;
}

