#include "Order.h"
#include "myFunctions.cpp"

void Order::Resize(size_t newCapacity)
{
  char* newList = new char[newCapacity];

  for(int i = 0; i < lastIndex; i++)
    newList[i] = orderList[i];

  delete[] orderList;

  orderList = newList;
  listCapacity = newCapacity;
}

Order::Order(size_t orderID)
{
  this->orderID = orderID;
  orderList = new char[DEFAULT_CAP];
  lastIndex = 0;
  listCapacity = DEFAULT_CAP;
}

Order::Order(const Order& other)
{
  this->orderID = other.orderID;
  mystrcpy(this->orderList, other.orderList);
  this->lastIndex = other.lastIndex;
  this->listCapacity = other.listCapacity;
}

Order& Order::operator=(const Order& other)
{
  if(this != &other)
  {
    if(this->orderList)
      delete[] this->orderList;

    this->orderID = other.orderID;
    mystrcpy(this->orderList, other.orderList);
    this->lastIndex = other.lastIndex;
    this->listCapacity = other.listCapacity;
  }
  return *this;
}

Order::~Order()
{
  if(orderList)
    delete[] orderList;
}

void Order::AddItem(const char* item)
{
  int itemLength = mystrlen(item);

  if(lastIndex + itemLength + 2 > listCapacity)
    Resize(2 * listCapacity);

  for(int i = 0; i < itemLength; i++, lastIndex++)
    orderList[lastIndex] = item[i];

  orderList[lastIndex] = ';';
  lastIndex++;
  orderList[lastIndex] = '\0';
}

void Order::Cancel()
{
  orderList[0] = '\0';
  lastIndex = 0;
}

ostream& operator<<(ostream& os, const Order& order)
{
  for(int i = 0; order.orderList[i] != '\0'; i++)
  {
    if(order.orderList[i] == ';')
      os << endl;
    else
      os << order.orderList[i];
  }

  return os;
}

int main()
{
  Order order;
  order.AddItem("Bread");
  order.AddItem("Sand");
  order.AddItem("Apple");
  order.AddItem("IPhone");

  cout << order;
  order.Cancel();
  cout << order;

  order.AddItem("Book");
  cout << order;

  return 0;
}
