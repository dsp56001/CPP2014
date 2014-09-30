#include "stdafx.h"
#include "Rocket.h"


Rocket::Rocket() : m_FlyDistance(0),
	m_FuelAmount(20),
	m_Speed(5),
	m_isLanuched(false)
{
}


Rocket::~Rocket()
{
}

void Rocket::Launch()
{
	this->m_isLanuched = true;
}
void Rocket::Fly()
{
	//Rockets only fly after they are launced
	if (!m_isLanuched)
	{
		return;
	}

	//Fly at speed if there is enough fuel
	if (m_FuelAmount > m_Speed)
	{
		this->m_FlyDistance += this->m_Speed;
		this->m_FuelAmount -= m_Speed;
	}
	else // fly as far as fuel allows
	{
		this->m_FuelAmount = 0;
		this->m_FlyDistance += this->m_FuelAmount;
	}
}

int Rocket::getFlyDistance()
{
	return this->m_FlyDistance;
}