// Problem 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class Factorial
{
	int value;
	int CalculateFactorial(int n);
public:
	void Constructor(int num);
	int GetFactorial();
};

int Factorial::CalculateFactorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n*CalculateFactorial(n - 1);
}

void Factorial::Constructor(int num)
{
	value = CalculateFactorial(num);
}

int Factorial::GetFactorial()
{
	return value;
}

int main()
{
	Factorial f;
	f.Constructor(5);
	cout << f.GetFactorial() << endl;

    return 0;
}

