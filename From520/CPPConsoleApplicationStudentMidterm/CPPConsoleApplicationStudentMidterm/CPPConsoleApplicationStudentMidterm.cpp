// CPPConsoleApplicationStudentMidterm.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Faculty.h"
#include "Student.h"
#include "Course.h"



using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Faculty * f = new Faculty();

	Student *s = new Student();
	s->Name = "Student1";

	Student *ss = new Student();
	ss->Name = "Student2";


	Course * oop = new Course();
	oop->CourseName = "Object Oriented Programming";
	oop->CourseNumber = "36-2600";

	Course * eng = new Course("English 101","101" );
	

	f->AddCourse(oop);
	f->AddCourse(eng);

	s->AddCourse(oop);
	ss->AddCourse(oop);

	s->AddCourse(eng);

	cout << f->About() << endl;
	cout << s->About() << endl;

	s->RemoveCourse(oop);

	cout << oop->About();

	cin.get();
	return 0;
}

