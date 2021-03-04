#include "course.h"
#include <iostream>

Course::Course(const std::string & name, const std::string & room, const std::shared_ptr<Teacher> & teacher, student_size maxStudents)
: _name(name), _room(room), _teacher(teacher), _maxStudents(maxStudents)
{
	_teacher.lock()->addCourse(std::make_shared<Course>(*this));
}

bool Course::enrollStudent(const std::shared_ptr<Student>& student)
{
	/* not needed when using reference. */
//	if(student == nullptr)
//		return false;

	if(_students.size() >= _maxStudents)
		return false;

	for (auto s : _students){
		if (s.lock() == student)
			return false;
	}

	_students.push_back(student);

	return true;
}

void Course::printInformation()
{

	std::cout << _name << " (" << _room << "): " << _students.size() << " students" << std::endl;
	std::cout << "Taught by "<< _teacher.lock()->getName() << "," << _teacher.lock()->getFirstName() << "("<<
			_teacher.lock()->getSalary() << ")" << std::endl;
	std::cout << "Taken by\n";
	for(auto student : _students){
		student.lock()->printInformation();
	}

}


