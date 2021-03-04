#include "person.h"

Person::Person(const std::string & name, const std::string & firstName, long long databaseID)
:_name{name},_firstName{firstName}, _databaseID{databaseID}
{}

Person::~Person(){}

const std::string &Person::getName() const
{
	return _name;
}

const std::string &Person::getFirstName() const
{
	return _firstName;
}

long long Person::getDatabaseID() const
{
	return _databaseID;
}
