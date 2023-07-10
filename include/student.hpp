#pragma once
#include <string>
#include "course.hpp"

class Student
{
	std::string name;
	int numOfCourses;
	Course* coursesList;
	double averageStudent;
public:
	Student(std::string, int, Course*);
	Student();
	std::string getName() const;
	int getNumberOfCourses() const;
	double averageCalculator() const;
	double average();
	friend std::ostream& operator<< (std::ostream&, const Student);
};