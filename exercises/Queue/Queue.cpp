#include <iostream>

class Queue {

private:
  int rear;
  int front;

public:
  int *arr;
  int size{0};
  Queue(int size) {
    this->size = size;
    int array[this->size];
    arr = array;
    rear = 0;
    front = 1;
  }
  void Enqueue(int item) {
    if (Is_full())
      std::cout << "queue is full" << std::endl;
    else {
      rear += 1;
      arr[rear % size] = item;
      std::cout << "arr[1] = " << arr[1] << std::endl;
      std::cout << "element added" << std::endl;
    }
  }

  void Dequeue() {
    if (Is_empty())
      std::cout << "queue is empty" << std::endl;
    else {
      std::cout << arr[front] << "removed from queue" << std::endl;
      front += 1;
    }
  }

  bool Is_full() {
    if (((rear + 2) % (size)) == ((front) % (size)))
      return 1;
    else
      return 0;
  }

  bool Is_empty() {
    if (front == rear + 1)
      return 1;
    else
      return 0;
  }
};

int main() {
  Queue a(5);
  a.Enqueue(1);
  a.Enqueue(2);
  a.Dequeue();
  for (int i = 0; i < a.size; i++)
    std::cout << a.arr[i] << std::endl;
  return 0;
}
