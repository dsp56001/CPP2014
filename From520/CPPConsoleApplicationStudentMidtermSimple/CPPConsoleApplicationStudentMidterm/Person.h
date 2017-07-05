#pragma once
class Person
{
protected:

public:
	Person();
	~Person();

	std::string Name;
	int Age;

    virtual std::string About();
};

