#include "vector.h"
#include <cassert>

Vector::Vector()
{
  elements = NULL;
  numberOfElements = 0;
}

Vector::Vector(double* elements, int numberOfElements)
{
  this->numberOfElements = numberOfElements;

  this->elements = new double[this->numberOfElements];
  for(int i = 0; i < this->numberOfElements; i++)
    this->elements[i] = elements[i];

  }

Vector::Vector(const Vector& other)
{
  this->numberOfElements = other.numberOfElements;

  this->elements = new double[this->numberOfElements];
  for(int i = 0; i < this->numberOfElements; i++)
    this->elements[i] = other.elements[i];
}

Vector& Vector::operator=(const Vector& other)
{
  if(this != &other)
  {
    if(this->elements)
      delete[] this->elements;

    this->numberOfElements = other.numberOfElements;

    this->elements = new double[this->numberOfElements];
    for(int i = 0; i < this->numberOfElements; i++)
      this->elements[i] = other.elements[i];
  }

  return *this;
}

Vector::~Vector()
{
  if(this->elements)
    delete[] this->elements;
}

ostream& operator<<(ostream& os, const Vector& vector)
{
  os << "(";
  for(int i = 0; i < vector.numberOfElements; i++)
  {
    if(i == vector.numberOfElements - 1)
      os << vector.elements[i];
    else
      os << vector.elements[i] << ", ";
  }
  os << ")";
  return os;
}

istream& operator>>(istream& is, Vector& vector)
{
  for(int i = 0; i < vector.numberOfElements; i++)
    is >> vector.elements[i];

  return is;
}

Vector& Vector::operator+=(const Vector& other)
{
  for(int i = 0; i < this->numberOfElements && i < other.numberOfElements; i++)
    this->elements[i] += other.elements[i];

  return *this;
}

Vector& Vector::operator-=(const Vector& other)
{
  for(int i = 0; i < this->numberOfElements && i < other.numberOfElements; i++)
    this->elements[i] -= other.elements[i];

  return *this;
}


Vector operator+(const Vector& v1, const Vector& v2)
{
  Vector result(v1);
  result += v2;

  return result;
}

Vector operator-(const Vector& v1, const Vector& v2)
{
  Vector result(v1);
  result -= v2;

  return result;
}

Vector& Vector::operator+=(double scalar)
{
  for(int i = 0; i < this->numberOfElements; i++)
    this->elements[i] += scalar;

  return *this;
}

Vector& Vector::operator-=(double scalar)
{
  for(int i = 0; i < this->numberOfElements; i++)
    this->elements[i] -= scalar;

  return *this;
}

Vector operator+(const Vector& vector, double scalar)
{
  Vector result(vector);
  result += scalar;

  return result;
}

Vector operator-(const Vector& vector, double scalar)
{
  Vector result(vector);
  result -= scalar;

  return result;
}

Vector& Vector::operator*=(double scalar)
{
  for(int i = 0; i < this->numberOfElements; i++)
    this->elements[i] *= scalar;

  return *this;
}

Vector& Vector::operator/=(double scalar)
{
  for(int i = 0; i < this->numberOfElements; i++)
    this->elements[i] /= scalar;

  return *this;
}

Vector operator*(const Vector& vector, double scalar)
{
  Vector result(vector);
  result *= scalar;

  return result;
}

Vector operator/(const Vector& vector, double scalar)
{
  Vector result(vector);
  result /= scalar;

  return result;
}

const double Vector::operator[](int index) const
{
  assert(("Invalid index!", index >= 0 && index < this->numberOfElements));

  return this->elements[index];
}

double& Vector::operator[](int index)
{
  assert(("Invalid index!", index >= 0 && index < this->numberOfElements));

  return this->elements[index];
}

double operator*(const Vector& v1, const Vector& v2)
{
  double result = 0;
  for(int i = 0; i < v1.numberOfElements && i < v2.numberOfElements; i++)
    result += v1[i] * v2[i];

  return result;
}

Vector& Vector::operator!()
{
  *this /= sqrt(*this * *this);

  return *this;
}

int main()
{
  double arr[3] = {1, 2, 3};
  double arr2[5] = {4, 5, 6, 7, 8};
  Vector v1(arr, 3);
  Vector v2(arr2, 5);

  cout << "v1: " << v1 << endl;
  cout << "v2: " << v2 << endl;

  cout << "v1 + v2 : " << v1 + v2 << endl;
  cout << "v2 - v1 : "<< v2 - v1 << endl;
  cout << "v1 * v2 : "<< v1 * v2 << endl;

  cout << "v1[1]: " <<v1[1] << endl;
  cout << "v2[2]: "<<v2[2] << endl;

  v1.operator!();
  cout << "v1: " << v1 << endl;

  return 0;
}
