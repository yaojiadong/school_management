#include "course.h"
#include <iostream>

Course::Course(const std::string & name, const std::string & room, const Teacher * teacher, student_size maxStudents)
  : _name(name), _room(room), _teacher(teacher), _maxStudents(maxStudents)
  {
  }

bool Course::enrollStudent(const Student * student)
  {
  if(student == nullptr)
    return false;

  if(_students.size() >= _maxStudents)
    return false;

  for (const Student * s : _students)
    {
    if (s == student)
      return false;
    }

  _students.push_back(student);

  return true;
  }

void Course::printInformation()
  {
  std::cout << _name << " (" << _room << "): " << _students.size() << " students" << std::endl;
  std::cout << "Taught by "<< _teacher->getName() << "," << _teacher->getFirstName() << "("<<
		  _teacher->getSalary() << ")" << std::endl;
  std::cout << "Taken by\n";
  for(auto student : _students){
	  student->printInformation();
  }

  }


