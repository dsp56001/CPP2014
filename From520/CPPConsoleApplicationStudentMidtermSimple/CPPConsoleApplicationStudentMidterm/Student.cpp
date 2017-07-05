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
	string about = "Student->About()->" + Academic::About().replace(Academic::About().find(toReplace), toReplace.length(), "a Student");
	if (this->isGraded)
	{ 
		about += "I have been graded.\n";
	}
	else
	{
		about += "I have not been graded.\n";
	}
	
	return about;

}
