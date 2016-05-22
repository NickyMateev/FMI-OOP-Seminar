#include "V.h"

V::V(int maxSpeed, int cargo, char* ppl)
{
  this->maxSpeed = maxSpeed;
  this->cargo = cargo;
  mystrcpy(this->ppl, ppl);
}

V::V(const V& other)
{
  this->maxSpeed = other.maxSpeed;
  this->cargo = other.cargo;
  mystrcpy(this->ppl, other.ppl);
}

V& V::operator=(const V& other)
{
  if(this != &other)
  {
    delete[] this->ppl;

    this->maxSpeed = other.maxSpeed;
    this->cargo = other.cargo;
    mystrcpy(this->ppl, other.ppl);

  }
  return *this;
}

V::~V()
{
  delete[] ppl;
}

int V::getSpeed()
{
  return maxSpeed;
}
