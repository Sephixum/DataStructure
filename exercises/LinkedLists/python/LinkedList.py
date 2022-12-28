class node:
    def __init__(this, value):
        this.val = value
        this.next = None

class Linkedlist:
    def __Printlist(this,head):
        tmp = head
        if( tmp == None ): return 
        print(tmp.val)
        this.__Printlist(tmp.next)

    def __init__(this) -> None:
        this.head = None
        this.tail = None
        this.len = 0

    def Append(this,data):
        tmp = node(data)
        tmp.next = None
        if (this.head == None):
            this.head = tmp
            this.tail = tmp
        else:
            this.tail.next = tmp
            this.tail = this.tail.next
        this.len += 1

    def Push(this,data):
        tmp = node(data)

        tmp.next = this.head
        this.head = tmp
        this.len += 1

    def Printlist(this):
        this.__Printlist(this.head)

    def Reverse(this) -> None:
        tmp = this.head
        prev = None
        next = None
        while (tmp != None): 
            next = tmp.next
            tmp.next = prev
            prev = tmp
            tmp = next
        this.head = prev

    def Showhead(this):
        print(this.head.val)

    def Showtail(this):
        print(this.tail.val)
