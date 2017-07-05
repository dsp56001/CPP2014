#pragma once
#include "Academic.h"

class Faculty : public Academic
	
{
public:
	Faculty();
	~Faculty();

	std::string About() override;
	void AddCourse(Course *) override;
	void RemoveCourse(Course *) override;
	void Grade();
};

