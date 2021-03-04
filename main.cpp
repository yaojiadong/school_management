#include "course.h"
#include "person.h"
#include "program.h"
#include "teacher.h"
#include "student.h"
#include "administration.h"

int main()
{
	Administration::Create();
	auto * administration = Administration::Instance();

	Teacher *wouter, *danny;
	Student *paul, *wen;
	Course *statistics;

	wouter = new Teacher{"Smiths", "Wouter", 10};
	danny = new Teacher("Van Bever", "Danny", 1);
	paul = new Student("Joe", "Paul", 25002563);
	wen = new Student("Sun", "Wen", 998877665544332211);

	statistics = new Course("Statistics", "Aula", danny,20);

	administration->addPerson(wouter);
	administration->addPerson(wen);
	administration->addPerson(paul);
	administration->addPerson(danny);
	administration->addCourse(statistics);

	danny->increaseSalary(20000.0f);
	danny->printInformation();

	administration->printAllPersons();

	administration->addStudentToCourse(wen, statistics);
	administration->addStudentToCourse(paul, statistics);

	statistics->printInformation();

	Administration::Destroy();


	return 0;
}
