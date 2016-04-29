#include "EventLog.h"
#include "myFunctions.cpp"

void EventLog::Resize(size_t newCapacity)
{
  char* newList = new char[newCapacity];

  for(int i = 0; i < lastIndex; i++)
    newList[i] = eventList[i];

  delete[] eventList;

  eventList = newList;
  listCapacity = newCapacity;
}

EventLog::EventLog(const char* name)
{
  mystrcpy(this->name, name);
  eventList = new char[DEFAULT_CAP];
  lastIndex = 0;
  listCapacity = DEFAULT_CAP;
}

EventLog::EventLog(const EventLog& other)
{
  mystrcpy(this->name, other.name);
  mystrcpy(this->eventList, other.eventList);
  this->lastIndex = other.lastIndex;
  this->listCapacity = other.listCapacity;
}

EventLog& EventLog::operator=(const EventLog& other)
{
  if(this != &other)
  {
    if(this->name)
      delete[] this->name;

    if(this->eventList)
      delete[] this->eventList;

    mystrcpy(this->name, other.name);
    mystrcpy(this->eventList, other.eventList);
    this->lastIndex = other.lastIndex;
    this->listCapacity = other.listCapacity;
  }
  return *this;
}

EventLog::~EventLog()
{
  if(this->name)
      delete[] this->name;

  if(this->eventList)
    delete[] this->eventList;
}

void EventLog::AddEvent(const char* event)
{
  int eventLength = mystrlen(event);

  if(lastIndex + eventLength + 2 > listCapacity)
    Resize(2 * listCapacity);

  for(int i = 0; i < eventLength; i++, lastIndex++)
    eventList[lastIndex] = event[i];

  eventList[lastIndex] = ';';
  lastIndex++;
  eventList[lastIndex] = '\0';
}

void EventLog::Clear()
{
  eventList[0] = '\0';
  lastIndex = 0;
}

ostream& operator<<(ostream& os, const EventLog& event)
{
  for(int i = 0; event.eventList[i] != '\0'; i++)
  {
    if(event.eventList[i] == ';')
      os << endl;
    else
      os << event.eventList[i];
  }

  return os;
}

int main()
{
  EventLog eventLog;
  eventLog.AddEvent("Make your bed");
  eventLog.AddEvent("Do your homework");
  eventLog.AddEvent("Go to the gym");
  eventLog.AddEvent("Pay the bills");
  eventLog.AddEvent("Eat some food");

  cout << eventLog << endl;

  eventLog.Clear();
  cout << eventLog << endl;

  eventLog.AddEvent("Go running");
  cout << eventLog;
  return 0;
}
