#pragma once
#include <iostream>
#include "myFunctions.h"

class V
{
  int maxSpeed;
  int cargo;
  char* ppl;
public:
  V(int = 0, int = 0, char* = NULL);
  V(const V&);
  V& operator=(const V&);
  ~V();

  int getSpeed();
};
