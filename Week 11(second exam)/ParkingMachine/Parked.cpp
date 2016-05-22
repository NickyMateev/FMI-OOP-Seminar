#include "Parked.h"

Parked::Parked()
{
  strcpy(regno, "00000000");
  time = 0;
}

Parked::Parked(char* regno, int time)
{
  assert(("Invalid register number!", strlen(regno) == 8));

  strcpy(this->regno, regno);
  this->time = time;
}

const char* Parked::getRegno()
{
  return regno;
}

int Parked::getTime()
{
  return time;
}
