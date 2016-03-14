// Problem 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

const int MAX_PLANET_NAME = 50;
const int SUN_SPEED = 299792;
const int MAX_CAPACITY = 100;

struct Planet
{
	char name[MAX_PLANET_NAME];
	double distance, diameter, mass;

	void Create(char* nameEntered, double distanceEntered, double diameterEntered, double massEntered)
	{
		strcpy_s(name, nameEntered);
		distance = distanceEntered;
		diameter = diameterEntered;
		mass = massEntered;
	}

	void Print()
	{
		cout << "Planet name: " << name << endl;
		cout << "Distance from the Sun: " << distance << endl;
		cout << "Planet diameter: " << diameter << endl;
		cout << "Planet mass: " << mass << endl;
	}

	double TimeNeeded()
	{
		return distance / (SUN_SPEED);
	}
};

void InitPlanet(Planet& planet)
{
	char name[MAX_PLANET_NAME];
	double distance, diameter, mass;

	cout << "Enter planet name: ";
	cin >> name;
	cout << "Enter planet distance from the sun: ";
	cin >> distance;
	cout << "Enter planet diameter: ";
	cin >> diameter;
	cout << "Enter planet mass: ";
	cin >> mass;

	planet.Create(name, distance, diameter, mass);
}

void InitPlanets(Planet* planets, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Planet #" << i + 1 << endl;
		InitPlanet(planets[i]);
		cout << endl;
	}
}

void PrintPlanets(Planet* planets, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Planet #" << i + 1 << " info:" << endl;
		planets[i].Print();
		cout << endl;
	}
}

Planet MaxDiameter(Planet* planets, int size)
{
	int index = 0;

	for (int i = 1; i < size; i++)
	{
		if (planets[i].diameter > planets[index].diameter)
			index = i;
	}
	return planets[index];
}

Planet MinMass(Planet* planets, int size)
{
	int index = 0;

	for (int i = 1; i < size; i++)
	{
		if (planets[i].mass < planets[index].mass)
			index = i;
	}
	return planets[index];
}

Planet ShortestTime(Planet* planets, int size)
{
	int index = 0;

	for (int i = 1; i < size; i++)
	{
		if (planets[i].TimeNeeded() < planets[index].TimeNeeded())
			index = i;
	}
	return planets[index];
}

Planet LongestTime(Planet* planets, int size)
{
	int index = 0;

	for (int i = 1; i < size; i++)
	{
		if (planets[i].TimeNeeded() > planets[index].TimeNeeded())
			index = i;
	}
	return planets[index];
}

int main()
{
	int numOfPlanets;
	cout << "How many planets do you want to enter? ";
	cin >> numOfPlanets;

	Planet planets[MAX_CAPACITY];
	InitPlanets(planets, numOfPlanets);

	PrintPlanets(planets, numOfPlanets);
	cout << "Max diameter: " << MaxDiameter(planets, numOfPlanets).diameter << endl;
	cout << "Min mass: " << MinMass(planets, numOfPlanets).mass << endl;
	cout << "Shortest time to the Sun: " << ShortestTime(planets, numOfPlanets).TimeNeeded() << endl;
	cout << "Longest time to the Sun: " << LongestTime(planets, numOfPlanets).TimeNeeded() << endl;

	return 0;
}
