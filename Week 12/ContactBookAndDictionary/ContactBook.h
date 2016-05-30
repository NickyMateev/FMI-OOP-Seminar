#pragma one
#include "Contact.h"
#include "Dictionary.h"
#include "UserChoice.h"

const int DEFAULT_CAP_CONTACTS = 32;
const int RESIZE_COEF_CONTACTS = 1.5;

class ContactBook
{
  private:
    Contact* contacts;
    int contactsCount;
    int capacity;

    Dictionary<std::string, Contact*> names;
    Dictionary<std::string, Contact*> numbers;
    Dictionary<std::string, Contact*> ids;

    void resize();
    void copy(const ContactBook& other);
    void destroy();
    void sort(UserChoice choice);
    void shift(int index);
    void remove(UserChoice choice, std::string userInput);

  public:
    ContactBook();
    ContactBook(const ContactBook& other);
    ContactBook& operator=(const ContactBook& other);
    ~ContactBook();

    void addContact(const Contact& contact);
    const Contact* getContactByName(std::string name) const;
    const Contact* getContactByNumber(std::string number) const;
    const Contact* getContactByID(std::string id) const;

    friend std::ostream& operator<<(std::ostream& os, const ContactBook& obj);

    void printContactBookByNames() const;
    void printContactBookByNumbers() const;
    void printContactBookByIDs() const;

    void removeContactByName(std::string name);
    void removeContactByNumber(std::string number);
    void removeContactByID(std::string ID);
};

