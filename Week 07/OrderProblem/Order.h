#pragma once
#include <iostream>
using namespace std;

const int DEFAULT_CAP = 1024;

class Order
{
  size_t orderID;
  char* orderList;
  int lastIndex;
  size_t listCapacity;

  void Resize(size_t newCapacity);
public:
  Order(size_t orderID = 0);
  Order(const Order& other);
  Order& operator=(const Order& other);
  ~Order();

  void AddItem(const char* item);
  void Cancel();

  friend ostream& operator<<(ostream& os, const Order& order);
};
