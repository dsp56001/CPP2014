#pragma once
#include "Person.h"
#include "Course.h"

class Academic : public Person
{
protected:
	std::vector<Course*> *Courses;
	std::string ListCourses();
public:
	Academic();
	~Academic();

	std::string About() override;
	virtual void AddCourse(Course *);
	virtual void RemoveCourse(Course *);

};

