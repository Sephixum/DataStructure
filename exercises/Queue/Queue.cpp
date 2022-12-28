#include <iostream>

class Queue {

private:
  int rear;
  int front;
  int size;
  int *arr;
  int currentSize;

public:
  Queue(int size);
  void Enqueue(int item);
  void Dequeue();
  bool Is_full();
  bool Is_empty();
  void Show_queue();
};

Queue::Queue(int size) {
  this->size = size;
  this->arr = new int[size];
  this->front = 1;
  this->rear = 0;
  this->currentSize = 0;
}

void Queue::Enqueue(int item) {
  if (Is_full())
    std::cout << "Overflow\n";

  else {
    rear = (rear + 1) % size;
    arr[rear] = item;
    std::cout << item << " added to queue\n";
    currentSize++;
  }
}

void Queue::Dequeue() {
  if (Is_empty())
    std::cout << "Underflow\n";
  else {
    arr[front] = 0;
    front = (front + 1) % size;
    currentSize--;
  }
}

bool Queue::Is_full() {
  // if (currentSize == size)
  if ((rear + 2) % size == front)
    return 1;
  return 0;
}

bool Queue::Is_empty() {
  // if (currentSize == 0)
  if (rear + 1 == front)
    return 1;
  return 0;
}

void Queue::Show_queue() {
  std::cout << "[";
  for (int i = 0; i < size; i++) {
    std::cout << "," << arr[i];
  }
  std::cout << "]\n";
}

int main() {
  int size;
  std::cin >> size;
  Queue a(size + 1);
  a.Enqueue(1);
  a.Enqueue(2);
  a.Enqueue(3);
  a.Enqueue(4);
  a.Enqueue(5);
  a.Enqueue(6);
  a.Enqueue(7);
  a.Dequeue();
  a.Dequeue();
  a.Dequeue();
  a.Enqueue(8);
  a.Show_queue();
  return 0;
}
