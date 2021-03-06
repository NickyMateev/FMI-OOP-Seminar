#include <iostream>
using namespace std;

const int ARRAY_LENGTH = 32;

class Point3
{
	int x, y, z;
public:
	Point3(int, int, int);
  Point3(const Point3&);
	int getX();
	void setX(const int x);
	int getY();
	void setY(const int y);
	int getZ();
	void setZ(const int z);

	void Print();
};

Point3::Point3(int x = 0, int y = 0, int z = 0)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point3::Point3(const Point3& other)
{
  x = other.x;
  y = other.y;
  z = other.z;
}

int Point3::getX() { return x; }

void Point3::setX(const int x) { this->x = x; }

int Point3::getY() { return y; }

void Point3::setY(const int y) { this->y = y; }

int Point3::getZ() { return z; }

void Point3::setZ(const int z) { this->z = z; }

void Point3::Print()
{
		cout << "x = "<< x <<endl;
		cout << "y = "<< y <<endl;
		cout << "z = "<< z <<endl;

}

void SwapPoints(Point3& pt1, Point3& pt2)
{
	Point3 temp = pt1;
	pt1 = pt2;
	pt2 = temp;
}

void SortPoints(Point3* arr, int numberOfPoints)
{
	for(int i = 0; i < numberOfPoints - 1; i++)
	{
		for(int j = 0; j < numberOfPoints - i - 1; j++)
		{
			if(!(arr[j].getX() < arr[j+1].getX() || (arr[j].getX() == arr[j+1].getX() && arr[j].getY() < arr[j+1].getY()) || (arr[j].getX() == arr[j+1].getX() && arr[j].getY() == arr[j+1].getY() && arr[j].getZ() < arr[j+1].getZ())))
			{
				SwapPoints(arr[j], arr[j+1]);
			}
		}
	}
}


void InputPoints(Point3* arr, int numberOfPoints)
{
	int x,y,z;
	for(size_t i = 0; i < numberOfPoints; i++)
	{
		cout << "x = ";
		cin>>x;
		cout << "y = ";
		cin>>y;
		cout << "z = ";
		cin>>z;
    cout << endl;

		arr[i].setX(x);
		arr[i].setY(y);
		arr[i].setZ(z);
	}
}

void PrintPoints(Point3* arr, int numberOfPoints)
{
  for(size_t i = 0; i < numberOfPoints; i++)
  {
    cout << "Point #" << i + 1 << ":"<<endl;
    arr[i].Print();
    cout << endl;
  }
}

int main()
{
	Point3 arr[ARRAY_LENGTH];
	int numberOfPoints;
	cout << "How many points do you want to enter: ";
	cin>>numberOfPoints;

	InputPoints(arr, numberOfPoints);
	SortPoints(arr, numberOfPoints);
	PrintPoints(arr, numberOfPoints);

	return 0;
}
