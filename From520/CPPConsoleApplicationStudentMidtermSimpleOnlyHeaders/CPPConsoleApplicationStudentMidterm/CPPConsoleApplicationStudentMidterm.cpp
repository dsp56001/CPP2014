// CPPConsoleApplicationStudentMidterm.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

using namespace std;

void Swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Courseinator 9000" << endl;

	//cout << "Create two courses" << endl;

	//create two courses
	//Course * oop = new Course();
	//oop->CourseName = "Object Oriented Programming";
	//oop->CourseNumber = "36-2600";

	//Course * eng = new Course("English 101", "101");


	////create faculty and students
	//Faculty * f = new Faculty();

	//Student *s = new Student();
	//s->Name = "Student1";

	//Student *ss = new Student();
	//ss->Name = "Student2";

	////Show about for courses in console
	//cout << oop->About();
	//cout << eng->About();
	//
	////Add some courses for faculty the faculty AddCourse should also adjust the Employee hours
	//f->AddCourse(oop);
	//f->AddCourse(eng);

	////Add some courses for students
	//s->AddCourse(oop);
	//ss->AddCourse(oop);

	//s->AddCourse(eng);

	////Show about for students in console
	//cout << f->About() << endl;
	//cout << s->About() << endl;
	//cout << ss->About() << endl;

	////Remove course from first student
	//s->RemoveCourse(oop);
	//f->Grade(*s);			//faculty should also grade
	//cout << s->About() << endl;


	int x = 4;
	if ((x % 2 == 0) && (x != 12))
	{ 
		cout << "Yes!" << endl;
	}
	

	////clean up
	//delete f;
	//delete s;
	//delete ss;
	//delete eng;
	//delete oop;
	int y;

	x = 10;
	y = 20;
	Swap(x, y);

	cout << x << " " << y << endl;

	////done
	cin.get();

	return 0;
}




