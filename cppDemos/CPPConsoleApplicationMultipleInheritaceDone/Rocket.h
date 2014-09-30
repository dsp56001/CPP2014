#pragma once
class Rocket
{

protected:
	int m_FlyDistance, m_FuelAmount, m_Speed;
	bool m_isLanuched;

public:
	Rocket();
	~Rocket();

	void Launch();
	void Fly();

	int getFlyDistance();

};

