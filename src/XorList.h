#pragma once
#include <iostream>

using std::out_of_range, std::cout;
#define PtrToInt(p) reinterpret_cast<uintptr_t>((void *)(p))
#define IntToPtr(i) reinterpret_cast<Node<T>*>((i))

template <typename T = int>
struct Node {
  T data;
  Node* link;
  Node(T data, Node* prev, Node* next) : data(data), link(XOR(prev, next)) {}
};

template <typename T = int>
Node<T>* XOR(Node<T>* prev, Node<T>* next) {
  return reinterpret_cast<Node<T>*>(PtrToInt(prev) ^ PtrToInt(next));
}

template <typename T = int>
class XorList {
 private:
  Node<T>* tail;
  Node<T>* head;

 public:
  XorList(T first) {
    head = new Node<T>(first, nullptr, nullptr);
    tail = head;
  }
  ~XorList() {}
  void add(T data) {
    Node<T>* prev = nullptr;
    Node<T>* cur = head;
    Node<T>* next = XOR(head->link, prev);

    while (next != nullptr) {
      prev = cur;
      cur = next;
      next = XOR(prev, cur->link);
    }
    auto newNode = new Node<T>(data, cur, nullptr);
    cur->link = XOR(prev, newNode);
    tail = newNode;
  }

  T at(std::size_t index) {
    Node<T>* prev = nullptr;  // is no previous node yet
    Node<T>* cur = head;
    while (index &&           // exit when we've iterated far enough
           cur != nullptr) {  // or we've run out of nodes
      Node<T>* next = XOR(prev, cur->link);  // find next node
      prev = cur;                            // update book keeping
      cur = next;
      index--;  // one less iteration
    }
    if (index != 0)  // oops.
    {
      throw out_of_range("index out of range");
    }
    return cur->data;
  }
  void print() {
    Node<T>* cur = head;
    Node<T>* prev = nullptr;
    while (cur != nullptr) {
      Node<T>* next = XOR(prev, cur->link);
      cout << cur->data << '\n';
      prev = cur;
      cur = next;
    }
  }
  std::size_t size() {
    Node<T>* cur = head;
    Node<T>* prev = nullptr;
    int count = 0;
    while (cur != nullptr) {
      Node<T>* next = XOR(prev, cur->link);
      prev = cur;
      cur = next;
      count++;
    }
    return count;
  }
  void reverse() {
    auto curr = head;
    auto prev = (Node<T>*)nullptr;
    auto next = (Node<T>*)nullptr;
    while (XOR(prev, curr->link)) {
      next = XOR(prev, curr->link);
      prev = curr;
      curr = next;
    }
    head = curr;
  }
};
