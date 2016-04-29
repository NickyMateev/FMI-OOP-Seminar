#include <iostream>
#include <string.h>
using namespace std;

const int NAME_LENGTH = 100;
const int MAX_PATIENTS = 100;

class Patient
{
  char name[NAME_LENGTH];
  int birthDay, birthMonth, birthYear;
  int visits;
public:
  Patient(char* name = "Default Name", int day = 1, int month = 1, int  year = 1, int visits = 0);

  const char* getName() const;
  void setName(const char* newName);
  int getVisits() const;
  void setVisits(const int visits);
};

class Doctor
{
  char name[NAME_LENGTH];
  Patient patients[MAX_PATIENTS];
  int numberOfPatients;
public:
  Doctor(char* name = "Default Name", Patient* patients = NULL, int numberOfPatients = 0);
  double GetAvgVisitsPerPatient();
  void PrintPatientsWithExcessVisits(int maxVisits = 10);
};

Patient::Patient(char* name, int day, int month, int year, int visits)
{
  strcpy(this->name, name);
  birthDay = day;
  birthMonth = month;
  birthYear = year;
  this->visits = visits;
}

const char* Patient::getName() const { return name; }
void Patient::setName(const char* newName) { strcpy(name, newName); }
int Patient::getVisits() const { return visits; }
void Patient::setVisits(const int visits) { this->visits = visits; }

Doctor::Doctor(char* name, Patient* patients, int numberOfPatients)
{
  strcpy(this->name, name);

  for(size_t i = 0; i < numberOfPatients; i++)
    this->patients[i] = patients[i];

  this->numberOfPatients = numberOfPatients;
}

double Doctor::GetAvgVisitsPerPatient()
{
  double sum = 0;
  for(size_t i = 0; i < numberOfPatients; i++)
    sum += patients[i].getVisits();

  return sum/numberOfPatients;
}

void Doctor::PrintPatientsWithExcessVisits(int maxVisits)
{
  for(size_t i = 0; i < numberOfPatients; i++)
  {
    if(patients[i].getVisits() > maxVisits)
      cout << patients[i].getName() << endl;
  }
}

int main()
{
  Patient p1("Pesho1", 1, 1, 1990, 12);
  Patient p2("Pesho2", 3, 2, 1980, 6);
  Patient p3("Pesho3", 8, 12, 1991, 1);
  Patient p4("Pesho4", 10, 24, 2000, 0);

  Patient patients[4] = {p1, p2, p3, p4};

  Doctor doc("Mr.Pesho", patients, 4);

  cout << "Average visits per patient: " << doc.GetAvgVisitsPerPatient() << endl;
  cout << "Patients with more than 5 visits:"<<endl;
  doc.PrintPatientsWithExcessVisits(5);

  return 0;
}
