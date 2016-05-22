#include "ParkingMachine.h"

int main()
{
  ParkingMachine parkMachine;
  std::cout << "Park machine created:" << std::endl;
  std::cout << parkMachine << std::endl;

  char* regno1 = "12345678";
  char* regno2 = "87654321";
  int time1 = 12, time2 = 13;

  parkMachine.enter(regno1, time1);
  parkMachine.enter(regno2, time2);
  std::cout << "Parked #1:" << std::endl;
  std::cout << "\tregno -> " << regno1 << std::endl;
  std::cout << "\ttime -> " << time1 << std::endl;

  std::cout << "Parked #2:" << std::endl;
  std::cout << "\tregno -> " << regno2 << std::endl;
  std::cout << "\ttime -> " << time2 << std::endl;


  std::cout << parkMachine << std::endl;

  std::cout << "-------------------" << std::endl;
  std::cout << (parkMachine & regno2) << std::endl;


  std::cout << "Parked#1 left after two hours and had to pay: ";
  std::cout << parkMachine.leave(regno1, time1 + 2) << "$" << std::endl;

  return 0;
}
