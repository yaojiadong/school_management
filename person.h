#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
  {
  public:
    Person(const std::string & name, const std::string & firstname, int databaseID);
    virtual ~Person();

    virtual void printInformation() const {}

    // getters and setters
    const std::string & getName() const;
    const std::string & getFirstName() const;
    int getDatabaseID() const;

  private:
    std::string _name;
    std::string _firstName;
    int _databaseID;
  };

#endif // PERSON_H
