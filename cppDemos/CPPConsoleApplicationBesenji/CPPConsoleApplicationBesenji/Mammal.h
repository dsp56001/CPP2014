#pragma once
#include <string>
class Mammal
{
public:
	Mammal();
	~Mammal();

	int Weight;
	std::string Name;

	virtual std::string About();
};

