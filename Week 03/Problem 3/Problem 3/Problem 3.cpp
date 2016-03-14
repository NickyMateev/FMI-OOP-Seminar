// Problem 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

const int MAX_CAPACITY = 100;
const int MAX_NAME = 32;

enum Color
{
	Brown,
	Green,
	Orange,
	Red,
	Yellow
};

enum YN
{
	No,
	Yes
};

struct Fruit
{
	char name[MAX_NAME];
	Color lc;
	YN annual;
	YN perennial;
	YN tropical;

	void Create(char* nameEntered, Color lcEntered, YN annualEntered, YN perennialEntered, YN tropicalEntered)
	{
		strcpy_s(name, nameEntered);
		lc = lcEntered;
		annual = annualEntered;
		perennial = perennialEntered;
		tropical = tropicalEntered;
	}

	void Print()
	{
		cout << "Fruit name: " << name << endl;
		cout << "Fruit color:";
		if (lc == 0)
			cout << "Brown" << endl;
		else if (lc == 1)
			cout << "Green" << endl;
		else if (lc == 2)
			cout << "Orange" << endl;
		else if (lc == 3)
			cout << "Red" << endl;
		else if (lc == 4)
			cout << "Yellow" << endl;
		else
			cout << "Unknown color..." << endl;

		cout << "Is it an annual fruit: ";
		if (annual)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		cout << "Is it a perennial fruit: ";
		if (perennial)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		cout << "Is it a tropical fruit: ";
		if (tropical)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
};

int UserInputYesNo(char* input)
{
	int userInput;
	cout << "Is it a/an " << input << " fruit?" << endl << "No -> 0" << endl << "Yes -> 1" << endl;
	cout << "Enter any number in the range 0-1 as your choice: ";
	cin >> userInput;
	while (userInput < 0 || userInput > 1)
	{
		cout << "Invalid number!" << endl;
		cout << "Enter any number in the range 0-1 as your choice: ";
		cin >> userInput;
	}
	return userInput;
}

void InitFruit(Fruit* fruit)
{
	char name[MAX_NAME];
	int colorChoice, annualChoice, perennialChoice, tropicalChoice;
	cout << "Fruit name: ";
	cin >> name;

	cout << "Fruit color: " << endl;
	cout << "Brown -> 0" << endl << "Green -> 1" << endl << "Orange -> 2" << endl << "Red -> 3" << endl << "Yellow -> 4" << endl;
	cout << "Enter any number in the range 0-4 as your choice: ";
	cin >> colorChoice;
	while (colorChoice < 0 || colorChoice > 4)
	{
		cout << "Invalid number!" << endl;
		cout << "Enter any number in the range 0-4 as your choice: ";
		cin >> colorChoice;
	}

	annualChoice = UserInputYesNo("annual");
	if (annualChoice)
		perennialChoice = 0;
	else
		perennialChoice = UserInputYesNo("perennial");
	tropicalChoice = UserInputYesNo("tropical");
	cout << endl;

	fruit->Create(name, static_cast<Color>(colorChoice), static_cast<YN>(annualChoice), static_cast<YN>(perennialChoice), static_cast<YN>(tropicalChoice));
}

void InitFruits(Fruit* fruit[], int size)
{
	for (int i = 0; i < size; i++)
		InitFruit(fruit[i]);
}

void PrintFruits(Fruit* fruit[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Fruit #" << i + 1 << endl;
		fruit[i]->Print();
		cout << endl;
	}
}

void SortByName(Fruit* fruit[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (strcmp(fruit[j]->name, fruit[j + 1]->name) > 0)
			{
				Fruit* tempFruit = fruit[j];
				fruit[j] = fruit[j + 1];
				fruit[j + 1] = tempFruit;
			}
		}
	}
}

void SortByColor(Fruit* fruit[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (fruit[j]->lc > fruit[j+1]->lc)
			{
				Fruit* tempFruit = fruit[j];
				fruit[j] = fruit[j + 1];
				fruit[j + 1] = tempFruit;
			}
		}
	}
}

void SortByFruitfulness(Fruit* fruit[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if ((fruit[j]->annual > fruit[j + 1]->annual) || (fruit[j]->perennial > fruit[j + 1]->perennial))
			{
				Fruit* tempFruit = fruit[j];
				fruit[j] = fruit[j + 1];
				fruit[j + 1] = tempFruit;
			}
		}
	}
}

int main()
{
	int numOfFruits;
	cout << "How many fruits do you want to enter? ";
	cin >> numOfFruits;

	Fruit fruits[MAX_CAPACITY];
	Fruit* fruitPointers[MAX_CAPACITY];

	for (int i = 0; i < numOfFruits; i++)
		fruitPointers[i] = &(fruits[i]);

	InitFruits(fruitPointers, numOfFruits);

	SortByName(fruitPointers, numOfFruits);
	SortByColor(fruitPointers, numOfFruits);
	SortByFruitfulness(fruitPointers, numOfFruits);

	PrintFruits(fruitPointers, numOfFruits);
	return 0;
}