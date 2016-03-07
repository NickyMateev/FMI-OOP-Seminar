// Problem 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string.h"
using namespace std;

const int MAX_NAME_LENGTH = 100;
const int MAX_CAPACITY = 100;

struct Person
{
	char firstName[MAX_NAME_LENGTH];
	char lastName[MAX_NAME_LENGTH];
};

struct Client
{
	Person person;
	double money;
};

void InitPerson(Person& p, char* firstName, char* lastName)
{
	strcpy_s(p.firstName, firstName);
	strcpy_s(p.lastName, lastName);
}

void InitClient(Client& c, Person p, double money)
{
	c.person = p;
	c.money = money;
}

void PrintPerson(Person p)
{
	cout << "First name: " << p.firstName << endl;
	cout << "Last name: " << p.lastName << endl;
}

void PrintClient(Client c)
{
	cout << "Client info: " << endl;
	PrintPerson(c.person);
	cout << "Money: " << c.money << endl;
}

void EnterPerson(Person& p)
{
	char firstName[MAX_NAME_LENGTH], lastName[MAX_NAME_LENGTH];
	cout << "First name: ";
	cin >> firstName;
	cout << "Last name: ";
	cin >> lastName;
	InitPerson(p, firstName, lastName);
}

void EnterClient(Client& c)
{
	Person p;
	double money;
	
	cout << "Enter client info:" << endl;
	EnterPerson(p);
	cout << "Enter client money: ";
	cin >> money;
	InitClient(c, p, money);
}

void InitClients(Client* clientsArray, int numOfClients)
{
	for (int i = 0; i < numOfClients; i++)
	{
		EnterClient(clientsArray[i]);
	}
}

void PrintClients(Client* clientsArray, int numOfClients)
{
	for (int i = 0; i < numOfClients; i++)
	{
		PrintClient(clientsArray[i]);
		cout << endl;
	}
}

double GetTotalMoney(Client* clientsArray, int numOfClients)
{
	double totalMoney = 0;
	for (int i = 0; i < numOfClients; i++)
	{
		totalMoney += clientsArray[i].money;
	}
	return totalMoney;
}

int main()
{
	Client clients[MAX_CAPACITY];
	int numberOfClients;
	cout << "How many clients do you want to enter: ";
	cin >> numberOfClients;
	InitClients(clients, numberOfClients);
	cout << endl;
	PrintClients(clients, numberOfClients);
	cout << "Total money: " << GetTotalMoney(clients, numberOfClients) << endl;

    return 0;
}