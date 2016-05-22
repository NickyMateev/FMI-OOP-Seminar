#pragma once
#include "Parked.h"

class ParkingMachine
{
  double price;
  Parked* parkedCars;
  int count;
  int capacity;

  double calculatePay(int startTime, int endTime);
  void resize();
  void shift(int index);
public:
  ParkingMachine();
  ParkingMachine(double price, int capacity);
  ParkingMachine(const ParkingMachine& other);
  ParkingMachine& operator=(const ParkingMachine& other);
  ~ParkingMachine();

  void enter(char* regno, int time);
  double leave(char* regno, int time);
  bool operator&(const char* regno); // checks whether there's a car with the given regno in the ParkingMachine or not
  double late(int hours, int curTime);
  friend std::ostream& operator<<(std::ostream& os, const ParkingMachine& obj);
};
