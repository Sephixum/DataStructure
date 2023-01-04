#include <iostream>

template <class T> struct node {
  T data;
  node<T> *next;
  node(T data) {
    this->data = data;
    this->next = NULL;
  }
};

template <class T> class Linkedlist {

private:
  node<T> *head, *tail;
  int len;

public:
  Linkedlist() {
    this->head = NULL;
    this->tail = NULL;
    this->len = 0;
  }

  void Append(T n) {
    node<T> *tmp = new node<T>(n);
    // tmp->value = n;
    tmp->next = NULL;

    if (head == NULL) {
      this->head = tmp;
      this->tail = tmp;
    } else {
      tail->next = tmp;
      tail = tail->next;
    }
    ++this->len;
  }

  void Push(int n) {
    node<T> *tmp = new node<T>(n);

    // tmp->value = n;
    tmp->next = this->head;
    this->head = tmp;
    ++this->len;
  }

  void Pop() {
    if (this->head == NULL)
      return;

    node<T> *tmp = this->head;
    node<T> *prev = tmp;
    while (tmp->next != NULL) {
      prev = tmp;
      tmp = tmp->next;
    }
    this->tail = prev;
    prev->next = NULL;
    --this->len;
    if (this->len == 0) {
      this->head = NULL;
      this->tail = NULL;
    }
  }

  void Reverse() {
    node<T> *tmp = this->head;
    node<T> *prev = NULL;
    node<T> *next = NULL;
    while (tmp != NULL) {
      next = tmp->next;
      tmp->next = prev;
      prev = tmp;
      tmp = next;
    }
    this->head = prev;
  }

  void Printlist() {
    node<T> *current = head;
    while (current != NULL) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }

  void Showlen() { std::cout << len << '\n'; }

  void Showhead() { std::cout << this->head->data << '\n'; }

  void Showtail() { std::cout << this->tail->data << '\n'; }
};

int main() {
  Linkedlist<int> a;
  a.Push(12);
  a.Push(13);
  a.Push(14);
  a.Push(15);
  a.Push(16);
  a.Push(17);
  a.Push(18);
  a.Printlist();
  a.Reverse();
  a.Printlist();
  return 0;
}
