// CPPConsoleApplicationPointerHomework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

//Write a program that has a function that asks the user to input a list of names with a maximum of 50 names.
//Return number of names inputted, pass list of names as pointer.
//Use a ~to signal the end of name input.Also write a function that writes out those names to the console.

using namespace std;


vector<string> names;

void addNameToVector(string s, vector<string>& vect);
string showVector(vector<string>& vect);

int _tmain(int argc, _TCHAR* argv[])
{
	
	string enteredName;
	cout << "Please enter a names until 50" << endl;
	do 
	{
		cout << "Please enter a name (" << names.size() << "):";
		getline(cin, enteredName);
		addNameToVector(enteredName, names);
	} while ((enteredName != "~") && names.size() < 50);
	
	cout << showVector(names) << endl;;
	cin.get();
	return 0;
}

void addNameToVector(string s, vector<string>& vect)
{
	vect.push_back(s);
}

string showVector(vector<string>& vect)
{
	string out;
	for (string s : vect)
	{
		out += s + "\n";
	}
	return out;
}

