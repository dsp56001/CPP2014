#pragma once
#include "Academic.h"

class Student :
	public Academic
{
public:
	Student();
	~Student();

	bool isGraded;
	std::string About() override;
	
};

