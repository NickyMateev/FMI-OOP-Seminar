#pragma once
#include <iostream>

class Contact
{
  private:
    std::string name;
    std::string number;
    std::string ID;
  public:
    Contact();
    Contact(std::string name, std::string number, std::string ID);

    std::string getName() const;
    std::string getNumber() const;
    std::string getID() const;

    void setName(std::string name);
    void setNumber(std::string number);
    void setID(std::string ID);

    friend std::ostream& operator<<(std::ostream& os, const Contact& obj);
};
