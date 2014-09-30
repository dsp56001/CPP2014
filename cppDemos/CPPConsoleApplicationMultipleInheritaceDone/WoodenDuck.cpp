#include "stdafx.h"
#include "WoodenDuck.h"
#include <iostream>



WoodenDuck::WoodenDuck()
{
}


WoodenDuck::~WoodenDuck()
{
}

void WoodenDuck::Fly()
{
	// no flying
	std::cout << "Wooden Ducks Don't Fly!!!" << std::endl;
}

void WoodenDuck::Swim()
{
	// no swimming
	std::cout << "Wooden Ducks Don't Swim!!!" << std::endl;
}
