#include "course.h"
#include "person.h"
#include "program.h"
#include "teacher.h"
#include "student.h"
#include "administration.h"

int main()
{
//	auto administration = Administration::Instance(); //copy ctor is deleted

//	std::shared_ptr<Teacher> wouter{new Teacher{"Smiths", "Wouter", 10}};
//	std::shared_ptr<Teacher> danny{new Teacher{"Van Bever", "Danny", 1}};
//	std::shared_ptr<Student> paul{new Student{"Joe", "Paul", 25002563}};
//	std::shared_ptr<Student> wen{new Student{"Sun", "Wen", 998877665544332211}};

	std::shared_ptr<Teacher> danny = std::make_shared<Teacher>("Van Bever", "Danny", 1);
	std::shared_ptr<Teacher> wouter = std::make_shared<Teacher>("Smiths", "Wouter", 10);
	std::shared_ptr<Student> paul = std::make_shared<Student>("Joe", "Paul", 25002563);
	std::shared_ptr<Student> wen= std::make_shared<Student>("Sun", "Wen", 998877665544332211);

	std::shared_ptr<Course> statistics{new Course{"Statistics", "Aula", danny, 20}};

	Administration::Instance().addPerson(wouter);
	Administration::Instance().addPerson(wen);
	Administration::Instance().addPerson(paul);
	Administration::Instance().addPerson(danny);
	Administration::Instance().addCourse(statistics);

	Administration::Instance().printAllPersons();

	statistics->setRoom("ALMA");
	danny->increaseSalary(20000.0f);
	danny->printInformation();

	Administration::Instance().printAllPersons();
	Administration::Instance().addStudentToCourse(wen, statistics);
	Administration::Instance().addStudentToCourse(paul, statistics);


	statistics->printInformation();

	return 0;
}
