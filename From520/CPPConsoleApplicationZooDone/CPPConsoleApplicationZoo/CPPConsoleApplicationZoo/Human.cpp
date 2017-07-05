#include "stdafx.h"
#include "Human.h"
#include<string>

Human::Human() : Name("jeff")
{
}


Human::~Human()
{
}

std::string Human::About()
{
	return "Hello my name is " + this->Name;
}