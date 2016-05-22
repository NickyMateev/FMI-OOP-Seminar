#pragma once
#include <iostream>

const int DEFAULT_CAP = 50;

template <typename T>
class Stack
{
  T arr[DEFAULT_CAP];
  int top; // index of the last inserted element
public:
  Stack();
  Stack(const T* collection, const int size);
  bool IsEmpty() const;
  void Push(const T element);
  const T Peek() const;
  void Pop();
};
