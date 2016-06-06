#include "ContactBook.h"

void ContactBook::swap(Contact& contact1, Contact& contact2)
{
  Contact temp = contact1;
  contact1 = contact2;
  contact2 = temp;
}

void ContactBook::resize()
{
  int newCap = this->capacity * RESIZE_COEF_CONTACTS;

  Contact* newContacts = new Contact[newCap];
  for(int i = 0; i < this->capacity; i++)
    newContacts[i] = this->contacts[i];

  this->destroy();

  this->contacts = newContacts;
  this->capacity = newCap;
}

void ContactBook::copy(const ContactBook& other)
{
  this->capacity = other.capacity;
  this->contactsCount = other.contactsCount;
  this->contacts = new Contact[other.capacity];

  for(int i = 0; i < other.contactsCount; i++)
  {
    this->contacts[i] = other.contacts[i];
    this->names.add(this->contacts[i].getName(), &(this->contacts[i]));
    this->numbers.add(this->contacts[i].getNumber(), &(this->contacts[i]));
    this->ids.add(this->contacts[i].getID(), &(this->contacts[i]));
  }
}

void ContactBook::destroy()
{
  delete[] this->contacts;
}

void ContactBook::sort(UserChoice choice)
{

  for(int i = 0; i < this->contactsCount - 1; i++)
  {
    for(int j = 0; j < this->contactsCount - 1 - i; j++)
    {
      if(choice == NAME)
      {
        if(this->contacts[i].getName().compare(this->contacts[i + 1].getName()) > 0)
          this->swap(this->contacts[i], this->contacts[i + 1]);
      }
      else if (choice == NUMBER)
      {
        if(this->contacts[i].getNumber().compare(this->contacts[i + 1].getNumber()) > 0)
          this->swap(this->contacts[i], this->contacts[i + 1]);
      }
      else
      {
        if(this->contacts[i].getID().compare(this->contacts[i + 1].getID()) > 0)
          this->swap(this->contacts[i], this->contacts[i + 1]);
      }
    }
  }

}

void ContactBook::shift(int index)
{
  for(; index < this->contactsCount - 1; index++)
    this->contacts[index] = this->contacts[index + 1];
}

void ContactBook::remove(UserChoice choice, std::string userInput)
{
  for(int i = 0; i < this->contactsCount; i++)
  {
    if((choice == NAME && this->contacts[i].getName().compare(userInput) == 0) || (choice == NUMBER && this->contacts[i].getNumber().compare(userInput) == 0) || (choice == ID && this->contacts[i].getID().compare(userInput) == 0))
    {
      names.remove(this->contacts[i].getName());
      numbers.remove(this->contacts[i].getNumber());
      ids.remove(this->contacts[i].getID());

      shift(i);
      this->contactsCount--;

      break;
    }
  }
}

ContactBook::ContactBook()
{
  this->capacity = DEFAULT_CAP_CONTACTS;
  this->contactsCount = 0;
  this->contacts = new Contact[DEFAULT_CAP_CONTACTS];
}

ContactBook::ContactBook(const ContactBook& other)
{
  this->copy(other);
}

ContactBook& ContactBook::operator=(const ContactBook& other)
{
  if(this != &other)
  {
    this->destroy();
    this->copy(other);
  }
  return *this;
}

ContactBook::~ContactBook()
{
  this->destroy();
}

void ContactBook::addContact(const Contact& contact)
{
  if(this->contactsCount == this->capacity)
    this->resize();

  this->contacts[this->contactsCount] = contact;
  this->names.add(this->contacts[this->contactsCount].getName(), &(this->contacts[this->contactsCount]));
  this->numbers.add(this->contacts[this->contactsCount].getNumber(), &(this->contacts[this->contactsCount]));
  this->ids.add(this->contacts[this->contactsCount].getID(), &(this->contacts[this->contactsCount]));

  this->contactsCount++;
}

const Contact* ContactBook::getContactByName(std::string name) const
{
  return this->names.getValue(name);
}

const Contact* ContactBook::getContactByNumber(std::string number) const
{
  return this->numbers.getValue(number);
}

const Contact* ContactBook::getContactByID(std::string ID) const
{
  return this->ids.getValue(ID);
}

std::ostream& operator<<(std::ostream& os, const ContactBook& obj)
{
  for(int i = 0; i < obj.contactsCount; i++)
  {
    std::cout << "Contact #" << i + 1 << ":" << std::endl;
    os << obj.contacts[i] << std::endl;
    std::cout<<std::endl;
  }
  return os;
}

void ContactBook::printContactBookByNames() const
{
  ContactBook temp(*this);
  temp.sort(NAME);

  std::cout << temp << std::endl;
}

void ContactBook::printContactBookByNumbers() const
{
  ContactBook temp(*this);
  temp.sort(NUMBER);

  std::cout << temp << std::endl;
}

void ContactBook::printContactBookByIDs() const
{
  ContactBook temp(*this);
  temp.sort(ID);

  std::cout << temp << std::endl;
}

void ContactBook::removeContactByName(std::string name)
{
  remove(NAME, name);
}

void ContactBook::removeContactByNumber(std::string number)
{
  remove(NUMBER, number);
}

void ContactBook::removeContactByID(std::string id)
{
  remove(ID, id);
}
