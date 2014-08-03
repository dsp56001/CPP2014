#pragma once
#include <string>
class Dog
{
public:
	Dog();
	Dog(std::string name);
	~Dog();
protected:
	int age;
public:
	int Weight;
	std::string Name;
	std::string BarkSound;
	std::string About();
};