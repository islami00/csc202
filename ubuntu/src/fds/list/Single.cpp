#include <iostream>

#include "islgr_util.h"
#include "node.h"
class SinglyLinked {
 private:
  Node* head;

 public:
  SinglyLinked();
  ~SinglyLinked();
  //   necessary utils
  void display();
  bool isEmpty();
};

// Constructor. Create an empty SinglyLinked.
SinglyLinked::SinglyLinked() { head = nullptr; }
// Empty
bool SinglyLinked::isEmpty() { return head == nullptr; }
// Display.
void SinglyLinked::display() {
  // Empty.
  if (isEmpty()) {
    std::cout << "List is empty" << std::endl;
    return;
  }
  // Traverse and display
  Node* tmp = head;
  while (tmp != nullptr) {
    // tags
    if (tmp == head) {
      std::cout << "Head: ";
    }
    // display
    tmp->display();
    std::cout << std::endl;
  }
}
void tests();
int main() { tests(); }

void tests() {
  SinglyLinked* l = new SinglyLinked();
  // Should be empty, and output empty
  bool empy = l->isEmpty();
  EXPECT_T(empy);
  std::cout << "Empty log" << std::endl;
  l->display();
}