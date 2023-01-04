// This code has been written on Arch Linux operating system
// using Neovim Text Editor
//----------------------------------------------------
#include "stack.h"
#include <iostream>
#define SIZE 50

//-----pre called functions-----
int prio(char character);
bool checkOp(char input);
// descriptions explaind on where its defined

// converts to Postfix
std::string inToPost(std::string input) {

  // define our desired stack
  MyStack stack;

  // the result string we will return
  std::string result;

  for (int i = 0; i < input.length(); i++) {
    // define the scanned character
    char scannedChar = input[i];

    // gets a value from checkOp function
    // to see if scannedChar is an operator or not
    if (checkOp(scannedChar) == false)
      result += scannedChar;

    else {
      // condition is  if out stack is not empty and
      // current character priority is bigger than the top character
      while (true) {
        if (!stack.empty() && prio(input[i]) >= prio(stack.top())) {
          // adds top of the stack to the result string
          // and changes the pointer
          result += stack.top();
          stack.pop();
        } else
          break;
      }
      // pushes current scannedChar to stack
      stack.push(scannedChar);
    }
  }

  // and pop all the elements in the order pushed
  // if stack isn't empty
  while (!stack.empty()) {
    result += stack.top();
    stack.pop();
  }

  // result string gets returned
  return result;
}

// basic function to return the priority of operator
int prio(char character) {

  if (character == '^')
    return 1;

  else if (character == '/' || character == '*')
    return 2; // same priority for * and /

  else if (character == '+' || character == '-')
    return 3; // same priority for + nad -

  else
    return 4; // last priority for other characters
}

// basic function to check if our character is an operator or not
bool checkOp(char input) {
  // list of operators
  char operators[] = {'^', '*', '/', '+', '-'};
  // traverses through operators list
  for (int i = 0; i < sizeof(operators); i++) {
    if (operators[i] == input)
      return true;
  }
  // if input wasn't an operator
  return false;
}

//----------------------Driver's code----------------------------------------
int main() {

  // deifne the desired string of infix
  std::string input;

  // input the desired string
  std::cin >> input;

  // send the infix string to our function
  // and get the returned postfix string
  std::cout << inToPost(input);

  return 0;
}
