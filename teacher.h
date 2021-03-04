#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"
#include <vector>
#include <memory>

class Course;
class Student;

class Teacher : public Person
  {
  public:
    Teacher(const std::string & name, const std::string & firstName, long long databaseID);

    void addCourse(const std::shared_ptr<Course>& course){
    	_courses.push_back(course);
    }

    // getters & setters
    float getSalary() const;
    void increaseSalary(float payRaise);

    void printInformation() const override;

  private:
    float _salary;
    std::vector<std::shared_ptr<Course>> _courses;
  };

#endif // TEACHER_H
