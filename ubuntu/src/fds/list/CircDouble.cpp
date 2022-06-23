#include <iostream>

#include "dnode.h"
#include "islgr_util.h"
// An impl of singly to go with class. find will handle traversal at beginning,
// end and middle. Then the insert/delete algos
// circular single/double, will use this same strctr.
class CircDoublyLinked {
 private:
  DNode* head;

 public:
  CircDoublyLinked();
  ~CircDoublyLinked();
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

// Constructor. Create an empty CircDoublyLinked.
CircDoublyLinked::CircDoublyLinked() { head = nullptr; }
// Empty
bool CircDoublyLinked::isEmpty() { return head == nullptr; }
// Display.
void CircDoublyLinked::display() {
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
  CircDoublyLinked* l = new CircDoublyLinked();
  // Should be empty, and output empty
  bool empy = l->isEmpty();
  EXPECT_T(empy);
  std::cout << "Empty log" << std::endl;
  l->display();
}