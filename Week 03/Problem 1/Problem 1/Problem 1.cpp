// Problem 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

const int MAX_CAPACITY = 50;

struct Triangle
{
	double a, b, c;

	void Create(double x, double y, double z)
	{
		a = x;
		b = y;
		c = z;
	}

	void Print()
	{
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "c: " << c << endl;
	}

	double Perimeter()
	{
		return a + b + c;
	}

	double Surface()
	{
		double p = Perimeter() / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}

	Triangle Mult_k(int k)
	{
		Triangle newTriangle;
		newTriangle.Create(a*k, b*k, c*k);
		return newTriangle;
	}
};

void InitTriangle(Triangle& triangle)
{
	double a, b, c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	triangle.Create(a, b, c);
}

void InitAllTriangles(Triangle* triangles, int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << "Triangle #" << i + 1 << endl;
		InitTriangle(triangles[i]);
		cout << endl;
	}
}

void PrintTriangles(Triangle* triangles, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Triangle #" << i + 1 << endl;
		triangles[i].Print();
		cout << endl;
	}
}

Triangle MinSurface(Triangle* tarr, int size)
{
	int index = 0;
	double sur = tarr[0].Surface();

	for (int i = 1; i < size; i++)
	{
		if (tarr[i].Surface() < sur)
		{
			sur = tarr[i].Surface();
			index = i;
		}
	}
	return tarr[index];
}

Triangle MaxPerimeter(Triangle* tarr, int size)
{
	int index = 0;
	double per = tarr[0].Perimeter();

	for (int i = 1; i < size; i++)
	{
		if (tarr[i].Perimeter() > per)
		{
			per = tarr[i].Perimeter();
			index = i;
		}
	}
	return tarr[index];
}

void NewSequence(Triangle* triangles, int size, Triangle* newTriangles)
{
	for (int i = 0; i < size; i++)
	{
		newTriangles[i] = triangles[i].Mult_k(i + 1);
	}
}

int main()
{
	int numOfTriangles = -1;
	cout << "How many triangles(1-20) do you want to enter? ";
	while (numOfTriangles <= 0 || numOfTriangles > 20)
		cin >> numOfTriangles;

	Triangle triangles[MAX_CAPACITY];
	InitAllTriangles(triangles, numOfTriangles);

	cout << "Minimum surface: " << MinSurface(triangles, numOfTriangles).Surface() << endl;
	cout << "Maximum perimeter: " << MaxPerimeter(triangles, numOfTriangles).Perimeter() << endl;
	cout << endl;

	Triangle newTriangles[MAX_CAPACITY];
	NewSequence(triangles, numOfTriangles, newTriangles);
	cout << "New triangles:" << endl;
	PrintTriangles(newTriangles, numOfTriangles);

    return 0;
}