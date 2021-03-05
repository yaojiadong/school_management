#include "student.h"
#include "course.h"
#include <iostream>
#include <algorithm>

Student::Student(const std::string & name, const std::string & firstName, long long databaseID)
: Person(name, firstName, databaseID)
{}


void Student::changeProgram(Program program){
	_program = program;
}

Program Student::getProgram(){
	return _program;
}

void Student::printInformation() const{
	std::cout << getDatabaseID() << ": " << getFirstName() << " " << getName() << " (" << _courses.size() << ")" << std::endl;
}

void Student::printSchedule() const{
	for(auto c :_courses){
		std::cout << c->name() << " " << c->room() << std::endl;
	}
}

bool Student::addCourse(const std::shared_ptr<Course>& course)
{
	/*todo: needed?*/
	if(course == nullptr)
		return false;

	if(std::find(_courses.begin(),_courses.end(), course) != _courses.end())
		return false;

	_courses.push_back(course);

	return true;
}
