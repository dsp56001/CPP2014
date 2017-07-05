#pragma once
class Faculty;
class Student;

class Course
{
protected:
	
	
public:
	Course();
	Course(std::string CourseName, std::string CourseNumber);
	~Course();
	std::string CourseName;
	std::string CourseNumber;
	int Hours;
	
	

	std::string About();
};

