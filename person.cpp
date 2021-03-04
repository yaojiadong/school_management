#include "person.h"

Person::Person(const std::string & name, const std::string & firstName, int databaseID)
  {
  _name = name;
  _firstName = firstName;
  _databaseID = databaseID;
  }

Person::~Person()
  {
  }

const std::string &Person::getName() const
  {
  return _name;
  }

const std::string &Person::getFirstName() const
  {
  return _firstName;
  }

int Person::getDatabaseID() const
  {
  return _databaseID;
  }
