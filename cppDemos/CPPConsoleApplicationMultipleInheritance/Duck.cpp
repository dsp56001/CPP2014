#include "stdafx.h"
#include "Duck.h"
#include <string>

using namespace std;

Duck::Duck() : m_FlyDistance(0), 
	m_QuackSound("quack"),
	m_SwimDistance(0)
{
}

Duck::~Duck()
{
}

void Duck::Fly()
{ 
	this->m_FlyDistance++;
}
void Duck::Swim()
{
	this->m_SwimDistance++;
}

string Duck::Quack()
{
	return this->m_QuackSound;
}

int Duck::getTotalDistance()
{
	return this->getFlyDistance() + this->getSwimDistance();
}
int Duck::getFlyDistance()
{
	return this->m_FlyDistance;
}
int Duck::getSwimDistance()
{
	return this->m_SwimDistance;
}
