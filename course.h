#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <memory>
#include "teacher.h"
#include "student.h"

/*
 * https://stackoverflow.com/questions/38298008/possible-memory-leaks-with-smart-pointers
 * https://stackoverflow.com/questions/1826902/how-to-avoid-memory-leak-with-shared-ptr
 *
 * Smart pointers based on reference counting (such as shared_ptr) will delete the
 * pointed-to-object when the reference count associated with the object drops to zero.
 * But if you have a cycle in your references (A->B->A, or some more elaborate cycle),
 * then the reference counts in the cycle will never drop to zero because the smart
 * pointers are "keeping each other alive".
 *
 * In this project, Student and course have circular reference, Teacher and Course have circular reference.
 * To break the cycle, store weak_ptr in Course for Student and Teacher.
 */

class Course
{

public:
	using student_size = std::vector<Student>::size_type;

	Course(const std::string & name, const std::string & room, const std::shared_ptr<Teacher>& teacher, student_size maxStudents);

	bool enrollStudent(const std::shared_ptr<Student>& student);
	void printInformation();

	// getters and setters
	const std::string & name() const				{ return _name; }
	const std::string & room() const				{ return _room; }
	student_size maxStudents() const					{ return _maxStudents; }
	const std::weak_ptr<Teacher> &  teacher() const				{ return _teacher; }
	const std::vector<std::weak_ptr<Student>> & students() const	{ return _students; }
	void setRoom(const std::string & room)			{ _room = room; }


	bool operator==(const Course& course){
		if(_name == course.name())  return true;

		return false;
	}

private:
	std::string _name;
	std::string _room;
	const std::weak_ptr<Teacher> _teacher;
	student_size _maxStudents;

	std::vector<std::weak_ptr<Student>> _students;
};

#endif // COURSE_H
