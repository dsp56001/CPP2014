#pragma once
#include "Academic.h"
#include "Employee.h"

class Faculty : public Academic, public Employee
	
{
public:
	Faculty();
	~Faculty();

	std::string About() override;
	void Grade(Student&);
	void AddCourse(Course *) override;
	void RemoveCourse(Course *) override;
};

