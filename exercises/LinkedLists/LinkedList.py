class Node:
    def __init__(self, value):
        self.val = value
        self.next = None

def printLinkedList(head):
    current = head
    if(current == None): return 
    print(current.val)
    printLinkedList(current.next)

def sumof(head):
    current = head
    if(current == None): return 0
    return (current.val + sumof(current.next))

a = Node(10)
b = Node(12)
c = Node(13)
d = Node(14)

a.next = b
b.next = c
c.next = d

printLinkedList(a)
print(sumof(a))
