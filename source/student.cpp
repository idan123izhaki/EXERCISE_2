#include<iostream>
#include "student.hpp"

Student::Student(std::string name, int num, Course* coursesList) :
	name(name), numOfCourses(num), coursesList(coursesList), averageStudent(-1) {}

Student::Student() : name(""), numOfCourses(0), coursesList(nullptr), averageStudent(-1) {}


std::string Student::getName() const
{
	return this->name;
}

int Student::getNumberOfCourses() const
{
	return this->numOfCourses;
}

double Student::averageCalculator() const
{
	int magicBonus = 0;
	double sum = 0;
	char lastChar, firstChar;
	std::string currentCourseName;
	for (int i = 0; i < this->numOfCourses; i++) {
		sum += this->coursesList[i].average();
		currentCourseName = this->coursesList[i].getName();
		lastChar = currentCourseName.at(currentCourseName.length() - 1);
		firstChar = currentCourseName.at(0);
		if (lastChar == 'y') magicBonus += 1;
		else if (lastChar == 'h') magicBonus += 5;
		if (firstChar == 'e') magicBonus += 2;
	}
	int randomBonus = int(rand() % 11);
	return (sum + randomBonus + magicBonus) / this->numOfCourses;
}

double Student::average()
{
	if (this->averageStudent == -1)
		this->averageStudent = averageCalculator();
	return this->averageStudent;
}


std::ostream& operator<< (std::ostream& out, const Student s)
{
	out << "Student name: " << s.getName() <<
		"\nNumber of courses: " << s.getNumberOfCourses() <<
		"\nAll the courses:";
	for (int i = 0; i < s.getNumberOfCourses(); i++)
		out << s.coursesList[i];
	return out;
}
