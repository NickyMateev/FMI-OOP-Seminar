#include <iostream>
#include <cmath>
#pragma once
using namespace std;

class Vector
{
  double* elements;
  int numberOfElements;
public:
  Vector();
  Vector(double* elements, int numberOfElements);
  Vector(const Vector& other);
  Vector& operator=(const Vector& other);
  ~Vector();

  friend ostream& operator<<(ostream& os, const Vector& vector);
  friend istream& operator>>(istream& is, Vector& vector);

  Vector& operator+=(const Vector& other);
  Vector& operator-=(const Vector& other);

  friend Vector operator+(const Vector& v1, const Vector& v2);
  friend Vector operator-(const Vector& v1, const Vector& v2);

  Vector& operator+=(double scalar);
  Vector& operator-=(double scalar);
  friend Vector operator+(const Vector& vector, double scalar);
  friend Vector operator-(const Vector& vector, double scalar);

  Vector& operator*=(double scalar);
  Vector& operator/=(double scalar);
  friend Vector operator*(const Vector& vector, double scalar);
  friend Vector operator/(const Vector& vector, double scalar);

  const double operator[](int index) const;
  double& operator[](int index);

  friend double operator*(const Vector& v1, const Vector& v2);

  Vector& operator!();
};
