#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "program.h"
#include <vector>
#include <memory>

class Course;


class Student : public Person
{
public:
	Student(const std::string & name, const std::string & firstName, long long databaseID);

	void changeProgram(Program program);
	Program getProgram();

	void printInformation() const override;
	void printSchedule() const;

	bool addCourse(const std::shared_ptr<Course>& course);

	bool operator==(Student& student){
		if(this->getDatabaseID() == student.getDatabaseID()) return true;

		return false;
	}

private:
	Program _program{Invalid}; //default value
	std::vector<std::shared_ptr<Course>> _courses;
};

#endif // STUDENT_H
