// CPPConsoleApplicationPerfectNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Determine perfect numbers between 1 and 1000.
// A number is perfect if it is equal to the sum of its factors.
#include <iostream>
#include <vector>
using namespace std;

bool isPerfect(int); // function prototype
void printSum(int); // function prototype

vector<int> perfects;

int _tmain(int argc, _TCHAR* argv[])
{
	const int MAX = 100000;
	
	cout << "Perfect integers between 1 and " << MAX <<":" << endl;

	// loop from 2 to 1000
	for (int j = 2; j <= MAX; j++)
	{
		// if current integer is perfect 
		if (isPerfect(j))
			printSum(j); // print it as sum of factors
	} // end for

	cout << endl << "Done" << endl;
	cin.get();
	return 0; // indicate successful termination
}


// isPerfect returns true if value is perfect integer,
// i.e., if value is equal to sum of its factors
bool isPerfect(int value)
{
	int factorSum = 1; // current sum of factors

	// loop through possible factor values
	for (int i = 2; i <= value / 2; i++)
	{
		// if i is factor
		if (value % i == 0)
			factorSum += i; // add to sum
	} // end for

	// return true if value is equal to sum of factors
	if (factorSum == value) 
		return true;
	
	return false;
} // end function isPerfect

// printSum displays value followed by factors in summation form
void printSum(int value)
{
	cout << value << " = 1";

	// loop through possible factor values
	for (int i = 2; i <= value / 2; i++)
	{
		// if i is factor
		if (value % i == 0)
			cout << " + " << i; // display as part of sum
	} // end for

	cout << endl;
} // end function printSum