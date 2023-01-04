# This code has been written on Arch Linux operating system
# using Neovim Text Editor
#------------------------------------------------------------------------
from stack import Stack

# Function to convert infix To postfix
def infixToPostfix(exp):
    stack = Stack()
    result = ""

    # Traverse every element in exp string
    for char in exp:
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
def main():
    exp = input()
    print(infixToPostfix(exp))

if __name__ == "__main__":
    main()
