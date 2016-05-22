#include "Stack.h"
#include <cassert>

template <typename T>
Stack<T>::Stack()
{
  top = -1;
}

template <typename T>
Stack<T>::Stack(const T* collection, const int size)
{
  assert(("Collection size is too high!", size <= DEFAULT_CAP));

  for(int i = 0; i < size; i++)
    collection[i] = arr[i];

  top = size - 1;
}

template <typename T>
bool Stack<T>::IsEmpty() const
{
  return top < 0;
}

template <typename T>
void Stack<T>::Push(const T element)
{
  assert(("Collection size is too high!", top + 1 < DEFAULT_CAP));

  top++;
  arr[top] = element;
}

template <typename T>
void Stack<T>::Pop()
{
  if(!IsEmpty())
    top--;
}

template <typename T>
const T Stack<T>::Peek() const
{
  assert(("Stack is empty!", !IsEmpty()));

  return arr[top];
}
