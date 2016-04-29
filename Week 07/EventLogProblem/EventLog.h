#pragma once
#include <iostream>
using namespace std;

const int NAME_LENGTH = 30;
const int DEFAULT_CAP = 1024;

class EventLog
{
  char* name;
  char* eventList;
  int lastIndex;
  size_t listCapacity;

  void Resize(size_t newCapacity);
public:
  EventLog(const char* name = "EventLog");
  EventLog(const EventLog& other);
  EventLog& operator=(const EventLog& other);
  ~EventLog();

  void AddEvent(const char* event);
  void Clear();

  friend ostream& operator<<(ostream& os, const EventLog& eventLog);
};
