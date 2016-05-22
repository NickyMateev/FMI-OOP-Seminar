#pragma once
#include <iostream>
#include <cassert>
#include <cstring>

const int REG_LENGTH = 9;

class Parked
{
  char regno[REG_LENGTH];
  int time;
  public:
  Parked();
  Parked(char* regno, int time);

  const char* getRegno();
  int getTime();
};
