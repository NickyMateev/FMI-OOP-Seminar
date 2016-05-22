#include "Car.h"

Car::Car(int speed, int cargo, char* ppl, char* brand) : V(speed, cargo, ppl)
{
  mystrcpy(this->brand, brand);
}

Car::Car(const Car& other) : V(other)
{
  mystrcpy(this->brand, other.brand);
}

Car& Car::operator=(const Car& other)
{
  if(this != &other)
  {
    V::operator=(other);

    delete[] this->brand;
    mystrcpy(this->brand, other.brand);
  }
  return *this;
}

Car::~Car()
{
  delete[] brand;
}
