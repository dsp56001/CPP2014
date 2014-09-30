#pragma once
#include "Duck.h"
#include "Rocket.h"
class RocketDuck :
	public Duck, public Rocket
{
public:
	RocketDuck();
	~RocketDuck();

	int getFlyDistance();
	int getTotalDistance();
};

