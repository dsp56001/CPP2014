#pragma once
#include <string>

class Duck
{
protected:
	std::string m_QuackSound;
	int m_FlyDistance;
	int m_SwimDistance;
	Duck();
public:
	
	~Duck();

	virtual void Fly();
	virtual void Swim();
	std::string Quack();

	int getTotalDistance();
	int getFlyDistance();
	int getSwimDistance();
};

