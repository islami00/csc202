#include <iostream>

#include "islgr_util.h"
#include "node.h"
// An impl of singly to go with class. find will handle traversal at beginning,
// end and middle. Then the insert/delete algos
// circular single/double, will use this same strctr.
enum Err { OUTOFBOUNDS = -2, UNDERFLOW };
class SinglyLinked {
 private:
  Node* head;

 public:
  SinglyLinked();
  ~SinglyLinked();
  //   ops.
  int deleteAt(int index);
  int insertAt(int index, int data);
  Node* find(int index);
  // exercise
  void reverse();
  //   necessary utils
  void display();
  bool isEmpty();
  int size();
  Node* getHead();
  Node* getTail();
  //   blanket impls. use composition to break in after parent impl.
  int deleteBeginning();
  int deleteEnd();
  int insertBeginning(int data);
  int insertEnd(int data);
};

// bin
void tests();
int main() {
  tests();
  return 0;
}

// Constructor. Create an empty SinglyLinked.
SinglyLinked::SinglyLinked() { head = nullptr; }
int SinglyLinked::insertAt(int index, int data) {
  Node* newNode = new Node(data);
  if ((index < 0) || (index > size())) {
    return Err::OUTOFBOUNDS;
  }
  // beginning
  if (index == 0) {
    newNode->setNext(head);
    head = newNode;
  }
  // end
  else if (index == size()) {
    Node* t = getTail();
    t->setNext(newNode);
  }
  // or elsewhere
  else {
    Node* current = head;
    Node* prev = current;
    int i = 0;
    while ((i != index) && (current != nullptr)) {
      i += 1;
      prev = current;
      current = current->getNext();
    }
    // i must be reachable. But still..
    // i in range [1,index]
    if (i == index) {
      newNode->setNext(current);
      prev->setNext(newNode);
    }
  }
}
int SinglyLinked::deleteAt(int index) {
  if (isEmpty()) {
    return Err::UNDERFLOW;
  }
  int _size = size();
  if ((index < 0) || (index >= _size)) {
    return Err::OUTOFBOUNDS;
  }
  // beginning
  if (index == 0) {
    Node* temp = head->getNext();
    delete head;
    head = temp;
  }
  // end
  else if (index == _size - 1) {
    Node* prev = find(_size - 2);
    Node* tail = prev->getNext();
    prev->setNext(nullptr);
    delete tail;
  }
  // or elsewhere.
  else {
    Node* current = head;
    Node* prev = current;
    Node* next = current->getNext();
    int i = 0;

    while ((i != index) && (next != nullptr)) {
      i += 1;
      prev = current;
      current = current->getNext();
      next = current->getNext();
    }

    prev->setNext(next);
    delete current;
  }
}
// blanket
int SinglyLinked::deleteEnd() {
  int end = size() - 1;
  return deleteAt(end);
}
int SinglyLinked::insertEnd(int data) {
  int end = size();
  return insertAt(end, data);
}
int SinglyLinked::deleteBeginning() { return deleteAt(0); }
int SinglyLinked::insertBeginning(int data) { return insertAt(0, data); }
// utils
bool SinglyLinked::isEmpty() { return head == nullptr; }
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
    tmp = tmp->getNext();
  }
}
Node* SinglyLinked::getHead() { return head; }
Node* SinglyLinked::getTail() {
  if (isEmpty()) {
    return head;
  }
  Node* temp = head;
  Node* next = temp->getNext();
  // last node will point to null.
  while (next != nullptr) {
    temp = temp->getNext();
    next = temp->getNext();
  }
  return temp;
}
int SinglyLinked::size() {
  Node* temp = head;
  int i = 0;
  while (temp != nullptr) {
    i += 1;
    temp = temp->getNext();
  }
  return i;
}
Node* SinglyLinked::find(int index) {
  if ((index < 0) || (index >= size())) {
    return nullptr;
  }
  if (index == 0) {
    return head;
  } else {
    Node* temp = head;
    Node* found = nullptr;
    int i = 0;
    while ((i != index) && (temp != nullptr)) {
      i += 1;
      temp = temp->getNext();
      if (i == index) {
        found = temp;
      }
    }
    return found;
  }
}

void tests() {
  SinglyLinked* l = new SinglyLinked();
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