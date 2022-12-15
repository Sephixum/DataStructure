# This code has been written on Arch Linux operating system
# using Neovim Text Editor
#------------------------------------------------------------------------
# Stack was studied from "https://www.geeksforgeeks.org/stack-in-cpp-stl/"
# Basic implementation of CPP-like Stack
class Stack:
    def __init__(self) :
        self.elements = []

    def push(self, item):
        self.elements.append(item)

    def pop(self):
        self.elements.pop()

    def size(self):
        return len(self.elements)

    def empty(self):
        return True if self.size() == 0 else False

    def top(self):
        return self.elements[len(self.elements)-1]

# Function to convert infix To postfix
def infixToPostfix(input):
    stack = Stack()
    result = ""

    # Traverse every element in input string
    for char in input:
        scannedChar = char

        # Checking for operands
        if( (ord(char) >= ord('a')) and (ord(char) <= ord('z') ) ):
            result += scannedChar

        #-----Priority of "()" is the highest------
        elif ( scannedChar == '(' ):
            stack.push('(')

        elif ( scannedChar == ')' ):
            while (stack.top() != '(' ):
                result += stack.top()
                stack.pop()
            stack.pop()
        #---------End of actions inside "()"-------

        else:
            while ( (not stack.empty()) and (prio(char) <= prio(stack.top())) ):
                result += stack.top()
                stack.pop()
            stack.push(scannedChar)

    while (not stack.empty()):
        result += stack.top()
        stack.pop()

    # A string being returned
    return result

# Function to check the prio of operators
def prio(character):
    if character == '^': return 3
    elif ( (character == '/')   or   (character == '*') ): return 2
    elif ( (character == '+')   or   (character == '-') ): return 1
    else: return -1
#-------------------------------------------------------------------------------------

# Main code
input = input()
print(infixToPostfix(input))
