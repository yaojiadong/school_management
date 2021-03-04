#include "administration.h"

#include "person.h"
#include "course.h"
#include "student.h"

#include <iostream>

//Administration Administration::_instance = 0;

Administration::Administration()
{
}

Administration::~Administration()
{
//	for(Person * person : _persons)
//		delete person;
//
//	for(Course * course : _courses)
//		delete course;
}

void Administration::Create()
{
//	if(_instance != 0)
//		return;
//
//	_instance = new Administration();

}

void Administration::Destroy()
{
//	delete _instance;
//	_instance = 0;
}

Administration& Administration::Instance()
{
	static Administration instance;
	return instance;
}

void Administration::addPerson(const std::shared_ptr<Person>& person)
{
	// check that we don't have two persons with the same name
	for(auto curPerson : _persons)
	{
		if(curPerson->getName() == person->getName() &&
				curPerson->getFirstName() == person->getFirstName())
			return;
	}

	_persons.push_back(person);
}

void Administration::addCourse(const std::shared_ptr<Course>& course)
{
	// check that we don't have two courses with the same name
	for(auto curCourse : _courses)
	{
		if(curCourse->name() == course->name())
			return;
	}

	_courses.push_back(course);
}

void Administration::addStudentToCourse(const std::shared_ptr<Student>& student, const std::shared_ptr<Course>& course)
{
	course->enrollStudent(student);//
	student->addCourse(course);


}

void Administration::printAllPersons() const
{
	for(auto person : _persons)
		person->printInformation();
}

void Administration::printAllCourses() const
{
	for(auto course : _courses)
		course->printInformation();
}
