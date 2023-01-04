#include "Node.h"
#include <iostream>
// #ifndef _X_H
// #define _X_H

class Linkedlist {

private:
  node *head, *tail;
  int len;

  // void Recursiveprint(node *head) {
  //   node *tmp = head;
  //   if (tmp == NULL) {
  //     std::cout << '\n';
  //     return;
  //   }
  //   std::cout << tmp->data << " ";
  //   Recursiveprint(tmp->next);
  // }

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

  void Remove(int data) {
    node *current_node = this->head;
    node *prev_node = NULL;
    while (current_node) {
      if (current_node->data == data) {
        if (prev_node) {
          prev_node->next = current_node->next;
        } else {
          this->head = current_node->next;
        }
        return;
      }
      prev_node = current_node;
      current_node = current_node->next;
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

  void Printlist() {
    node *current_node = this->head;
    while (current_node) {
      std::cout << current_node->data;
      current_node = current_node->next;
    }
    return;
  }

  void Showhead() { std::cout << this->head->data << '\n'; }

  void Showtail() { std::cout << this->tail->data << '\n'; }
};

// #endif
