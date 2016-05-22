#include "ParkingMachine.h"

const double DEFAULT_PRICE = 4.99;
const int DEFAULT_CAP = 40;
const int MAX_CAP = 1280;

double ParkingMachine::calculatePay(int startTime, int endTime)
{
  return (this->price) * (endTime - startTime);
}

void ParkingMachine::resize()
{
  int newCap;
  if(capacity*2 > MAX_CAP)
    newCap = MAX_CAP;
  else
    newCap = 2 * capacity;

  Parked* newParked = new Parked[newCap];
  for(int i = 0; i < this->count; i++)
    newParked[i] = this->parkedCars[i];

  delete[] this->parkedCars;
  this->parkedCars = newParked;
  this->capacity = newCap;
}

void ParkingMachine::shift(int index)
{
  for(; index < this->count - 1; index++)
    parkedCars[index] = parkedCars[index + 1];
}

ParkingMachine::ParkingMachine()
{
  this->price = DEFAULT_PRICE;
  this->count = 0;
  this->capacity = DEFAULT_CAP;
  this->parkedCars = new Parked[capacity];
}

ParkingMachine::ParkingMachine(double price, int capacity)
{
  this->price = price;
  this->count = 0;
  this->capacity = capacity;
  parkedCars = new Parked[capacity];
}

ParkingMachine::ParkingMachine(const ParkingMachine& other)
{
  this->price = other.price;
  this->count = other.count;
  this->capacity = other.capacity;
  this->parkedCars = new Parked[other.capacity];

  for(int i = 0; i < other.count; i++)
    parkedCars[i] = other.parkedCars[i];
}

ParkingMachine& ParkingMachine::operator=(const ParkingMachine& other)
{
  if(this != &other)
  {
    delete[] this->parkedCars;

    this->price = other.price;
    this->count = other.count;
    this->capacity = other.capacity;
    this->parkedCars = new Parked[other.capacity];

    for(int i = 0; i < other.count; i++)
      parkedCars[i] = other.parkedCars[i];
  }
  return *this;
}

ParkingMachine::~ParkingMachine()
{
  delete[] this->parkedCars;
}

void ParkingMachine::enter(char* regno, int time)
{
  if(count == MAX_CAP)
  {
    std::cout << "The park machine is full! Cannot add any more vechicles." << std::endl;
    return;
  }
  else if (count == capacity)
    resize();

  Parked temp(regno, time);
  this->parkedCars[count] = temp;
  this->count++;
}

double ParkingMachine::leave(char* regno, int time)
{
  for(int i = 0; i < this->count; i++)
  {
    if(strcmp(parkedCars[i].getRegno(), regno) == 0)
    {
      double payPrice = calculatePay(parkedCars[i].getTime(), time);
      shift(i);
      this->count--;

      return payPrice;
    }
  }

  return -1; // if no such vechicle is found
}

bool ParkingMachine::operator&(const char* regno)
{
  for(int i = 0; i < this->count; i++)
    if(strcmp(parkedCars[i].getRegno(), regno) == 0)
      return true;

  return false;
}

double ParkingMachine::late(int hours, int curTime)
{
  double sum = 0;
  int diff;
  for(int i = 0; i < this->count; i++)
  {
    diff = curTime - parkedCars[i].getTime();
    if(diff >= hours)
      sum += (this->price) * diff;
  }

  return sum;
}

std::ostream& operator<<(std::ostream& os, const ParkingMachine& obj)
{
  os << "Number of cars: " << obj.count << std::endl;
  os << "Capacity: " << obj.capacity << std::endl;
  os << "Price: " << obj.price << std::endl;

  return os;
}
