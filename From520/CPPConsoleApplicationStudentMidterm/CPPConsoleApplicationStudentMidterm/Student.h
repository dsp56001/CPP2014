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
	void AddCourse(Course *) override;
	void RemoveCourse(Course *) override;
};

