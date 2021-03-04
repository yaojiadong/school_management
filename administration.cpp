#include "administration.h"

#include "person.h"
#include "course.h"
#include "student.h"


Administration::Administration()
{
}

Administration::~Administration()
{
	for(Person * person : _persons)
		delete person;

	for(Course * course : _courses)
		delete course;
}


Administration & Administration::Instance()
{
	static Administration _instance;
	return _instance;
}

void Administration::addPerson(Person * person)
{
	// check that we don't have two persons with the same name
	for(Person * curPerson : _persons)
	{
		if(curPerson->getName() == person->getName() &&
				curPerson->getFirstName() == person->getFirstName())
			return;
	}

	_persons.push_back(person);
}

void Administration::addCourse(Course * course)
{
	// check that we don't have two courses with the same name
	for(Course * curCourse : _courses)
	{
		if(curCourse->name() == course->name())
			return;
	}

	_courses.push_back(course);
}

void Administration::addStudentToCourse(Student * student, Course * course)
{
	course->enrollStudent(student);
	student->addCourse(course);
}

void Administration::printAllPersons() const
{
	for(Person * person : _persons)
		person->printInformation();
}

void Administration::printAllCourses() const
{
	for(Course * course : _courses)
		course->printInformation();
}
