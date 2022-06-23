#include <iostream>

#include "islgr_util.h"
#include "dnode.h"
// An impl of singly to go with class. find will handle traversal at beginning,
// end and middle. Then the insert/delete algos
// circular single/double, will use this same strctr.
class DoublyLinked {
 private:
  DNode* head;

 public:
  DoublyLinked();
  ~DoublyLinked();
  //   ops.
  int deleteAt(int index);
  int insertAt(int index, DNode* DNode);
  DNode* find(int index);
  // exercise
  void reverse();
  //   necessary utils
  void display();
  bool isEmpty();
  //   blanket impls. use composition to break in after parent impl.
  int deleteBeginning();
  int deleteEnd();
  int insertBeginning();
  int insertEnd();
};

// Constructor. Create an empty DoublyLinked.
DoublyLinked::DoublyLinked() { head = nullptr; }
// Empty
bool DoublyLinked::isEmpty() { return head == nullptr; }
// Display.
void DoublyLinked::display() {
  // Empty.
  if (isEmpty()) {
    std::cout << "List is empty" << std::endl;
    return;
  }
  // Traverse and display
  DNode* tmp = head;
  while (tmp != nullptr) {
    // tags
    if (tmp == head) {
      std::cout << "Head: ";
    }
    // display
    tmp->display();
    std::cout << std::endl;
    tmp = tmp->getNext();
  }
}

// bin
void tests();
int main() { tests(); }

void tests() {
  DoublyLinked* l = new DoublyLinked();
  // Should be empty, and output empty
  bool empy = l->isEmpty();
  EXPECT_T(empy);
  std::cout << "Empty log" << std::endl;
  l->display();
}