// CPPConsoleApplicationTemplate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


template <typename Type> Type maxof(Type a, Type b)
{
	return (a > b ? a : b);
}

class CPPStudent
{
public:
	std::string name;
	int hours;
};

bool operator > (const CPPStudent& lhs, const CPPStudent& rhs)
{
	return (lhs.hours > rhs.hours ? true : false);
}

bool operator < (const CPPStudent& lhs, const CPPStudent& rhs)
{
	if (lhs.hours < rhs.hours)
		return true;
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int four = 4;
	int three = 3;
	cout << maxof<int>(four , three);
	cin.get();


	//Create new student in dynamic memory
	CPPStudent * jeff = new CPPStudent();
	jeff->hours = 10;
	jeff->name = "jeff";

	CPPStudent * sally = new CPPStudent();
	sally->hours = 12;
	sally->name = "sally";

	CPPStudent max = maxof<CPPStudent>(*jeff, *sally);
	cout << max.name.c_str() << endl;

	cin.get();

	delete jeff;		//done with Jeff pointer 
	delete sally;


	return 0;
}

