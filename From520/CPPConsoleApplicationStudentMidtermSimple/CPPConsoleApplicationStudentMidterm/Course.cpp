#include "stdafx.h"
#include "Course.h"
#include "Faculty.h"
#include "Student.h"

using namespace std;

Course::Course() : Hours(3)
{

}

Course::Course(string CourseName, string CourseNumber) : Hours(3)
{
	
	this->CourseName = CourseName;
	this->CourseNumber = CourseNumber;
}


Course::~Course()
{
	
}


string Course::About()
{
	string about = "\nCourse->About(): " + this->CourseName + " : " + this->CourseNumber;
	return about;
}