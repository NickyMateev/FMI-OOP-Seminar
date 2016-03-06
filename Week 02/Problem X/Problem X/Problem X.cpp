// Problem X.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct Rectangle
{
	int length;
	int width;
};

void print_rectangle(Rectangle r)
{
	cout << "Length: " << r.length << endl;
	cout << "Width: " << r.width << endl;
}

void init_rectangle(Rectangle& r)
{
	cout << "Enter length: ";
	cin >> r.length;
	cout << "Enter width: ";
	cin >> r.width;
}

Rectangle init_rectangle()
{
	Rectangle rect;
	init_rectangle(rect);
	return rect;
}

int main()
{
	// first way
	Rectangle rect;
	init_rectangle(rect);
	print_rectangle(rect);

	// second way
	Rectangle getRect = init_rectangle();
	print_rectangle(getRect);

    return 0;
}

