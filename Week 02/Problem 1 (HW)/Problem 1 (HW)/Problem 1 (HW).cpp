// Problem 1 (HW).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string.h"
using namespace std;

const int MAX_CITY_LENGTH = 32;

struct Destination
{
	char city[MAX_CITY_LENGTH];
	int kilometers;
};

void init_Dest(Destination& destination, char* city, int kilometers)
{
	strcpy_s(destination.city, city);
	destination.kilometers = kilometers;
}

void EnterDest(Destination& d)
{
	char city[MAX_CITY_LENGTH];
	int kilometers;
	cout << "Enter city name: ";
	cin >> city;
	cout << "Enter kilometers: ";
	cin >> kilometers;
	init_Dest(d, city, kilometers);
}

void PrintDest(Destination d)
{
	cout << "Destination: " << d.city << endl;
	cout << "Kilometers: " << d.kilometers << endl;
}

void InitDestinations(Destination* destinations, const int numOfDestinations, bool useDefaultValues)
{
	if (useDefaultValues)
	{
		for (int i = 0; i < numOfDestinations; i++)
		{
			memset(destinations[i].city, NULL, MAX_CITY_LENGTH);
			destinations[i].kilometers = 0;
		}
	}
	else
	{
		for (int i = 0; i < numOfDestinations; i++)
		{
			cout << "City #" << i + 1 << endl;
			EnterDest(destinations[i]);
			cout << endl;
		}
	}
}

void PrintDestinations(Destination* destinations, int numOfDestinations)
{
	for (int i = 0; i < numOfDestinations; i++)
	{
		cout << "City #" << i + 1 << endl;
		PrintDest(destinations[i]);
		cout << endl;
	}
}

int main()
{
	Destination plovdiv = { "Plovdiv", 165 };
	Destination varna = { "Varna", 469 };

	PrintDest(plovdiv);
	cout << endl;
	PrintDest(varna);
	cout << endl;

	Destination destinations[30];
	InitDestinations(destinations, 30, true);
	
	Destination newDestinations[5];
	InitDestinations(newDestinations, 5, false);
	cout << "Destinations: " << endl;
	PrintDestinations(newDestinations, 5);

    return 0;
}