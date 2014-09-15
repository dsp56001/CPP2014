// CPPConsoleApplicationVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

vector<int> MakeVector(int size)
{
	vector<int> numbers;
	for (int i = 0; i < size; i++)
	{
		numbers.insert(numbers.begin() + i,i);
	}
	return numbers;
}

vector<int> MakeRandomVector(int size)
{
	vector<int> numbers;
	for (int i = 0; i < size; i++)
	{
		numbers.insert(numbers.begin() + i, std::rand());
	}
	return numbers;
}


void PrintVector(vector<int> &nums)
{
	//Old way
	/*
	for (int i = 0; i < nums.size(); i++)
		std::cout << nums[i] << " ";
	*/

	//With STL interator
	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
		cout << (*iter) << " ";
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums = MakeVector(100);
	PrintVector(nums);
	cin.get();
	

	//Add 101 to end of nums vector
	nums.push_back(100);

	//Add -1 ro begining using begin() iterator
	nums.insert(nums.begin(), -1);

	//Add to 42 to end of nums Vector using end() iterator
	//nums.insert(nums.end() + 1, 42);		//Assert fails?
	PrintVector(nums);
	cin.get();

	//Remove number at index 0 of nums vector
	nums.erase(nums.begin());  //begins() returns STL interator at begining of vector
	nums.erase(nums.begin() + 1);

	//while with iterator
	vector<int>::iterator itr = nums.begin();
	while (itr != nums.end())
	{
		cout << *itr << " ";
		itr++;
	}

	nums = MakeRandomVector(100);
	PrintVector(nums);
	cin.get();

	list<int> lnums{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	

	return 0;
}


