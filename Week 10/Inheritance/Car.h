#pragma once
#include "V.h"

class Car : public V
{
  char* brand;
public:
  Car(int speed, int cargo, char* ppl, char* brand = NULL);
  Car(const Car& other);
  Car& operator=(const Car& other);
  ~Car();
};
