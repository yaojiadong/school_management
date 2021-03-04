#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"
#include <vector>

class Course;
class Student;

class Teacher : public Person
  {
  public:
    Teacher(const std::string & name, const std::string & firstName, long databaseID);

    // getters & setters
    float getSalary() const;
    void increaseSalary(float payRaise);

    void printInformation() const;

  private:
    float _salary;
    std::vector<const Course *> _courses;
  };

#endif // TEACHER_H
