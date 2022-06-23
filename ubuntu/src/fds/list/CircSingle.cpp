#include <iostream>

#include "islgr_util.h"
#include "node.h"
// An impl of singly to go with class. find will handle traversal at beginning,
// end and middle. Then the insert/delete algos
// circular single/double, will use this same strctr.
class CircSingly {
 private:
  Node* head;

 public:
  CircSingly();
  ~CircSingly();
  //   ops.
  int deleteAt(int index);
  int insertAt(int index, Node* node);
  Node* find(int index);
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

// Constructor. Create an empty CircSingly.
CircSingly::CircSingly() { head = nullptr; }
// Empty
bool CircSingly::isEmpty() { return head == nullptr; }
// Display.
void CircSingly::display() {
  // Empty.
  if (isEmpty()) {
    std::cout << "List is empty" << std::endl;
    return;
  }
  // Traverse and display
  Node* tmp = head;
  do {
    // tags
    if (tmp == head) {
      std::cout << "Head: ";
    }
    // display
    tmp->display();
    std::cout << std::endl;
    tmp = tmp->getNext();
  } while (tmp != head);
}

// bin
void tests();
int main() { tests(); }

void tests() {
  CircSingly* l = new CircSingly();
  // Should be empty, and output empty
  bool empy = l->isEmpty();
  EXPECT_T(empy);
  std::cout << "Empty log" << std::endl;
  l->display();
}