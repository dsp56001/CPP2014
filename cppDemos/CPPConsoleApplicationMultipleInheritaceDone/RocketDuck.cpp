#include "stdafx.h"
#include "RocketDuck.h"


RocketDuck::RocketDuck()
{
}


RocketDuck::~RocketDuck()
{
}

int RocketDuck::getFlyDistance()
{
	return this->Duck::getFlyDistance() + this->Rocket::getFlyDistance();
}

int RocketDuck::getTotalDistance()
{
	return this->getFlyDistance() + this->Duck::getSwimDistance();
}
