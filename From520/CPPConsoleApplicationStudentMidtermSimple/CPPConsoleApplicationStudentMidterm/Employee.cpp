#include "stdafx.h"
#include "Employee.h"

using namespace std;

Employee::Employee()
{
}


Employee::~Employee()
{
}

string Employee::Pay()
{
	string pay = "Pay for " + to_string(this->Hours) + " hours\n";
	if (this->Hours <= 0)
		pay = "no hours to pay\n";
	return pay;
}

void Employee::AddHours(int hoursToAdd)
{
	this->Hours += hoursToAdd;
}

void Employee::ReduceHours(int hoursToReduce)
{
	this->Hours += hoursToReduce;
}
