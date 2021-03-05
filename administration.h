#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <vector>
#include <memory>

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

	static Administration& Instance();

	void addPerson(const std::shared_ptr<Person>& person);
	void addCourse(const std::shared_ptr<Course>& course);
	void addStudentToCourse(const std::shared_ptr<Student>& student, const std::shared_ptr<Course>& course);
	void printAllPersons() const;
	void printAllCourses() const;


private:

	Administration();

	std::vector<std::shared_ptr<Person>> _persons;
	std::vector<std::shared_ptr<Course>> _courses;
};

#endif // ADMINISTRATION_H
