#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "teacher.h"
#include "student.h"

//class Student;
//class Teacher;

class Course
{
	using student_size = std::vector<const Student *>::size_type;
public:
	Course(const std::string & name, const std::string & room, const Teacher * teacher, student_size maxStudents);

	bool enrollStudent(const Student * student);
	void printInformation();

	// getters and setters
	const std::string & name() const				{ return _name; }
	const std::string & room() const				{ return _room; }
	student_size maxStudents() const					{ return _maxStudents; }
	const Teacher *  teacher() const				{ return _teacher; }
	const std::vector<const Student *> & students() const	{ return _students; }
	void setRoom(const std::string & room)			{ _room = room; }


private:
	std::string _name;
	std::string _room;
	const Teacher * _teacher;
	student_size _maxStudents;

	std::vector<const Student *> _students;
};

#endif // COURSE_H
