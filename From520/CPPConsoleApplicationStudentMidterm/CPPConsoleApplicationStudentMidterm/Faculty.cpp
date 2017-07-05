#include "stdafx.h"
#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{
}


Faculty::~Faculty()
{
}

string Faculty::About()
{
	string about = "";
	string toReplace = "Academic";
	about += Academic::About().replace(Academic::About().find(toReplace), toReplace.length(), "Instructor");
	return about;

}

void Faculty::AddCourse(Course *c)
{
	Academic::AddCourse(c);	//call base class
	c->AddInstructor(this);	//Add faculty pointer to course
}

void Faculty::RemoveCourse(Course *c)
{
	Academic::RemoveCourse(c);	//call base class
	c->RemoveInstructor(this);	//Add faculty pointer to course
}

void Faculty::Grade()
{
	for (auto c : *Courses)
	{
		
	}
}
