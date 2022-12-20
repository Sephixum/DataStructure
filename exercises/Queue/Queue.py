class Queue:
    def __init__(this, maxsize):
        this.queueArray = [None for i in range(maxsize)]
        #-------------------------------
        # or you could say :
        # for i in range(10):
        #   this.queueArray.append(None)
        #-------------------------------
        this.maxsize = maxsize
        this.rear = 0
        this.front = 1


    def Enqueue(this):
        if(this.Is_full()):
            print("queue is full")
            print(this.queueArray)
        else:
            this.rear += 1
            item = input("item to add :")
            this.queueArray[(this.rear%this.maxsize)] = item
            print("element added")
            print(this.queueArray)

    def Dequeue(this):
        if(this.Is_empty()):
            print("queue is empty")
        else:
            this.queueArray[this.front] = None
            this.front += 1
            print("removed from queue")

    def Is_full(this):
        if ( (this.rear+2)%(this.maxsize) == (this.front)%(this.maxsize) ) :  return True
        else:   return False

    def Is_empty(this):
        if(this.front == this.rear+1):  return True
        else:   return False

while(True):
    print("1. Create a queue.")
    print("2. Enqueue(add) an element.")
    print("3. Dequeue(remove) an element.")
    print("4. Show the queue.")
    print("5. Exit.")
    option = int(input("choose your option :"))

    if(option == 1):
        qSize = int(input("size of queue :"))
        queue = Queue(qSize+1)

    elif(option == 4):
        print(queue.queueArray)

    elif(option == 5):
        break

    else:
        actions = {2: queue.Enqueue, 3: queue.Dequeue}
        action = actions.get(option)
        action()
