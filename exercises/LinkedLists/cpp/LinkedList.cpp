#include <iostream>

struct node {
  int data;
  node *next;
  node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class Linkedlist {

private:
  node *head, *tail;
  int len;

  void Recursiveprint(node *head) {
    node *tmp = head;
    if (tmp == NULL) {
      std::cout << '\n';
      return;
    }
    std::cout << tmp->data << " ";
    Recursiveprint(tmp->next);
  }

public:
  Linkedlist() {
    this->head = NULL;
    this->tail = NULL;
    this->len = 0;
  }

  void Append(int n) {
    node *tmp = new node(n);
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
    node *tmp = new node(n);

    // tmp->value = n;
    tmp->next = this->head;
    this->head = tmp;
    ++this->len;
  }

  void Pop() {
    if (this->head == NULL)
      return;

    node *tmp = this->head;
    node *prev = tmp;
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
    node *tmp = this->head;
    node *prev = NULL;
    node *next = NULL;
    while (tmp != NULL) {
      next = tmp->next;
      tmp->next = prev;
      prev = tmp;
      tmp = next;
    }
    this->head = prev;
  }

  void Showlen() { std::cout << len << '\n'; }

  void Printlist() { Recursiveprint(this->head); }

  void Showhead() { std::cout << this->head->data << '\n'; }

  void Showtail() { std::cout << this->tail->data << '\n'; }
};

int main() {
  Linkedlist a;
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
