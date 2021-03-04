#include "teacher.h"
#include "course.h"
#include <iostream>

Teacher::Teacher(const std::string & name, const std::string & firstName, long long databaseID)
: Person(name, firstName, databaseID), _salary{20000.0f}
{
}

float Teacher::getSalary() const
{
	return _salary;
}

void Teacher::increaseSalary(float payRaise)
{
	_salary += payRaise;
}

void Teacher::printInformation() const
{
	std::cout << getName() << ", " << getFirstName() << " (" << _salary << ")" << std::endl;
	for(auto course:_courses)
		std::cout << course->room()<<std::endl;
}

