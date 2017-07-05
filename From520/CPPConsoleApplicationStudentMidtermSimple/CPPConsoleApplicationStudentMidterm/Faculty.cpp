#include "stdafx.h"
#include "Faculty.h"
#include "Student.h"

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
	about += "Faculty->About()->" + Academic::About().replace(Academic::About().find(toReplace), toReplace.length(), "Instructor");
	about += Employee::Pay();
	return about;

}

void Faculty::Grade(Student& student)
{
	student.isGraded = true;
}

void Faculty::AddCourse(Course * course)
{
	Academic::AddCourse(course);
	Employee::AddHours(course->Hours);
}

void Faculty::RemoveCourse(Course * course)
{
	Academic::RemoveCourse(course);
	Employee::ReduceHours(course->Hours);
}
