#include "course.h"
#include "person.h"
#include "program.h"
#include "teacher.h"
#include "student.h"
#include "administration.h"

int main()
{
	Teacher *wouter, *danny;
	Student *paul, *wen;
	Course *statistics;

	wouter = new Teacher{"Smiths", "Wouter", 10};
	danny = new Teacher("Van Bever", "Danny", 1);
	paul = new Student("Joe", "Paul", 25002563);
	wen = new Student("Sun", "Wen", 998877665544332211);

	statistics = new Course("Statistics", "Aula", danny,20);

	Administration::Instance().addPerson(wouter);
	Administration::Instance().addPerson(wen);
	Administration::Instance().addPerson(paul);
	Administration::Instance().addPerson(danny);
	Administration::Instance().addCourse(statistics);

	danny->increaseSalary(20000.0f);
	danny->printInformation();

	Administration::Instance().printAllPersons();

	Administration::Instance().addStudentToCourse(wen, statistics);
	Administration::Instance().addStudentToCourse(paul, statistics);

	statistics->printInformation();

	return 0;
}
