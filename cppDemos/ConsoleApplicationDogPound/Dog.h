#pragma once
#include <string>
#include <ostream>

class Dog
{
public:
	Dog();						//Constructor
	Dog(std::string name);		//Overloaded Constructor
	~Dog();						//Destructor
protected:
	int age;					//Private instance data memebers
	int weight;
public:
	
	std::string Name;
	std::string BarkSound;
	std::string About();

	//accessors
	int getAge();				//Read Only Accessor
	int getWeight();
	void setWeight(int);

	//Fiend of ostream to override the << operator
	friend std::ostream& operator << (std::ostream&, Dog*);
};