// CPPStrings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int stringCharacterCount(string inputString)
{
	int count =0;
	for (unsigned int i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] == 'H')
			count++;
	}
	return count;
	
}

void stringCharacterRemover(string &inputString, char charToRemove)
{
	string s = "";
	for (unsigned int i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] != charToRemove)
		{
			s.append(1, inputString[i]);
		}
	}
	inputString = s;
}

void stringCharacterReplacer(string &inputString, char charToRemove, char charToReplaceWith)
{
	string s = "";
	for (unsigned int i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] != charToRemove)
		{
			s.append(1, inputString[i]);
		}
		else
		{
			s.append(1, charToReplaceWith);
		}
	}
	inputString = s;
}



int _tmain(int argc, _TCHAR* argv[])
{
	string s = "Hello String World! How are you?";
	cout << stringCharacterCount(s) << endl;
	
	string remove = s;
	stringCharacterRemover(remove, 'H');
	cout << remove << endl;

	string replace = s;
	stringCharacterReplacer(replace, 'H', 'J');
	cout << replace << endl;

	cin.get();
	return 0;
}

