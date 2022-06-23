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
  int insertAt(int index, int DNode);
  DNode* find(int index);
  // exercise
  void reverse();
  //   necessary utils
  void display();
  bool isEmpty();
  int size();
  DNode* getHead();
  DNode* getTail();
  //   blanket impls. use composition to break in after parent impl.
  int deleteBeginning();
  int deleteEnd();
  int insertBeginning(int data);
  int insertEnd(int data);
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
int main() {
  tests();
  return 0;
}

void tests() {
  DoublyLinked* l = new DoublyLinked();
  // empty check
  bool empy = l->isEmpty();
  EXPECT_T(empy);
  EXPECT_T(l->size() == 0);
  l->display();
  // insert a few things at head
  for (int i = 0; i < 2; i++) {
    l->insertBeginning(i + 1);
  }
  EXPECT_T(l->getHead()->getData() == 2);
  l->display();
  // insert a few things at end
  for (int i = 0; i < 2; i++) {
    l->insertEnd(i + 1);
  }
  EXPECT_T(l->getTail()->getData() == 2);
  l->display();
  // insert a thing at a specific point
  l->insertAt(2, 12);
  EXPECT_T(l->find(2)->getData() == 12);
  l->display();
  // delete last, beginning
  l->deleteEnd();
  l->deleteBeginning();
  EXPECT_T(l->getTail()->getData() == 1);
  EXPECT_T(l->getHead()->getData() == 1);
  l->display();
  // delete at a specific place
  l->deleteAt(1);
  EXPECT_T(l->find(1)->getData() == 1);
}