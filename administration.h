#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <vector>

class Student;
class Person;
class Course;

class Administration
  {
  public:
    ~Administration();

	//delete copy ctor
	Administration(const Administration&) = delete;

	//delete copy assignment operator
	Administration & operator=(const Administration&) = delete;

    static Administration & Instance();

    void addPerson(Person * person);
    void addCourse(Course * course);
    void addStudentToCourse(Student * student, Course * course);
    void printAllPersons() const;
    void printAllCourses() const;


  private:

    Administration();

    std::vector<Person *> _persons;
    std::vector<Course *> _courses;
  };

#endif // ADMINISTRATION_H
