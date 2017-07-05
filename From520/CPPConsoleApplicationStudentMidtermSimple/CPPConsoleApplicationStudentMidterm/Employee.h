#pragma once
class Employee
{
public:
	int Hours;
	Employee();
	~Employee();

	std::string Pay();
	void AddHours(int);
	void ReduceHours(int);
};

