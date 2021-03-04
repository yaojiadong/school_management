#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
class Person
{
public:
	Person(const std::string & name, const std::string & firstname, long long databaseID);
	virtual ~Person();

	virtual void printInformation() const {std::cout<<"Here is Person base class\n";}

	// getters and setters
	const std::string & getName() const;
	const std::string & getFirstName() const;
	long long getDatabaseID() const;

private:
	std::string _name;
	std::string _firstName;
	long long _databaseID;
};

#endif // PERSON_H
