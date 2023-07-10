#pragma once
#include<string>

class Course
{
	std::string courseName;
	int grades[3];
	
public:
	Course(std::string, int, int, int);
	Course();
	std::string getName() const;
	const int* getGrades() const;
	void setName(std::string);
	void setGrades(int*);
	double average() const;
	friend std::ostream& operator<<(std::ostream& out, const Course& c);
};