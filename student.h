#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "program.h"
#include <vector>

class Course;


class Student : public Person
{
public:
	Student(const std::string & name, const std::string & firstName, long long databaseID);

	void changeProgram(Program program);
	Program getProgram();

	void printInformation() const;
	void printSchedule() const;

	bool addCourse(const Course * course);

private:
	Program _program{Invalid}; //default value
	std::vector<const Course *> _courses;
};

#endif // STUDENT_H
