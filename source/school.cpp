#include<iostream>
#include<vector>
#include<string>
#include "course.hpp"
#include "student.hpp"


int main()
{
	//task_2

	int option, numberOfCourses, currentNumberOfStudents = 0, j = 0;
	double average = -1;
	std::string name, courseName, courseNamesList;
	std::vector<Student> school;
	Course* coursePtr = nullptr;
	int* grades = new int[3];
	while (true)
	{
		std::cout << "Welcome to Magshimim School! You have the following options:" << std::endl;
		std::cout << "1- Add new student to school\n2- Calculate average grade of all students\n3- show all students descending by their averages\n4- Exit\n\nEnter yout choice: ";
		std::cin >> option;
		if (option == 1)
		{
			std::cout << "Enter student's name: ";
			std::cin >> name;
			std::cout << "Enter number of courses for student: ";
			std::cin >> numberOfCourses;
			Course* coursePtr = new Course[numberOfCourses];
			for (int i = 0; i < numberOfCourses; i++)
			{
				std::cout << "Enter Course name: "; std::cin >> courseName;
				coursePtr[i].setName(courseName);
				std::cout << "Enter first test grade: "; std::cin >> grades[0];
				std::cout << "Enter second test grade: "; std::cin >> grades[1];
				std::cout << "Enter exam grade: "; std::cin >> grades[2];
				coursePtr[i].setGrades(grades);
				courseNamesList.append(courseName.append(" "));
			}
			Student newStudent(name, numberOfCourses, coursePtr);
			if (!school.size()) {
				school.insert(school.begin(), newStudent);
			}
			else
			{
				average = newStudent.average();
				while ((j < school.size()) && (average < school[j].average()))
					j++;
				school.insert(school.begin() + j, newStudent);
				j = 0;
			}
			school.shrink_to_fit();
			std::cout << "\nThe size of the school is: " << school.size() << std::endl;
			std::cout << "\nStudent: " << newStudent.getName() << " Courses: " << courseNamesList << std::endl;
			courseNamesList.clear();
		}
		else if (option == 2)
		{
			if (school.empty())
				std::cout << "The school is empty... please insert some students!" << std::endl << std::endl;
			else
			{
				std::cout << std::endl;
				double averageAllStudents = 0;
				for (auto itr = school.begin(); itr != school.end(); itr++)
					averageAllStudents += itr->average();
				std::cout << "The average grades of all the students in the school is: " << averageAllStudents/school.size() << std::endl << std::endl;
			}
		}
		else if (option == 3)
		{
			if (school.empty())
				std::cout << "The school is empty... please insert some students!" << std::endl << std::endl;
			else
			{
				std::cout << std::endl;
				for (auto itr = school.begin(); itr != school.end(); itr++)
					std::cout << "Student name: " << itr->getName() << ", with grade average of: " << itr->average() << std::endl;
				std::cout << std::endl;
			}
		}
		else if (option == 4)
		{
			std::cout << "You have successfully logged out,\nhave a nice day!" << std::endl;
			delete[]grades;
			for (Student& student : school) {
				delete[]student.coursesList;
			}
			break;
		}
		else
			std::cout << "\nInvalid input, please try again..." << std::endl;
	}


	return 0;
}