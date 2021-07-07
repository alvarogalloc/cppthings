export module MyList;
#define RESET "\033[0m"
#define BOLDCYAN "\033[1m\033[36m"
import<iostream>;

export struct Node {
  Node() { this->next = nullptr; }
  int data;
  Node *next;
};
export class List {

public:
  ~List() { delete this->node; }
  List(int _data) {
    this->node = new Node();
    this->node->data = _data;
  }
  void append(int _data) {
    Node *last = this->node;
    while (last->next != nullptr)
      last = last->next;
    last->next = new Node();
    last->next->data = _data;
    last->next->next = nullptr;
  }

  void printList() {
    Node *curr = this->node;
    for (std::size_t i = 0; curr != nullptr; i++) {
      std::cout << BOLDCYAN << "Index: " << RESET << i << BOLDCYAN << " Has Value: " << RESET << curr->data << "\n";
      curr = curr->next;
    }
  }
  void reverse() {
    // Initialize current, previous and
    // next pointers
    Node *current = this->node;
    Node *prev = nullptr, *next = nullptr;

    while (current != nullptr) {
      // Store next
      next = current->next;

      // Reverse current node's pointer
      current->next = prev;

      // Move pointers one position ahead.
      prev = current;
      current = next;
    }
    this->node = prev;
  }

private:
  Node *node;
};
