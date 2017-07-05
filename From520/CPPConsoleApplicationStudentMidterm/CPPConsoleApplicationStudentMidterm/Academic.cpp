#include "stdafx.h"
#include "Academic.h"


using namespace std;

Academic::Academic()
{
	this->Courses = new vector<Course*>();
}


Academic::~Academic()
{
	delete Courses;
}


string Academic::About() 
{
	return Person::About() + " I am an Academic." + "\n" + this->ListCourses();
}

void Academic::AddCourse(Course * c)
{
	this->Courses->push_back(c);
}
void Academic::RemoveCourse(Course * c)
{
	for (auto it = (*Courses).begin(); it != Courses->end(); it++)
	{
		if ((*it) == c)
		{
			*Courses->erase(it);
			break;
		}
	}
}

string Academic::ListCourses()
{
	string list = "Courses:\n";
	for (auto c : *Courses)
	{
		list += c->CourseName + "\n";
	}
	return list;
}
