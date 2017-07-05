#include "stdafx.h"
#include "Course.h"
#include "Faculty.h"
#include "Student.h"

using namespace std;

Course::Course() : Hours(3)
{
	this->Instructors = new vector<Faculty*>();
	this->Students = new vector<Student*>();
}

Course::Course(string CourseName, string CourseNumber) : Hours(3)
{
	this->Instructors = new vector<Faculty*>();
	this->Students = new vector<Student*>();
	this->CourseName = CourseName;
	this->CourseNumber = CourseNumber;
}


Course::~Course()
{
	delete Instructors;
	delete Students;
}


string Course::About()
{
	string about = this->CourseName + " : " + this->CourseNumber;
	about += "\nInstructors:\n" + this->ListInstructors();
	about += "\nStudents:\n" + this->ListStudents();
	return about;
}

string Course::ListInstructors()
{
	string about = "";
	for (auto *i : *Instructors)
	{
		about.append(i->Name + "\n");
	}
	return about;
}

string Course::ListStudents()
{
	string about = "";
	for (auto *i : *Students)
	{
		about.append(i->Name + "\n");
	}
	return about;
}

void Course::AddInstructor(Faculty* faculty)
{
	this->Instructors->push_back(faculty);
}

void Course::AddStudent(Student* student)
{
	this->Students->push_back(student);
}

void Course::RemoveInstructor (Faculty * faculty)
{
	
	for (auto it = (*Instructors).begin(); it != Instructors->end(); it++)
	{
		if ((*it) == faculty)
		{
			*Instructors->erase(it);
			break;
		}
	}
}

void Course::RemoveStudent(Student* student)
{
	for (auto it = (*Students).begin(); it != Students->end(); it++)
	{
		if ((*it) == student)
		{
			*Students->erase(it);
			break;
		}
	}
}

//vector<Student *> Course::GetStudents()
//{
//	return this->Students;
//}
