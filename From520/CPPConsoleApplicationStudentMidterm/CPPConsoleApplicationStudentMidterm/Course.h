#pragma once
class Faculty;
class Student;

class Course
{
protected:
	std::string Course::ListInstructors();
	std::string Course::ListStudents();
	std::vector<Faculty*> *Instructors;
	std::vector<Student*> *Students;
	
public:
	Course();
	Course(std::string CourseName, std::string CourseNumber);
	~Course();
	std::string CourseName;
	std::string CourseNumber;
	int Hours;
	
	void AddInstructor(Faculty*);
	void AddStudent(Student*);
	void RemoveInstructor(Faculty*);
	void RemoveStudent(Student*);

	std::string About();
};

