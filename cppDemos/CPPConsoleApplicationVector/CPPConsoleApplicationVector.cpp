// CPPConsoleApplicationVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
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
	for (int i = 0; i < nums.size(); i++)
		std::cout << nums[i] << " ";
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums = MakeVector(100);
	PrintVector(nums);
	cin.get();
	nums = MakeRandomVector(100);
	PrintVector(nums);
	cin.get();
	return 0;
}


