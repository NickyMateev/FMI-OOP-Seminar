#include "Contact.h"
#include <cassert>

Contact::Contact()
{
  this->name = "Unknown name";
  this->number = "Unknown number";
  this->ID = "No ID";
}

Contact::Contact(std::string name, std::string number, std::string ID)
{
  assert(("Invalid number! Number can contain 10 digits maximum.", number.length() <= 10));

  this->name = name;
  this->number = number;
  this->ID = ID;
}

std::string Contact::getName() const
{
  return this->name;
}

std::string Contact::getNumber() const
{
  return this->number;
}

std::string Contact::getID() const
{
  return this->ID;
}

void Contact::setName(std::string name)
{
  this->name = name;
}

void Contact::setNumber(std::string number)
{
  this->number = number;
}

void Contact::setID(std::string ID)
{
  this->ID = ID;
}

std::ostream& operator<<(std::ostream& os, const Contact& obj)
{
  os << "Name: " << obj.name << std::endl;
  os << "Phone number: " << obj.number << std::endl;
  os << "ID: " << obj.ID;

  return os;
}
