#include "stdafx.h"
#include "Student.h"

using namespace std;

Student::Student()
{
}


Student::~Student()
{
}

string Student::About()
{
	string toReplace = "an Academic";
	return Academic::About().replace(Academic::About().find(toReplace), toReplace.length(), "a Student");

}

void Student::AddCourse(Course *c)
{
	Academic::AddCourse(c);	//call base class
	c->AddStudent(this);	//Add Student pointer to course
}

void Student::RemoveCourse(Course *c)
{
	Academic::RemoveCourse(c);	//call base class
	c->RemoveStudent(this);	//Add faculty pointer to course
}