// this code can be pasted in a .cpp and be used as normal

#include <iostream>
#define SIZE 50

// a stack-like class
// that returns an array object with
// stack behaviors
class MyStack {
  // our array
  char stackArray[SIZE];
  // our pointer
  int topOfStack;

public:
  MyStack() { topOfStack = 0; }
  //------methods----
  void push(char character) {
    if (topOfStack < SIZE) {
      stackArray[++topOfStack] = character;
    } else
      std::cout << "Stack overflow ... ";
  }

  void pop() { topOfStack--; }

  char top() { return stackArray[topOfStack]; }

  char empty() {
    if (topOfStack == 0)
      return true;
    else
      return false;
  }
};
