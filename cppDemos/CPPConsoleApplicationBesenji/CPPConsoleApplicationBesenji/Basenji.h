#pragma once
#include "Dog.h"
class Basenji :
	public Dog
{
public:
	Basenji();
	Basenji(std::string name);
	~Basenji();
	std::string Bark() override;
};

