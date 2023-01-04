# Stack was studied from "https://www.geeksforgeeks.org/stack-in-cpp-stl/" Basic implementation of CPP-like Stack
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
