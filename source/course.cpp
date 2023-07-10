#include <iostream>
#include "course.hpp"

Course::Course(std::string courseName, int grade1, int grade2, int testGrade)
{
	this->courseName = courseName;
	this->grades[0] = grade1;
	this->grades[1] = grade2;
	this->grades[2] = testGrade;
}

Course::Course() : courseName(""), grades{0, 0, 0}{}

std::string Course::getName() const
{
	return this->courseName;
}

const int* Course::getGrades() const
{
	return this->grades;
}

void Course::setName(std::string name)
{
	this->courseName = name;
}

void Course::setGrades(int* grades)
{
	this->grades[0] = grades[0];
	this->grades[1] = grades[1];
	this->grades[2] = grades[2];
}

double Course::average() const
{
	return ((this->grades[0] + this->grades[1]) / 2) * 0.5 + this->grades[2] * 0.5;
}

std::ostream& operator<<(std::ostream & out, const Course& c)
{
	return out << "\nCourse name: " << c.getName()
		<< "\nTest grades: " << c.getGrades()[0] << ", " << c.getGrades()[1]
		<< "\nExam grade: " << c.getGrades()[2] << std::endl;
}
