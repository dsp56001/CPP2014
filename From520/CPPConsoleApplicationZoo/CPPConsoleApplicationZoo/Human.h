#pragma once
#include<string>
class Human
{
public:
	Human();
	~Human();
	std::string Name;
	virtual std::string About();
};

