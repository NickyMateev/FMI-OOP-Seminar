#include "Stack.h"

int main()
{
  Stack<int> stack;
  std::cout << "Stack created." << std::endl;
  if(stack.IsEmpty())
    std::cout << "Stack is empty." << std::endl;
  else
    std::cout << "Stack is not empty." << std::endl;

  std::cout << "Pushing elements to the stack..." << std::endl;
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  stack.Push(4);
  stack.Push(5);

  std::cout << "Top element of the stack right now: " << stack.Peek() << std::endl;
  if(stack.IsEmpty())
    std::cout << "Stack is empty." << std::endl;
  else
    std::cout << "Stack is not empty." << std::endl;
  std::cout << std::endl;

  std::cout << "Popping the stack:" << std::endl;
  while(!stack.IsEmpty())
  {
    std::cout << stack.Peek() << std::endl;
    stack.Pop();
  }

  if(stack.IsEmpty())
    std::cout << "Stack is empty." << std::endl;
  else
    std::cout << "Stack is not empty." << std::endl;

  return 0;
}
